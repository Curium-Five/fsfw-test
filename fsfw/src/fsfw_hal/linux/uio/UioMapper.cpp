#include "UioMapper.h"

#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#include <filesystem>
#include <fstream>
#include <sstream>

#include "fsfw/serviceinterface.h"

const char UioMapper::UIO_PATH_PREFIX[] = "/sys/class/uio/";
const char UioMapper::MAP_SUBSTR[] = "/maps/map";
const char UioMapper::SIZE_FILE_PATH[] = "/size";

UioMapper::UioMapper(std::string uioFile, int mapNum) : mapNum(mapNum) {
  struct stat buf;
  lstat(uioFile.c_str(), &buf);
  if (S_ISLNK(buf.st_mode)) {
    char* res = realpath(uioFile.c_str(), nullptr);
    if (res) {
      this->uioFile = res;
      free(res);
    } else {
#if FSFW_CPP_OSTREAM_ENABLED == 1
      sif::error << "Could not resolve real path of UIO file " << uioFile << std::endl;
#endif
    }
  } else {
    this->uioFile = std::move(uioFile);
  }
}

UioMapper::~UioMapper() {}

ReturnValue_t UioMapper::getMappedAdress(uint32_t** address, Permissions permissions) {
  ReturnValue_t result = returnvalue::OK;
  int fd = open(uioFile.c_str(), O_RDWR);
  if (fd < 1) {
#if FSFW_CPP_OSTREAM_ENABLED == 1
    sif::error << "UioMapper::getMappedAdress: Invalid UIO device file " << uioFile << std::endl;
#endif
    return returnvalue::FAILED;
  }
  size_t size = 0;
  result = getMapSize(&size);
  if (result != returnvalue::OK) {
    return result;
  }
  *address = static_cast<uint32_t*>(
      mmap(NULL, size, static_cast<int>(permissions), MAP_SHARED, fd, mapNum * getpagesize()));

  if (*address == MAP_FAILED) {
#if FSFW_CPP_OSTREAM_ENABLED == 1
    sif::error << "UioMapper::getMappedAdress: Failed to map physical address of uio device "
               << uioFile.c_str() << " and map" << static_cast<int>(mapNum) << std::endl;
#endif
    return returnvalue::FAILED;
  }
  return returnvalue::OK;
}

ReturnValue_t UioMapper::getMapSize(size_t* size) {
  std::stringstream namestream;
  namestream << UIO_PATH_PREFIX << uioFile.substr(5, std::string::npos) << MAP_SUBSTR << mapNum
             << SIZE_FILE_PATH;
  FILE* fp;
  fp = fopen(namestream.str().c_str(), "r");
  if (fp == nullptr) {
#if FSFW_CPP_OSTREAM_ENABLED == 1
    sif::error << "UioMapper::getMapSize: Failed to open file " << namestream.str() << std::endl;
#endif
    return returnvalue::FAILED;
  }
  char hexstring[SIZE_HEX_STRING] = "";
  int items = fscanf(fp, "%s", hexstring);
  if (items != 1) {
#if FSFW_CPP_OSTREAM_ENABLED == 1
    sif::error << "UioMapper::getMapSize: Failed with error code " << errno
               << " to read size "
                  "string from file "
               << namestream.str() << std::endl;
#endif
    fclose(fp);
    return returnvalue::FAILED;
  }
  uint32_t sizeTmp = 0;
  items = sscanf(hexstring, "%x", &sizeTmp);
  if (size != nullptr) {
    *size = sizeTmp;
  }
  if (items != 1) {
#if FSFW_CPP_OSTREAM_ENABLED == 1
    sif::error << "UioMapper::getMapSize: Failed with error code " << errno << "to convert "
               << "size of map" << mapNum << " to integer" << std::endl;
#endif
    fclose(fp);
    return returnvalue::FAILED;
  }
  fclose(fp);
  return returnvalue::OK;
}

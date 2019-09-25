/**
 * @file HashFile.cpp
 * @author Allan de Miranda Silva (allandemiranda@gmail.com)
 * @brief Métodos para classe HashFile
 * @version 0.1
 * @date 25-09-2019
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "HashFile.hpp"
#include <openssl/hmac.h>
#include <openssl/md5.h>
#include <boost/iostreams/device/mapped_file.hpp>
#include <iomanip>
#include <sstream>

/**
 * @brief Construct a new Hash File:: Hash File object
 *
 * @param file Caminho do arquivo
 */
HashFile::HashFile(std::string file) { setHash(file); }
/**
 * @brief Destroy the Hash File:: Hash File object
 *
 */
HashFile::~HashFile(void) {}

/**
 * @brief Get the Hash object
 *
 * @return std::string
 */
std::string HashFile::getHash(void) { return hash; }

/**
 * @brief Set the Hash object
 *
 * @param path_file Caminho do arquivo
 */
void HashFile::setHash(std::string path_file) {
  unsigned char result[MD5_DIGEST_LENGTH];
  boost::iostreams::mapped_file_source src(path_file);
  MD5((unsigned char*)src.data(), src.size(), result);
  std::ostringstream sout;
  sout << std::hex << std::setfill('0');
  for (auto c : result) sout << std::setw(2) << (int)c;
  hash = sout.str();
}
/**
 * @file HmacFile.cpp
 * @author Allan de Miranda Silva (allandemiranda@gmail.com)
 * @brief Métodos para classe HmacFile
 * @version 0.1
 * @date 25-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "HmacFile.hpp"
#include <openssl/hmac.h>
#include <openssl/md5.h>
#include <boost/iostreams/device/mapped_file.hpp>
#include <iomanip>
#include <sstream>

/**
 * @brief Construct a new Hmac File:: Hmac File object
 *
 * @param file Caminho do arquivo
 * @param key Chave
 */
HmacFile::HmacFile(std::string file, std::string key) { setHmac(file, key); }

/**
 * @brief Destroy the Hmac File:: Hmac File object
 *
 */
HmacFile::~HmacFile(void) {}

/**
 * @brief Get the Hmac object
 *
 * @return std::string Hmac
 */
std::string HmacFile::getHmac(void) { return hmac; }

/**
 * @brief Set the Hmac object
 *
 * @param path_file Caminho do arquivo
 * @param new_key Chave
 */
void HmacFile::setHmac(std::string path_file, std::string new_key) {
  unsigned char result[MD5_DIGEST_LENGTH];
  boost::iostreams::mapped_file_source src(path_file);
  char key[new_key.size() + 1];
  strcpy(key, new_key.c_str());
  HMAC(EVP_md5(), key, strlen(key), (unsigned char*)src.data(), src.size(),
       result, NULL);
  std::ostringstream sout;
  sout << std::hex << std::setfill('0');
  for (auto c : result) sout << std::setw(2) << (int)c;
  hmac = sout.str();
}
/**
 * @file HashFile.hpp
 * @author Allan de Miranda Silva (allandemiranda@gmail.com)
 * @brief Classe que cria a hash para o arquivo solicitado
 * @version 0.1
 * @date 25-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef HASHFILE_HPP_
#define HASHFILE_HPP_

#include <string>  // std::string

class HashFile {
 private:
  std::string hash;
  void setHash(std::string);
  void setHmac(std::string, std::string);

 public:
  std::string getHash(void);
  HashFile(std::string);
  HashFile(std::string, std::string);
  ~HashFile(void);
};

#endif
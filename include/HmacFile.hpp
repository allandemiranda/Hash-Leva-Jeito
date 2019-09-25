/**
 * @file HmacFile.hpp
 * @author Allan de Miranda Silva (allandemiranda@gmail.com)
 * @brief Classe que cria a hash com senha para o arquivo solicitado
 * @version 0.1
 * @date 25-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef HMACFILE_HPP_
#define HMACFILE_HPP_

#include <string>  // std::string

class HmacFile {
 private:
  std::string hmac;
  void setHmac(std::string, std::string);

 public:
  std::string getHmac(void);
  HmacFile(std::string, std::string);
  ~HmacFile(void);
};

#endif
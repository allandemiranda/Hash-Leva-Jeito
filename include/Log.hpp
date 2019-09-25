/**
 * @file Log.hpp
 * @author Allan de Miranda Silva (allandemiranda@gmail.com)
 * @brief Classe para gerenciar o modelo de logs
 * @version 0.1
 * @date 25-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef LOG_HPP_
#define LOG_HPP_

#include <string>  // std::string

class Log {
 private:
  std::string hash_md5;
  std::string file_path;

 public:
  Log(std::string, std::string);
  Log(void);
  std::string getHash(void);
  std::string getFilePath(void);
  void setHash(std::string);
  void setFilePath(std::string);
  ~Log(void);
};

#endif
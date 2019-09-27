/**
 * @file Guarda.hpp
 * @author Allan de Miranda Silva (allandemiranda@gmail.com)
 * @brief Classe de controle
 * @version 0.2
 * @date 25-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef GUARDA_HPP_
#define GUARDA_HPP_

#include <string>  // std::string

class Guarda {
 private:
  std::string outFileData = ".guarda/data.g";
  void setOutFileData(std::string);
  std::string correctionPath(std::string);

 public:
  Guarda(std::string, std::string);
  Guarda(std::string, std::string, std::string);
  Guarda(std::string, std::string, bool, std::string);
  Guarda(std::string, std::string, std::string, bool, std::string);
  ~Guarda(void);
};

#endif
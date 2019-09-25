/**
 * @file OpenLogFile.hpp
 * @author Allan de Miranda Silva (allandemiranda@gmail.com)
 * @brief Classe para abrir arquivos de log de acordo com o padrão solicitado
 * @version 0.1
 * @date 25-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef OPENLOGFILE_HPP_
#define OPENLOGFILE_HPP_

#include <string>  // std::string
#include <vector>  // std::vector
#include "Log.hpp"

class OpenLogFile {
 private:
  std::vector<Log> log_table;
  void getLogs(std::string);

 public:
  std::vector<Log> getLogTable(void);
  OpenLogFile(std::string);
  ~OpenLogFile(void);
};

#endif
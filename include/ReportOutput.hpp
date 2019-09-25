/**
 * @file ReportOutput.hpp
 * @author Allan de Miranda Silva (allandemiranda@gmail.com)
 * @brief Classe para gerenciar saída de arquivo de log
 * @version 0.1
 * @date 25-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef REPORTOUTPUT_HPP_
#define REPORTOUTPUT_HPP_

#include <string>  // std::string
#include <vector>  // std::vector
#include "Log.hpp"

class ReportOutput {
 private:
  void setFileOut(std::vector<Log>, std::string);

 public:
  ReportOutput(std::vector<Log>, std::string);
  ~ReportOutput(void);
};

#endif
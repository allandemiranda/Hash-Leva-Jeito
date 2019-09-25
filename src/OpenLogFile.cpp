/**
 * @file OpenLogFile.cpp
 * @author Allan de Miranda Silva (allandemiranda@gmail.com)
 * @brief Métodos para a classe OpenLogFile
 * @version 0.1
 * @date 25-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "OpenLogFile.hpp"
#include <fstream>   // std::ifstream
#include <iostream>  // std::cerr
#include <string>    // std::string
#include <vector>    // std::vector
#include "Log.hpp"

/**
 * @brief Construct a new Open Log File:: Open Log File object
 *
 * @param path Caminho do arquivo de configuração
 */
OpenLogFile::OpenLogFile(std::string path) { getLogs(path); }

/**
 * @brief Destroy the Open Log File:: Open Log File object
 *
 */
OpenLogFile::~OpenLogFile(void) {}

/**
 * @brief Get the Logs object
 *
 * @param new_path Caminho do arquivo de configuração
 */
void OpenLogFile::getLogs(std::string new_path) {
  try {
    std::ifstream file(new_path);
    std::string line_text;
    long int cont = 1;
    Log temp;
    while (file >> line_text) {
      if (cont % 2 == 0) {
        temp.setFilePath(line_text);
        log_table.push_back(temp);
        ++cont;
      } else {
        temp.setHash(line_text);
        ++cont;
      }
    }
  } catch (const std::ios_base::failure& e) {
    std::cerr << e.what() << '\n';
  }
}

/**
 * @brief Get the Log Table object
 *
 * @return std::vector<log> Dados do arquivo de configuração
 */
std::vector<Log> OpenLogFile::getLogTable(void) { return log_table; }
/**
 * @file ReportOutput.cpp
 * @author Allan de Miranda Silva (allandemiranda@gmail.com)
 * @brief Métodos para a classe ReportOutput
 * @version 0.1
 * @date 25-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "ReportOutput.hpp"
#include <fstream>   // std::ifstream, std::ofstream
#include <iostream>  // std::cerr
#include <string>    // std::string
#include <vector>    // std::vector
#include "Log.hpp"

/**
 * @brief Construct a new Report Output:: Report Output object
 *
 * @param logs Vetor com os logs a ser salvo em um arquivo de texto
 * @param path Caminho do arquivo para salvar
 */
ReportOutput::ReportOutput(std::vector<Log> logs, std::string path) {
  setFileOut(logs, path);
}

/**
 * @brief Destroy the Report Output:: Report Output object
 *
 */
ReportOutput::~ReportOutput(void) {}

/**
 * @brief Set the File Out object
 *
 * @param logs Vetor com os logs a ser salvo em um arquivo de texto
 * @param path Caminho do arquivo para salvar
 */
void ReportOutput::setFileOut(std::vector<Log> logs, std::string path) {
  try {
    std::ofstream newFile;
    std::string fileName = path;
    newFile.open(fileName, std::ios::trunc);
    for (auto i(0u); i < logs.size(); ++i) {
      newFile << logs[i].getHash() << " " << logs[i].getFilePath() << std::endl;
    }
    newFile.close();
  } catch (const std::ios_base::failure& e) {
    std::cerr << e.what() << '\n';
  }
}
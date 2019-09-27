/**
 * @file CheckHashTable.cpp
 * @author Allan de Miranda Silva (allandemiranda@gmail.com)
 * @brief Metodos da classe CheckHashTable
 * @version 0.2
 * @date 25-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "CheckHashTable.hpp"
#include <iomanip>
#include <iostream>  // std::cout, std::endl
#include <string>    // std::string
#include <vector>    // std::vector
#include "HashFile.hpp"
#include "Log.hpp"

/**
 * @brief Construct a new Check Hash Table:: Check Hash Table object
 *
 * @param fileTable Tabela de arquivos da pasta
 * @param logTable Tabela de log existente
 */
CheckHashTable::CheckHashTable(std::vector<std::string> fileTable,
                               std::vector<Log> logTable) {
  for (Log log : logTable) {
    bool flag = true;
    for (auto i(0u); i < fileTable.size(); ++i) {
      if (log.getFilePath() == fileTable[i]) {
        flag = false;
        HashFile tempHF(fileTable[i]);
        std::string tempHash = tempHF.getHash();
        if (log.getHash() == tempHash) {
          // setNewStatus("Arquivo Não Modificado", log.getFilePath());
        } else {
          setNewStatus("Arquivo Modificado", log.getFilePath());
        }
        fileTable.erase(fileTable.begin() + i);
        --i;
        break;
      }
    }
    if (flag) {
      setNewStatus("Arquivo Deletado", log.getFilePath());
    }
  }
  for (std::string path_p : fileTable) {
    setNewStatus("Arquivo Criado", path_p);
  }
}

/**
 * @brief Construct a new Check Hash Table:: Check Hash Table object
 *
 * @param fileTable Tabela de arquivos da pasta
 * @param logTable Tabela de log existente
 * @param key Chave
 */
CheckHashTable::CheckHashTable(std::vector<std::string> fileTable,
                               std::vector<Log> logTable, std::string key) {
  for (Log log : logTable) {
    bool flag = true;
    for (auto i(0u); i < fileTable.size(); ++i) {
      if (log.getFilePath() == fileTable[i]) {
        flag = false;
        HashFile tempHF(fileTable[i], key);
        std::string tempHash = tempHF.getHash();
        if (log.getHash() == tempHash) {
          // setNewStatus("Arquivo Não Modificado", log.getFilePath());
        } else {
          setNewStatus("Arquivo Modificado", log.getFilePath());
        }
        fileTable.erase(fileTable.begin() + i);
        --i;
        break;
      }
    }
    if (flag) {
      setNewStatus("Arquivo Deletado", log.getFilePath());
    }
  }
  for (std::string path_p : fileTable) {
    setNewStatus("Arquivo Criado", path_p);
  }
}

CheckHashTable::~CheckHashTable(void) {}

/**
 * @brief Set the New Status object
 *
 * @param status Status do arquivo
 * @param path Caminho do arquivo
 */
void CheckHashTable::setNewStatus(std::string status, std::string path) {
  Log tempLog(status, path);
  status_logs.push_back(tempLog);
}

/**
 * @brief Get the Status Log Vector object
 *
 * @return std::vector<Log> Vetor com os logs finais
 */
std::vector<Log> CheckHashTable::getStatusLogVector(void) {
  return status_logs;
}

/**
 * @brief Imprimir na tela o vetor status de logs
 *
 */
void CheckHashTable::showStatusLog(void) {
  std::cout << std::endl;
  unsigned int sizePath = 0;
  unsigned int sizeStatus = 0;
  for (Log log : status_logs) {
    unsigned int sizePathTemp = log.getFilePath().size();
    if (sizePathTemp > sizePath) {
      sizePath = sizePathTemp;
    }
    unsigned int sizeStatusTemp = log.getHash().size();
    if (sizeStatusTemp > sizeStatus) {
      sizeStatus = sizeStatusTemp;
    }
  }
  sizePath += 3;
  sizeStatus += 3;
  std::cout << "+";
  std::cout << std::setw(sizePath) << std::setfill('-') << "";
  std::cout << "+";
  std::cout << std::setw(sizeStatus) << "";
  std::cout << "+" << std::endl;
  std::cout << "|";
  std::cout << std::setw(sizePath) << std::setfill(' ') << std::left
            << " CAMINHO";
  std::cout << "|";
  std::cout << std::setw(sizeStatus) << " STATUS";
  std::cout << "|" << std::endl;
  std::cout << "+";
  std::cout << std::setw(sizePath) << std::setfill('-') << "";
  std::cout << "+";
  std::cout << std::setw(sizeStatus) << "";
  std::cout << "+" << std::endl;
  std::cout << std::setfill(' ');
  const std::string red("\033[0;31m");
  const std::string green("\033[1;32m");
  const std::string yellow("\033[1;33m");
  const std::string cyan("\033[0;36m");
  const std::string reset("\033[0m");
  for (Log log : status_logs) {
    if (log.getHash() == "Arquivo Não Modificado") {
      // std::cout << "| ";
      // std::cout << std::setw(sizePath - 1) << log.getFilePath() << "";
      // std::cout << "| ";
      // std::cout << cyan + log.getHash() + reset
      //           << std::setw(sizeStatus - log.getHash().size()) << "";
      // std::cout << "|" << std::endl;
    } else {
      if (log.getHash() == "Arquivo Criado") {
        std::cout << "| ";
        std::cout << std::setw(sizePath - 1) << log.getFilePath() << "";
        std::cout << "| ";
        std::cout << green + log.getHash() + reset
                  << std::setw(sizeStatus - log.getHash().size() - 1) << "";
        std::cout << "|" << std::endl;
      }
      if (log.getHash() == "Arquivo Deletado") {
        std::cout << "| ";
        std::cout << std::setw(sizePath - 1) << log.getFilePath() << "";
        std::cout << "| ";
        std::cout << red + log.getHash() + reset
                  << std::setw(sizeStatus - log.getHash().size() - 1) << "";
        std::cout << "|" << std::endl;
      }
      if (log.getHash() == "Arquivo Modificado") {
        std::cout << "| ";
        std::cout << std::setw(sizePath - 1) << log.getFilePath() << "";
        std::cout << "| ";
        std::cout << yellow + log.getHash() + reset
                  << std::setw(sizeStatus - log.getHash().size() - 1) << "";
        std::cout << "|" << std::endl;
      }
    }
  }
  std::cout << "+";
  std::cout << std::setw(sizePath) << std::setfill('-') << "";
  std::cout << "+";
  std::cout << std::setw(sizeStatus) << "";
  std::cout << "+" << std::endl;
  std::cout << std::endl;
}
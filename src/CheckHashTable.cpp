/**
 * @file CheckHashTable.cpp
 * @author Allan de Miranda Silva (allandemiranda@gmail.com)
 * @brief Metodos da classe CheckHashTable
 * @version 0.1
 * @date 25-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "CheckHashTable.hpp"
#include <string>  // std::string
#include <vector>  // std::vector
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
          setNewStatus("Arquivo Não Modificado", log.getFilePath());
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
          setNewStatus("Arquivo Não Modificado", log.getFilePath());
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
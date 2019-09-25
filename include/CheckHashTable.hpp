/**
 * @file CheckHashTable.hpp
 * @author Allan de Miranda Silva (allandemiranda@gmail.com)
 * @brief Classe para comparar os arquivos com o da tabela de configuraçao
 * @version 0.1
 * @date 25-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef CHECKHASHTABLE_HPP_
#define CHECKHASHTABLE_HPP_

#include <string>  // std::string
#include <vector>  // std::vector
#include "Log.hpp"

class CheckHashTable {
 private:
  std::vector<Log> status_logs;
  void setNewStatus(std::string, std::string);

 public:
  std::vector<Log> getStatusLogVector(void);
  CheckHashTable(std::vector<std::string>, std::vector<Log>);
  CheckHashTable(std::vector<std::string>, std::vector<Log>, std::string);
  ~CheckHashTable(void);
};

/**
 * @brief Construct a new Check Hash Table:: Check Hash Table object
 *
 * @param fileTable Tabela de arquivos da pasta
 * @param logTable Tabela de log existente
 */
CheckHashTable::CheckHashTable(std::vector<std::string> fileTable,
                               std::vector<Log> logTable) {
    for(Log log : logTable){
        for(auto i(0u); i<fileTable.size(); ++i){
            if(log.getFilePath() == fileTable[i]){
                
            }
        }
    }
    

}

CheckHashTable::CheckHashTable(std::vector<std::string> fileTable,
                               std::vector<Log> logTable, std::string key) {}

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

#endif
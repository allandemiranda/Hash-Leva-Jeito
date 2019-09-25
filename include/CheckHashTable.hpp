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

#endif
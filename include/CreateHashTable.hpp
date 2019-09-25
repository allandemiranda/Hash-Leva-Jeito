/**
 * @file CreateHashTable.hpp
 * @author Allan de Miranda Silva (allandemiranda@gmail.com)
 * @brief Classe para a criação do arquivo de configuração
 * @version 0.1
 * @date 25-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef CREATEHASHTABLE_HPP_
#define CREATEHASHTABLE_HPP_

#include <string>  // std::string
#include <vector>  // std::vector
#include "Log.hpp"

class CreateHashTable {
 private:
  std::vector<Log> hash_table;
  void setNewHashInTable(Log);

 public:
  std::vector<Log> getHashTable(void);
  CreateHashTable(std::vector<std::string>);
  CreateHashTable(std::vector<std::string>, std::string);
  ~CreateHashTable(void);
};

#endif
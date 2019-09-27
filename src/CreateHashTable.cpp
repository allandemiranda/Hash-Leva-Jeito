/**
 * @file CreateHashTable.cpp
 * @author Allan de Miranda Silva (allandemiranda@gmail.com)
 * @brief Métodos para classe CreateHashTable
 * @version 0.2
 * @date 25-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "CreateHashTable.hpp"
#include <iomanip>
#include <iostream>  // std::cout, std::endl
#include <string>    // std::string
#include <vector>    // std::vector
#include "HashFile.hpp"
#include "Log.hpp"

/**
 * @brief Create a Hash Table:: Create Hash Table object
 *
 * @param path Vetor de caminho de arquivos
 */
CreateHashTable::CreateHashTable(std::vector<std::string> path) {
  for (std::string path_file : path) {
    HashFile newFile(path_file);
    std::string md5_hash = newFile.getHash();
    Log newLog(md5_hash, path_file);
    setNewHashInTable(newLog);
  }
}

/**
 * @brief Create a Hash Table object
 *
 * @param path Vetor de caminho de arquivos
 * @param key Chave
 */
CreateHashTable::CreateHashTable(std::vector<std::string> path,
                                 std::string key) {
  for (std::string path_file : path) {
    HashFile newFile(path_file, key);
    std::string md5_hash = newFile.getHash();
    Log newLog(md5_hash, path_file);
    setNewHashInTable(newLog);
  }
}

/**
 * @brief Create a Hash Table::~ Create Hash Table object
 *
 */
CreateHashTable::~CreateHashTable(void) {}

/**
 * @brief Set the New Hash In Table object
 *
 * @param new_log Novo log
 */
void CreateHashTable::setNewHashInTable(Log new_log) {
  hash_table.push_back(new_log);
}

/**
 * @brief Get the Hash Table object
 *
 * @return std::vector<Log> Vetor de logs gerado
 */
std::vector<Log> CreateHashTable::getHashTable(void) { return hash_table; }

/**
 * @brief Mostar o log da tabela criada
 *
 */
void CreateHashTable::showLog(void) {
  std::cout << std::endl;
  unsigned int sizePath = 0;
  unsigned int sizeStatus = 0;
  for (Log log : hash_table) {
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
  for (Log log : hash_table) {
    std::cout << "| ";
    std::cout << std::setw(sizePath - 1) << log.getFilePath() << "";
    std::cout << "| ";
    if (log.getHash() == "Arquivo Não Modificado") {
      // std::cout << cyan + log.getHash() + reset
      //           << std::setw(sizeStatus - log.getHash().size()) << "";
    } else {
      if (log.getHash() == "Arquivo Criado") {
        std::cout << green + log.getHash() + reset
                  << std::setw(sizeStatus - log.getHash().size() - 1) << "";
      }
      if (log.getHash() == "Arquivo Deletado") {
        std::cout << red + log.getHash() + reset
                  << std::setw(sizeStatus - log.getHash().size() - 1) << "";
      }
      if (log.getHash() == "Arquivo Modificado") {
        std::cout << yellow + log.getHash() + reset
                  << std::setw(sizeStatus - log.getHash().size() - 1) << "";
      }
    }
    std::cout << "|" << std::endl;
  }
  std::cout << "+";
  std::cout << std::setw(sizePath) << std::setfill('-') << "";
  std::cout << "+";
  std::cout << std::setw(sizeStatus) << "";
  std::cout << "+" << std::endl;
  std::cout << std::endl;
}
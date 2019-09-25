/**
 * @file CreateHashTable.cpp
 * @author Allan de Miranda Silva (allandemiranda@gmail.com)
 * @brief Métodos para classe CreateHashTable
 * @version 0.1
 * @date 25-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "CreateHashTable.hpp"
#include <string>  // std::string
#include <vector>  // std::vector
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
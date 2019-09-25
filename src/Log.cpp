/**
 * @file Log.cpp
 * @author Allan de Miranda Silva (allandemiranda@gmail.com)
 * @brief Métodos da classe Log
 * @version 0.1
 * @date 25-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "Log.hpp"
#include <string>  //  std::string

/**
 * @brief Construct a new Log:: Log object
 *
 * @param new_hash_md5 Hash para guardar
 * @param new_file_path Caminho do arquivo guardar
 */
Log::Log(std::string new_hash_md5, std::string new_file_path) {
  setHash(new_hash_md5);
  setFilePath(new_file_path);
}

/**
 * @brief Construct a new Log:: Log object
 * 
 */
Log::Log(void) {}

/**
 * @brief Destroy the Log:: Log object
 *
 */
Log::~Log(void) {}

/**
 * @brief Get the Hash object
 *
 * @return std::string Hash gurdada
 */
std::string Log::getHash(void) { return hash_md5; }

/**
 * @brief Get the File Path object
 *
 * @return std::string Caminho do arquivo guradado
 */
std::string Log::getFilePath(void) { return file_path; }

/**
 * @brief Set the Hash object
 *
 * @param new_hash Nova hash a guradar
 */
void Log::setHash(std::string new_hash) { hash_md5 = new_hash; }

/**
 * @brief Set the File Path object
 *
 * @param new_path Novo caminho a quardar
 */
void Log::setFilePath(std::string new_path) { file_path = new_path; }

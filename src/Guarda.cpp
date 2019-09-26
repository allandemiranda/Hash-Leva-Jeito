/**
 * @file Guarda.cpp
 * @author Allan de Miranda Silva (allandemiranda@gmail.com)
 * @brief Métodos para classe Guarda
 * @version 0.1
 * @date 25-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "Guarda.hpp"
#include <cstring>
#include <string>  // std::string
#include "CheckHashTable.hpp"
#include "CreateHashTable.hpp"
#include "OpenLogFile.hpp"
#include "ReadingFolderFiles.hpp"
#include "ReportOutput.hpp"

/**
 * @brief Construct a new Guarda:: Guarda object
 *
 * @param opcao -x Exlui arquivo mapa hash
 */
Guarda::Guarda(std::string opcao) {
  if (opcao != "-x") {
    throw "ERRO! Opção para exluir arquivo incompatível";
  }
  std::string deletFile = "rm -r";
  deletFile += outFileData;
  char a[deletFile.size() + 1];
  strcpy(a, deletFile.c_str());
  system(a);
}

/**
 * @brief Construct a new Guarda:: Guarda object
 *
 * metodo -hash Método Hash MD5
 * @param opcao -i Criar arquivo mapa hash
 * @param opcao -t Checa arquivo mapa hash
 * @param pasta Indica a pasta a ser “guardada”
 */
Guarda::Guarda(std::string opcao, std::string pasta) {
  if ((opcao != "-i") and (opcao != "-t")) {
    throw "ERRO! Opção de criação ou checagem Hash incompatível";
  }
  if (opcao == "-i") {
    ReadingFolderFiles pathReading(pasta);
    CreateHashTable table(pathReading.getListPath());
    ReportOutput fileSave(table.getHashTable(), outFileData);
  }
  if (opcao == "-t") {
    ReadingFolderFiles pathReading(pasta);
    OpenLogFile tableLog(outFileData);
    CheckHashTable start(pathReading.getListPath(), tableLog.getLogTable());
    start.showStatusLog();
  }
}

/**
 * @brief Construct a new Guarda:: Guarda object
 *
 * metodo -hmac Método Hmac MD5
 * @param metodoSenha Senha para método Hmac MD5
 * @param opcao -i Criar arquivo mapa hash
 * @param opcao -t Checa arquivo mapa hash
 * @param pasta Indica a pasta a ser “guardada”
 */
Guarda::Guarda(std::string metodoSenha, std::string opcao, std::string pasta) {
  if ((opcao != "-i") and (opcao != "-t")) {
    throw "ERRO! Opção de criação ou checagem Hash incompatível";
  }
  if (opcao == "-i") {
    ReadingFolderFiles pathReading(pasta);
    CreateHashTable table(pathReading.getListPath(), metodoSenha);
    ReportOutput fileSave(table.getHashTable(), outFileData);
  }
  if (opcao == "-t") {
    ReadingFolderFiles pathReading(pasta);
    OpenLogFile tableLog(outFileData);
    CheckHashTable start(pathReading.getListPath(), tableLog.getLogTable(),
                         metodoSenha);
    start.showStatusLog();
  }
}

/**
 * @brief Construct a new Guarda:: Guarda object
 *
 * metodo -hash Método Hash MD5
 * @param opcao -t Checa arquivo mapa hash
 * @param pasta Indica a pasta a ser “guardada”
 * @param saida Indica que deseja salvar relatório
 * @param saidaArquivo Indica onde deseja salvar relatório
 */
Guarda::Guarda(std::string opcao, std::string pasta, std::string saida,
               std::string saidaArquivo) {
  if ((opcao != "-t") or (saida != "-o")) {
    throw "ERRO! Opção de checagem Hash incompatível";
  }
  if (opcao == "-t") {
    ReadingFolderFiles pathReading(pasta);
    OpenLogFile tableLog(outFileData);
    CheckHashTable start(pathReading.getListPath(), tableLog.getLogTable());
    ReportOutput saveF(start.getStatusLogVector(), saidaArquivo);
  }
}

/**
 * @brief Construct a new Guarda:: Guarda object
 *
 * metodo -hmac Método Hmac MD5
 * @param metodoSenha Senha para método Hmac MD5
 * @param opcao -t Checa arquivo mapa hash
 * @param pasta Indica a pasta a ser “guardada”
 * @param saida Indica o arquivo de saída para o relatório
 */
Guarda::Guarda(std::string metodoSenha, std::string opcao, std::string pasta,
               std::string saida, std::string saidaArquivo) {
  if ((opcao != "-t") or (saida != "-o")) {
    throw "ERRO! Opção de checagem Hash incompatível";
  }
  if (opcao == "-t") {
    ReadingFolderFiles pathReading(pasta);
    OpenLogFile tableLog(outFileData);
    CheckHashTable start(pathReading.getListPath(), tableLog.getLogTable(),
                         metodoSenha);
    ReportOutput saveF(start.getStatusLogVector(), saidaArquivo);
  }
}

/**
 * @brief Destroy the Guarda:: Guarda object
 *
 */
Guarda::~Guarda(void) {}
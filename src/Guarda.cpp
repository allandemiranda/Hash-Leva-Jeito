/**
 * @file Guarda.cpp
 * @author Allan de Miranda Silva (allandemiranda@gmail.com)
 * @brief Métodos para classe Guarda
 * @version 0.2
 * @date 25-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "Guarda.hpp"
#include <cstring>
#include <iostream>  // std::cout, std::endl
#include <string>    // std::string
#include "CheckHashTable.hpp"
#include "CreateHashTable.hpp"
#include "OpenLogFile.hpp"
#include "ReadingFolderFiles.hpp"
#include "ReportOutput.hpp"

/**
 * @brief Construct a new Guarda:: Guarda object para método HASH e sem saída em
 * arquivo
 *
 * @param opcao Opção selecionada
 * @param pasta Pasta a ser operada
 */
Guarda::Guarda(std::string opcao, std::string pasta) {
  setOutFileData(correctionPath(pasta));
  if (opcao == "x") {
    std::string deletFile = "rm -r ";    
    deletFile += outFileData;
    char a[deletFile.size() + 1];
    strcpy(a, deletFile.c_str());
    system(a);
    std::cout << "Tabela Hash deletada" << std::endl;
  }
  if (opcao == "i") {
    ReadingFolderFiles pathReading(pasta);
    CreateHashTable table(pathReading.getListPath());
    table.showLog();
    ReportOutput fileSave(table.getHashTable(), outFileData);
  }
  if (opcao == "t") {
    ReadingFolderFiles pathReading(pasta);
    OpenLogFile tableLog(outFileData);
    CheckHashTable start(pathReading.getListPath(), tableLog.getLogTable());
    start.showStatusLog();
    CreateHashTable table(pathReading.getListPath());
    ReportOutput fileSave(table.getHashTable(), outFileData);
  }
}

/**
 * @brief Construct a new Guarda:: Guarda object para método HMAC e sem saída em
 * arquivo
 *
 * @param opcao Opção selecionada
 * @param pasta Pasta a ser operada
 * @param senha Senha Hmac
 */
Guarda::Guarda(std::string opcao, std::string pasta, std::string senha) {
  setOutFileData(correctionPath(pasta));
  if (opcao == "x") {
    std::string deletFile = "rm -r ";    
    deletFile += outFileData;
    char a[deletFile.size() + 1];
    strcpy(a, deletFile.c_str());
    system(a);
    std::cout << "Tabela Hash deletada" << std::endl;
  }
  if (opcao == "i") {
    ReadingFolderFiles pathReading(pasta);
    CreateHashTable table(pathReading.getListPath(), senha);
    table.showLog();
    ReportOutput fileSave(table.getHashTable(), outFileData);
  }
  if (opcao == "t") {
    ReadingFolderFiles pathReading(pasta);
    OpenLogFile tableLog(outFileData);
    CheckHashTable start(pathReading.getListPath(), tableLog.getLogTable(),
                         senha);
    start.showStatusLog();
    CreateHashTable table(pathReading.getListPath(), senha);
    ReportOutput fileSave(table.getHashTable(), outFileData);
  }
}

/**
 * @brief Construct a new Guarda:: Guarda object para método HASH e com saída em
 * arquivo
 * @param opcao Opção selecionada
 * @param pasta Pasta a ser operada
 * @param saida Opção de saída ativada
 * @param destino Destino da saída
 */
Guarda::Guarda(std::string opcao, std::string pasta, bool saida,
               std::string destino) {
  if (!saida) {
    throw "ERRO! Opção incompatível";
  }
  setOutFileData(correctionPath(pasta));
  if (opcao == "x") {
    std::string deletFile = "rm -r ";    
    deletFile += outFileData;
    char a[deletFile.size() + 1];
    strcpy(a, deletFile.c_str());
    system(a);
    std::cout << "Tabela Hash deletada" << std::endl;
  }
  if (opcao == "i") {
    ReadingFolderFiles pathReading(pasta);
    CreateHashTable table(pathReading.getListPath());
    ReportOutput fileSaveDestino(table.getHashTable(), correctionPath(destino));
    ReportOutput fileSave(table.getHashTable(), outFileData);
    std::cout << "Table Hash criada" << std::endl;
  }
  if (opcao == "t") {
    ReadingFolderFiles pathReading(pasta);
    OpenLogFile tableLog(outFileData);
    CheckHashTable start(pathReading.getListPath(), tableLog.getLogTable());
    ReportOutput fileSaveDestino(start.getStatusLogVector(),
                                 correctionPath(destino));
    CreateHashTable table(pathReading.getListPath());
    ReportOutput fileSave(table.getHashTable(), outFileData);
    std::cout << "Table Hash gerada" << std::endl;
  }
}

/**
 * @brief Construct a new Guarda:: Guarda object para método HMAC e com saída em
 * arquivo
 *
 * @param opcao Opção selecionada
 * @param pasta Pasta a ser operada
 * @param senha Senha Hmac
 * @param saida Opção de saída ativada
 * @param destino Destino da saída
 */
Guarda::Guarda(std::string opcao, std::string pasta, std::string senha,
               bool saida, std::string destino) {
  if (!saida) {
    throw "ERRO! Opção incompatível";
  }
  setOutFileData(correctionPath(pasta));
  if (opcao == "x") {
    std::string deletFile = "rm -r ";    
    deletFile += outFileData;
    char a[deletFile.size() + 1];
    strcpy(a, deletFile.c_str());
    system(a);
    std::cout << "Tabela Hash deletada" << std::endl;
  }
  if (opcao == "i") {
    ReadingFolderFiles pathReading(pasta);
    CreateHashTable table(pathReading.getListPath(), senha);
    ReportOutput fileSaveDestino(table.getHashTable(), correctionPath(destino));
    ReportOutput fileSave(table.getHashTable(), outFileData);
    std::cout << "Table Hash criada" << std::endl;
  }
  if (opcao == "t") {
    ReadingFolderFiles pathReading(pasta);
    OpenLogFile tableLog(outFileData);
    CheckHashTable start(pathReading.getListPath(), tableLog.getLogTable(),
                         senha);
    ReportOutput fileSaveDestino(start.getStatusLogVector(),
                                 correctionPath(destino));
    CreateHashTable table(pathReading.getListPath(), senha);
    ReportOutput fileSave(table.getHashTable(), outFileData);
    std::cout << "Table Hash gerada" << std::endl;
  }
}

/**
 * @brief Destroy the Guarda:: Guarda object
 *
 */
Guarda::~Guarda(void) {}

/**
 * @brief Set the Out File Data object
 *
 * @param pathFile Caminho da pasta a ser analisada
 */
void Guarda::setOutFileData(std::string pathFile) {
  if (*(pathFile.end() - 1) == '/') {
    outFileData.insert(0, pathFile);
  } else {
    outFileData.insert(0, "/");
    outFileData.insert(0, pathFile);
  }
}

/**
 * @brief Corrigir o ./ inicial da pasta
 *
 * @param path
 * @return std::string
 */
std::string Guarda::correctionPath(std::string path) {
  if (path.front() == '.') {
    if (*(path.begin() + 1) == '/') {
      path.erase(0, 2);
    }
  }
  return path;
}
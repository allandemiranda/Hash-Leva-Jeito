/**
 * @file main.cpp
 * @author Allan de Miranda Silva (allandemiranda@gmail.com)
 * @brief Main
 * @version 0.1
 * @date 25-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#include <dirent.h>
#include <cstdlib>
#include <iostream>
#include <string>

int listaArquivos(std::string nomeDir) {
  DIR *dir = 0;
  struct dirent *entrada = 0;
  unsigned char isDir = 0x4;
  unsigned char isFile = 0x8;

  dir = opendir(nomeDir.c_str());

  if (dir == 0) {
    std::cerr << "Nao foi possivel abrir diretorio." << std::endl;
    exit(1);
  }

  // Iterar sobre o diretorio
  while (entrada = readdir(dir))
    std::cout << entrada->d_name << std::endl;

  closedir(dir);

  return 0;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cerr << "Diretorio nao fornecido." << std::endl;
    exit(1);
  }

  listaArquivos(argv[1]);

  return 0;
}

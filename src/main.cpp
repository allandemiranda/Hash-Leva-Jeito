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

#include <iostream>  // std::cout, std::endl
#include <string>    // std::string
#include "Guarda.hpp"

/**
 * @brief Função main
 *
 * @param argc Quantidade de argumentos
 * @param argv Argumentos de entrada
 * @return int 0 Finalizado com sucesso
 * @return int 1 Argumento de entrada incorreto
 */
int main(int argc, char const* argv[]) {
  if (argc == 2) {
    std::string opcao = argv[1];
    if (opcao == "-x") {
      try {
        Guarda deletar(opcao);
        std::cout << "Tabela deletada" << std::endl;
      } catch (const char* msg) {
        std::cerr << msg << std::endl;
      }
    } else {
      std::cout << "Argumentos de entrada incorreto" << std::endl;
      return 1;
    }
    return 0;
  }
  if (argc == 4) {
    std::string metodo = argv[1];
    if (metodo == "-hash") {
      std::string opcao = argv[2];
      if ((opcao == "-i") or (opcao == "-t")) {
        std::string pasta = argv[3];
        try {
          Guarda criarChecar(opcao, pasta);
        } catch (const char* msg) {
          std::cerr << msg << std::endl;
        }
        if (opcao == "-i") {
          std::cout << "Arquivo mapa hash criado" << std::endl;
        }
      } else {
        std::cout << "Argumentos de entrada incorreto" << std::endl;
        return 1;
      }
    } else {
      std::cout << "Argumentos de entrada incorreto" << std::endl;
      return 1;
    }
    return 0;
  }
  if (argc == 5) {
    std::string metodo = argv[1];
    if (metodo == "-hmac") {
      std::string opcao = argv[2];
      if ((opcao == "-i") or (opcao == "-t")) {
        std::string senha = argv[3];
        std::string pasta = argv[4];
        try {
          Guarda criarChecar(senha, opcao, pasta);
        } catch (const char* msg) {
          std::cerr << msg << std::endl;
        }
        if (opcao == "-i") {
          std::cout << "Arquivo mapa hmac criado" << std::endl;
        }
      } else {
        std::cout << "Argumentos de entrada incorreto" << std::endl;
        return 1;
      }
    } else {
      std::cout << "Argumentos de entrada incorreto" << std::endl;
      return 1;
    }
    return 0;
  }
  if (argc == 6) {
    std::string metodo = argv[1];
    if (metodo == "-hash") {
      std::string opcao = argv[2];
      if (opcao == "-t") {
        std::string pasta = argv[3];
        std::string saida = argv[4];
        if (saida == "-o") {
          std::string saidaArquivo = argv[5];
          try {
            Guarda criarChecar(opcao, pasta, saida, saidaArquivo);
          } catch (const char* msg) {
            std::cerr << msg << std::endl;
          }
          std::cout << "Arquivo de relatório salvo em " << saidaArquivo
                    << std::endl;
        } else {
          std::cout << "Argumentos de entrada incorreto" << std::endl;
          return 1;
        }
      } else {
        std::cout << "Argumentos de entrada incorreto" << std::endl;
        return 1;
      }
    } else {
      std::cout << "Argumentos de entrada incorreto" << std::endl;
      return 1;
    }
    return 0;
  }
  if (argc == 7) {
    std::string metodo = argv[1];
    if (metodo == "-hmac") {
      std::string opcao = argv[2];
      if (opcao == "-t") {
        std::string senha = argv[3];
        std::string pasta = argv[4];
        std::string saida = argv[5];
        if (saida == "-o") {
          std::string saidaArquivo = argv[6];
          try {
            Guarda criarChecar(senha, opcao, pasta, saida, saidaArquivo);
          } catch (const char* msg) {
            std::cerr << msg << std::endl;
          }
          std::cout << "Arquivo de relatório salvo em " << saidaArquivo
                    << std::endl;
        } else {
          std::cout << "Argumentos de entrada incorreto" << std::endl;
          return 1;
        }
      } else {
        std::cout << "Argumentos de entrada incorreto" << std::endl;
        return 1;
      }
    } else {
      std::cout << "Argumentos de entrada incorreto" << std::endl;
      return 1;
    }
    return 0;
  }
  std::cout << "Argumentos de entrada incorreto" << std::endl;
  return 1;
}

/**
 * @file main.cpp
 * @author Allan de Miranda Silva (allandemiranda@gmail.com)
 * @brief Main
 * @version 0.2
 * @date 25-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#include <getopt.h>  // getopt_long
#include <iostream>  // std::cout, std::endl
#include <string>    // std::string
#include "Guarda.hpp"

/**
 * @brief Função main
 *
 * @param argc Quantidade de argumentos
 * @param argv Argumentos de entrada
 * @return int return
 */
int main(int argc, char* argv[]) {
  const char* const short_opts = "i:t:x:o:";
  const option long_opts[] = {{"hmac", required_argument, nullptr, 'hmac'},
                              {"hash", no_argument, nullptr, 'hash'}};
  int opt;
  bool metodo = false;
  std::string senha = "";
  bool hmac = false;
  bool setOpcao = false;
  std::string opcao;
  std::string pasta;
  std::string pastaSaida;
  bool saida = false;
  while ((opt = getopt_long(argc, argv, short_opts, long_opts, nullptr)) > 0) {
    switch (opt) {
      case 'i':
        if (setOpcao == true) {
          std::cout << "Opção inválida ou faltando argumento" << std::endl;
          return EXIT_FAILURE;
        } else {
          setOpcao = true;
        }
        opcao = "i";
        if (optarg == "") {
          std::cout << "Opção inválida ou faltando argumento" << std::endl;
          return EXIT_FAILURE;
        } else {
          pasta = optarg;
        }
        break;
      case 't':
        if (setOpcao == true) {
          std::cout << "Opção inválida ou faltando argumento" << std::endl;
          return EXIT_FAILURE;
        } else {
          setOpcao = true;
        }
        opcao = "t";
        if (optarg == "") {
          std::cout << "Opção inválida ou faltando argumento" << std::endl;
          return EXIT_FAILURE;
        } else {
          pasta = optarg;
        }
        break;
      case 'x':
        if (setOpcao == true) {
          std::cout << "Opção inválida ou faltando argumento" << std::endl;
          return EXIT_FAILURE;
        } else {
          setOpcao = true;
        }
        opcao = "x";
        if (optarg == "") {
          std::cout << "Opção inválida ou faltando argumento" << std::endl;
          return EXIT_FAILURE;
        } else {
          pasta = optarg;
        }
        break;
      case 'o':
        if (saida == true) {
          std::cout << "Opção inválida ou faltando argumento" << std::endl;
          return EXIT_FAILURE;
        } else {
          saida = true;
        }
        if (optarg == "") {
          std::cout << "Opção inválida ou faltando argumento" << std::endl;
          return EXIT_FAILURE;
        } else {
          pastaSaida = optarg;
        }
        break;
      case 'hmac':
        if (metodo == true) {
          std::cout << "Opção inválida ou faltando argumento" << std::endl;
          return EXIT_FAILURE;
        } else {
          hmac = true;
          metodo = true;
        }
        if (optarg == "") {
          std::cout << "Opção inválida ou faltando argumento" << std::endl;
          return EXIT_FAILURE;
        } else {
          senha = optarg;
        }
        break;
      case 'hash':
        if (metodo == true) {
          std::cout << "Opção inválida ou faltando argumento" << std::endl;
          return EXIT_FAILURE;
        } else {
          hmac = false;
          metodo = true;
        }
        break;
      default:
        std::cout << "Opção inválida ou faltando argumento" << std::endl;
        return EXIT_FAILURE;
    }
  }
  if (metodo) {
    std::cout << "Opção inválida ou faltando argumento" << std::endl;
    return EXIT_FAILURE;
  }
  if (setOpcao) {
    std::cout << "Opção inválida ou faltando argumento" << std::endl;
    return EXIT_FAILURE;
  }
  if ((hmac == false) and (saida == false)) {
    try {
      Guarda(opcao, pasta);
    } catch (const char* msg) {
      std::cerr << msg << std::endl;
      return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
  }
  if ((hmac == true) and (saida == false)) {
    try {
      Guarda(opcao, pasta, senha);
    } catch (const char* msg) {
      std::cerr << msg << std::endl;
      return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
  }
  if ((hmac == false) and (saida == true)) {
    try {
      Guarda(opcao, pasta, saida, pastaSaida);
    } catch (const char* msg) {
      std::cerr << msg << std::endl;
      return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
  }
  if ((hmac == true) and (saida == false)) {
    try {
      Guarda(opcao, pasta, senha, saida, pastaSaida);
    } catch (const char* msg) {
      std::cerr << msg << std::endl;
      return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
  }
  return EXIT_FAILURE;
}
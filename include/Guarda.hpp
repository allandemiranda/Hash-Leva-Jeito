/**
 * @file Guarda.hpp
 * @author Allan de Miranda Silva (allandemiranda@gmail.com)
 * @brief Classe de controle
 * @version 0.1
 * @date 25-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef GUARDA_HPP_
#define GUARDA_HPP_

#include <string>

class Guarda {
 private:
  /* data */
 public:
  Guarda(std::string, std::string);

  ~Guarda(void);
};

Guarda::Guarda(std::string metodo, std::string opcao) {}

Guarda::Guarda(std::string metodo, std::string metodoSenha, std::string opcao) {}

Guarda::Guarda(std::string metodo, std::string opcao, std::string pasta) {}

Guarda::Guarda(std::string metodo, std::string metodoSenha, std::string opcao, std::string pasta) {}

Guarda::Guarda(std::string metodo, std::string opcao, std::string pasta, std::string saida) {}

Guarda::Guarda(std::string metodo, std::string metodoSenha, std::string opcao, std::string pasta, std::string saida) {}

/**
 * @brief Construct a new Guarda:: Guarda object
 *
 * @param metodo -hash Método Hash MD5
 * @param metodo -hmac Método Hmac MD5
 * @param metodoSenha Senha para método Hmac MD5
 * @param opcao -i Criar arquivo mapa hash
 * @param opcao -t Checa arquivo mapa hash
 * @param opcao -x Exlui arquivo mapa hash
 * @param pasta Indica a pasta a ser “guardada”
 * @param saida Indica o arquivo de saída para o relatório
 */
Guarda::Guarda(std::string metodo, std::string opcao, std::string pasta,
               std::string saida) {}

Guarda::~Guarda(void) {}

#endif
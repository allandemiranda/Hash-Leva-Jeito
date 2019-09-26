# Atividade Prática – Operação “Leva Jeito”

Desenvolvido  por   [Allan de Miranda](https://github.com/allandemiranda)   

25 de setembro de 2019 - Segurança de Redes - IMD

## Introdução

Por conta de seus conhecimentos em segurança computacional, você foi convocado a
colaborar com as investigações da operação “Leva Jeito” na qualidade de concultor
técnico.

Sua contribuição inicial será o desenvolvimento de um software que permita garantir a
integridade de documentos extraídos de computadores, preservando assim a cadeia de
custódia destes elementos de prova.

O problema relatado é que documentos extraídos ou coletados em computadores de
suspeitos podem potencialmente serem alterados entre a sua coleta e o seu
processamento investigativo.

Assim, a equipe da “Leva Jeito” requisitou a você o desenvolvimento de um software que
permita verificar a integridade dos dados a qualquer momento.

## Implementação

Implemente o programa guarda que, usando de calculo de puro Hash ou HMAC, 
permita garantir a autenticação de um conjunto de arquivos para uma determinada pasta
(recursivamente). O programa deverá ser executado em linha de comando, seguindo a
sintaxe:

./guarda <metodo> <opcao> <pasta> <saída>

― <metodo> : indica o método a ser utilizado ( -hash ou -hmac senha)
― <opcao>: indica a ação a ser desempenhada pelo programa
• -i : inicia a guarda da pasta indicada em <pasta>, ou seja, faz a leitura de todos os arquivos da pasta (recursivamente) registrando os dados e Hash/HMAC de cada um e armazenando numa estrutura própria (Ex: tabela hash em uma subpasta oculta ./guarda – ou pode ser usada uma árvore B)
• -t : faz o rastreio (tracking) da pasta indicada em <pasta>, inserindo informações sobre novos arquivos e indicando alterações detectadas/exclusões
• -x : desativa a guarda e remove a estrutura alocada
― <pasta> : indica a pasta a ser “guardada”
― <saida> : indica o arquivo de saída para o relatório (-o saída). Caso não seja passado este parâmetro, a saída deve ser feita em tela.

## Requisitos

Para a instalação do programa é necessário que seu computador tenha os seguintes pacotes:

`g++ openssl libssl-dev libboost-all-dev` 

Para instalar estes pacotes abra o terminal e digite:

`sudo apt-get install g++ openssl libssl-dev libboost-all-dev` 

## Instalação

Para instalar e executar o programa siga as instruções:

1. Abra o terminal do seu sistema operacional e digite `cd` 
2. `git clone https://github.com/allandemiranda/Hash-Leva-Jeito.git` 
3. `cd Hash-Leva-Jeito/` 
4. `make` 

## Como utilizar programa Guarda

1. Abra o terminal do seu sistema operacional e digite `cd` 
2. `cd criptografia-simetrica/` 
3. `./bin/guarda <metodo> <opcao> <pasta> <saída>` 
4. A utilização destes argumentos de entrada estão descritos no item de implementação.
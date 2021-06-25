# Tutorial de configuração do pacote

Será necessário modificar os arquivos

- description/problem.info
  ... basename=letra_do_problema
  ... fullname=Nome do Problema
- input
  ... Entradas de teste. Deverá ser numerado de 1 a N
- output
  ... Saídas de teste. Deverá ser numerado de 1 a N
- generator
  ... Código gerador de entradas e saídas (se houver)
- solver
  ... Código que resolve o problema. Pelo menos em C++ e Python3

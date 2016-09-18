#include <iostream>
#include "arvore.h"

int main() {
 Arvore arvore(5, "Rais principal");
 int buscar = 2;
 std::string retorno;

 arvore.inserir(1, "Numero 1");
 arvore.inserir(2, "Numero 2");
 arvore.inserir(3, "Numero 3");
 arvore.inserir(4, "Numero 4");
 arvore.inserir(7, "Numero 7");
 arvore.inserir(6, "Numero 6");

 retorno = arvore.get(buscar);
  if(buscar == -1) std::cout << "Erro, não foi encontrada a chave\n";
  else std::cout << "Chave: " << buscar << ". conteudo:  " << retorno << "\n";
  buscar = 3;
   retorno = arvore.get(buscar);
  if(buscar == -1) std::cout << "Erro, não foi encontrada a chave\n";
  else std::cout << "Chave: " << buscar << ". conteudo:  " << retorno << "\n";
  buscar = 6;
   retorno = arvore.get(buscar);
  if(buscar == -1) std::cout << "Erro, não foi encontrada a chave\n";
  else std::cout << "Chave: " << buscar << ". conteudo:  " << retorno << "\n";
    buscar = 7;
   retorno = arvore.get(buscar);
  if(buscar == -1) std::cout << "Erro, não foi encontrada a chave\n";
  else std::cout << "Chave: " << buscar << ". conteudo:  " << retorno << "\n";
    buscar = 5;
   retorno = arvore.get(buscar);
  if(buscar == -1) std::cout << "Erro, não foi encontrada a chave\n";
  else std::cout << "Chave: " << buscar << ". conteudo:  " << retorno << "\n";

 std:: cout << ">>>>>>>> Fim do programa\n";
 return 0;
}

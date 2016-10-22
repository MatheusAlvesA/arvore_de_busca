#include <iostream>
#include "arvore.h"

void mostrar(Arvore *arvore, int inicio, int fim);

int main() {
 Arvore arvore(5, "Rais principal");
 std::string retorno;

 arvore.inserir(1, "Numero 1");
 arvore.inserir(2, "Numero 2");
 arvore.inserir(3, "Numero 3");
 arvore.inserir(4, "Numero 4");
 arvore.inserir(7, "Numero 7");
 arvore.inserir(6, "Numero 6");
 arvore.inserir(8, "Numero 8");
 arvore.inserir(9, "Numero 9");

 mostrar(&arvore, 1, 9);

 std::cout << "__________________________________________\n";
 if(arvore.remover(5)) std::cout << "sucesso na remoção\n";
else std::cout << "falha na remoção\n";
if(arvore.remover(6)) std::cout << "sucesso na remoção\n";
else std::cout << "falha na remoção\n";
 std::cout << "__________________________________________\n";

 mostrar(&arvore, 1, 9);

 std:: cout << "\n>>>>>>>> Fim do programa\n";
 return 0;
}

void mostrar(Arvore *arvore, int inicio, int fim) {
  std::string retorno = "";

  for(int buscando = inicio; inicio <= fim; inicio++) {
    buscando = inicio;
    retorno = arvore->get(buscando);
    if(buscando == -1) std::cout << "Erro, não foi encontrada a chave " << inicio <<"\n";
    else std::cout << "Chave: " << inicio << ". conteudo:  " << retorno << "\n";
  }
}
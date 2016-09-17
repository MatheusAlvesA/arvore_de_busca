#ifndef _ARVORE_
#define _ARVORE_

#include <string>

class Arvore {
  private:
    Arvore *r;
    Arvore *l;
    int chave;
    std::string dados;
  public:
    Arvore(int c, std::string d); // inicializa a arvore
    bool inserir(int c, std::string); // insere um novo dado associado a uma chave na arvore
    std::string get(int &c); // retorna a partir da chave um determinado dado
};

#endif
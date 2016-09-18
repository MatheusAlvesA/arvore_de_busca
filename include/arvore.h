#ifndef _ARVORE_
#define _ARVORE_

#include <string>
#include <iostream>

class Arvore {
  private:
    Arvore *r;
    Arvore *l;
    int chave;
    std::string dados;
    void destruir(Arvore *arvore); // destroi a avore liberando a memória
  public:
    Arvore(int c, std::string d); // inicializa a arvore
    ~Arvore(); // inicializa a arvore
    bool inserir(int c, std::string); // insere um novo dado associado a uma chave na arvore
    std::string get(int &c); // retorna a partir da chave um determinado dado
    void remover(int &c); // remove um galho da arvore, reorganizando os outros
};

#endif
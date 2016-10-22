#ifndef _ARVORE_
#define _ARVORE_

#include <string>
#include <iostream>

class Arvore {
  private:
    Arvore *r; // ponteiro para a arvore a direita
    Arvore *l; // ponteiro para a arvore a esquerda
    bool root; // variável que guarda se aquele pnteiro é raiz ou não
    int chave; // a chave do valor guardado
    std::string dados; // o valor a ser gardado
    void destruir(Arvore *arvore); // destroi a avore liberando a memória
    void operator=(Arvore *b); // sobrecarga do operador = para copiar arvores facilmente
    
  public:
    Arvore(int c, std::string d); // inicializa a arvore
    Arvore(int c, std::string d, bool isroot); // inicializa a arvore, mas "avisa" que ela não é a raiz principal
    ~Arvore(); // inicializa a arvore
    bool inserir(int c, std::string); // insere um novo dado associado a uma chave na arvore e retorna se houve algum problema
    std::string get(int &c); // retorna a partir da chave um determinado dado ou retorna -1 no 'c' caso não ache
    bool remover(int c); // remove um galho da arvore, reorganizando os outros e retorna false caso não tenha achado o elemento
    void remover_auxiliar(int c, Arvore *&ptr_P, Arvore *&ptr_F); // função recursiva que encontra o nó e seu antecessor
};

#endif
#ifndef _ARVORE_
#define _ARVORE_

#include <string>
#include <iostream>
#include <sstream>

class Arvore {
  private:
    Arvore *r; // ponteiro para a arvore a direita
    Arvore *l; // ponteiro para a arvore a esquerda
    bool root; // variável que guarda se aquele pnteiro é raiz ou não
    int chave; // a chave do valor guardado
    int abaixo; //guarda quantos elementos existem abaixo dessa arvore

    void destruir(Arvore *arvore); // destroi a avore liberando a memória
    void operator=(Arvore *b); // sobrecarga do operador = para copiar arvores facilmente
    int _enesimoElemento(int &n); // função auxiliar a função de enesimo elemento
    //bool _posicao(int x, int &n); // função auxiliar a função posição
    
  public:
    Arvore(int c); // inicializa a arvore
    Arvore(int c, bool isroot); // inicializa a arvore, mas "avisa" que ela não é a raiz principal
    ~Arvore(); // inicializa a arvore
    bool inserir(int c); // insere um novo dado associado a uma chave na arvore e retorna se houve algum problema
    int get(int c); // retorna a partir da chave um determinado dado ou retorna -1 no 'c' caso não ache
    bool remover(int c); // remove um galho da arvore, reorganizando os outros e retorna false caso não tenha achado o elemento
    void remover_auxiliar(int c, Arvore *&ptr_P, Arvore *&ptr_F); // função recursiva que encontra o nó e seu antecessor
    // funções adicionais
   // std::string toString (); // retorna uma String que contém a sequência de visitação (percorrimento) da ABB por nível.
    int getAbaixo() {return this->abaixo;} // retorna quantos elementos exitem a direita e esquerda dessa arvore
    bool ehCheia(); // retorna verdadeiro se a ABB for uma árvore binária cheia e falso, caso contrário.
    bool ehCompleta(); // retorna verdadeiro se a ABB for uma árvore binária completa e falso, caso contrário.
    int enesimoElemento (int &n); //retorna o n-ésimo elemento (contando a partir de 1) do percurso em ordem (ordem simétrica) da ABB.
    //int posicao(int x); // retorna a posição ocupada pelo elemento x em um percurso em ordem simétrica na ABB (contando a partir de 1).
};

#endif
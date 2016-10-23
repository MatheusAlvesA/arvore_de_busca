#include <iostream>
#include <fstream>
#include <string.h>
#include "arvore.h"

struct comandos {
  int comando;
  int valor;
};

void mostrar(Arvore *arvore, int inicio, int fim);
Arvore *lerArvore(std::string entrada);
comandos *lerComandos(std::string entrada, int &numero);

int main(int argc, char const *argv[]) {
 std:: cout << "\n>>>>>>>> Inicio do programa\n\n";

  if(argc < 3) {
    std::cout << "ERRO! Passe por parametro os dois arquivos de entrada\n";
    return -1;
  }
  std::string entrada = argv[1];
  Arvore * arvore = lerArvore(entrada);
  entrada = argv[2];
  int n = 0;
  comandos *comando = lerComandos(entrada, n);

  int bk = 0;
  for(int i = 0; i < n; i++) {
    switch(comando[i].comando) {
      case 0:
        std::cout << "O valor da mediana dessa arvore é: " << arvore->mediana() << "\n";
      break;
      case 1:
        if(arvore->ehCheia()) std::cout << "Essa arvore é cheia\n";
        else std::cout << "Essa arvore NÃO é cheia\n";
      break;
      case 2:
        if(arvore->ehCompleta()) std::cout << "Essa arvore é completa\n";
        else std::cout << "Essa arvore NÃO é completa\n";
      break;
      case 3:
        std::cout << "\n" << arvore->toString() << "\n";
      break;
      case 4:
       bk = comando[i].valor;
        std::cout << "O elemento " << bk << " dessa arvore é: " << arvore->enesimoElemento(comando[i].valor) << "\n";
      break;
      case 5:
      bk = comando[i].valor;
        std::cout << "A posição do elemento " << bk << " dessa arvore é: " << arvore->posicao(comando[i].valor) << "\n";
      break;
      case 6:
        std::cout << "Removendo o elemento " << comando[i].valor << "\n";
        arvore->remover(comando[i].valor);
      break;
      default:
        std::cout << "Comando inválido " << comando[i].comando << "\n";
  }
}

 delete[] comando;
 delete arvore;
 std:: cout << "\n>>>>>>>> Fim do programa\n";
 return 0;
}

void mostrar(Arvore *arvore, int inicio, int fim) {
  for(int buscando = inicio; inicio <= fim; inicio++) {
    buscando = inicio;
    buscando = arvore->get(buscando);
    if(buscando == -1) std::cout << "Erro, não foi encontrada a chave " << inicio <<"\n";
    else std::cout << "Chave: " << inicio << " OK, tem " << arvore->getAbaixo() << " de elementos abaixo" << "\n";
  }
}

Arvore *lerArvore(std::string entrada) {
  std::string linha;
  std::ifstream arquivo(entrada); // ifstream = padrão ios:in

  if(arquivo.is_open())  {
    getline(arquivo,linha);
    arquivo.close();
  }
  else {
    std::cout << "ERRO! Não foi possível ler o arquivo de inserções: " << entrada << "\n";
    exit(0);
  }

  unsigned int i = 0;
  int lendo = 0;
    while(linha[i] != ' ') {
      lendo += (int)(linha[i] - '0');
      lendo *= 10; // abrindo espaço para o próximo digito
      i++;
    }
    lendo /= 10;
    i++;
    Arvore *arvore = new Arvore(lendo);

  while(i < linha.length()) {
    lendo = 0;
    while((int)(linha[i] - '0') >= 0 && (int)(linha[i] - '0') <= 9) {
      lendo += (int)(linha[i] - '0');
      lendo *= 10; // abrindo espaço para o próximo digito
      i++;
    }
    lendo /= 10;
    i++;
    arvore->inserir(lendo);
  }

  return arvore;
}

comandos *lerComandos(std::string entrada, int &numero) {
  std::string linha;
  std::ostringstream stream;
  int lendo = 0;
  comandos *retorno = new comandos[100]; // limite máximo de 100 comandos
  std::ifstream arquivo(entrada); // ifstream = padrão ios:in

  if(!arquivo.is_open())  {
    std::cout << "ERRO! Não foi possível ler o arquivo de inserções: " << entrada << "\n";
    exit(0);
  }

  int i = 0;
  int x = 0;
  while(!arquivo.eof()) {
    stream.str(""); // esvaziando
    getline(arquivo, linha);

    for(i = 0; (int)(linha[i] - 'A') >= 0 && (int)(linha[i] - 'Z') <= 25; i++) {
      stream << linha[i];
    }
    i++;

    if(strcmp(stream.str().c_str(), "MEDIANA") == 0) retorno[x].comando = 0;
    if(strcmp(stream.str().c_str(), "CHEIA") == 0) retorno[x].comando = 1;
    if(strcmp(stream.str().c_str(), "COMPLETA") == 0) retorno[x].comando = 2;
    if(strcmp(stream.str().c_str(), "IMPRIMA") == 0) retorno[x].comando = 3;

    if(strcmp(stream.str().c_str(), "ENESIMO") == 0) {
      retorno[x].comando = 4;

     while((int)(linha[i] - '0') >= 0 && (int)(linha[i] - '0') <= 9) {
        lendo += (int)(linha[i] - '0');
        lendo *= 10; // abrindo espaço para o próximo digito
        i++;
     }
      lendo /= 10;

      retorno[x].valor = lendo;
      lendo = 0;
    }

    if(strcmp(stream.str().c_str(), "POSICAO") == 0) {
      retorno[x].comando = 5;

     while((int)(linha[i] - '0') >= 0 && (int)(linha[i] - '0') <= 9) {
        lendo += (int)(linha[i] - '0');
        lendo *= 10; // abrindo espaço para o próximo digito
        i++;
     }
      lendo /= 10;

      retorno[x].valor = lendo;
      lendo = 0;
    }

    if(strcmp(stream.str().c_str(), "REMOVA") == 0) {
      retorno[x].comando = 6;

     while((int)(linha[i] - '0') >= 0 && (int)(linha[i] - '0') <= 9) {
        lendo += (int)(linha[i] - '0');
        lendo *= 10; // abrindo espaço para o próximo digito
        i++;
     }
      lendo /= 10;

      retorno[x].valor = lendo;
      lendo = 0;
    }

    x++;
  }

  numero = x;
  arquivo.close();
  return retorno;
}
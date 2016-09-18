#include "arvore.h"

Arvore::Arvore(int c, std::string d) {
	this->chave = c; // configura a chave inicial
	this->dados = d; // configura o primeiro dado para armazenar
	this->r = this->l = nullptr;
}
Arvore::~Arvore() {
 if(this->l != nullptr) this->destruir(this->l);
 if(this->r != nullptr) this->destruir(this->r);
}
void Arvore::destruir(Arvore *arvore) {
  if(arvore->l == nullptr && arvore->r == nullptr) delete arvore; // caso base
  else {
     if(arvore->l != nullptr) { // esquerda não pode ser deletada por que não ta vazia
       this->destruir(arvore->l); // recursivamente deleta a esquerda
       arvore->l = nullptr;
     }
     if(arvore->r != nullptr) { // repete o processo par a direita da arvore
       this->destruir(arvore->r);
       arvore->r = nullptr;
     }
     delete arvore; // nesse ponto os dois lados da arvore já foram esvaziados
  }
}

bool Arvore::inserir(int c, std::string d) {
	if(c == this->chave) return false; // não é nescesário inserir, pois já existe
	if(c > this->chave) { // caso essa chave seja maior que a atual então va para a direita na arvore
		if(this->r != nullptr) return this->r->inserir(c, d); // caso o lado direito esteja ocupado repita recursivamente
		else { // se não estiver ocupado encontramos onde colocar
			this->r = new Arvore(c, d); // colocando o novo dado
			return true; // retornando com sucesso
		}
	}
	else {
		if(this->l != nullptr) return this->l->inserir(c, d); // caso o lado esquerdo esteja ocupado repita recursivamente
		else { // se não estiver ocupado encontramos onde colocar
			this->l = new Arvore(c, d); // colocando o novo dado
			return true; // retornando com sucesso
		}
	}
}

std::string Arvore::get(int &c) {
	if(c == this->chave) return this->dados; // Caso base, encontrou o dado
	if(c > this->chave) { // caso essa chave seja maior que a atual então va para a direita na arvore
		if(this->r != nullptr) return this->r->get(c); // caso o lado direito esteja ocupado repita recursivamente
		else { // se não possuir mais caminho então não pode mais continuar}
            c = -1;
		    return NULL; // se não estiver ocupado então chegou al dead end
		}  
	}
	else {
		if(this->l != nullptr) return this->l->get(c); // caso o lado esquerdo esteja ocupado repita recursivamente
		else {
            c = -1;
		   return NULL; // se não estiver ocupado então chegou al dead end
		} 
	}
}

void Arvore::remover(int &c) {
	if(c == this->chave) {
		
	}
	if(c > this->chave) { // caso essa chave seja maior que a atual então va para a direita na arvore
		if(this->r != nullptr) this->r->get(c); // caso o lado direito esteja ocupado repita recursivamente
		else c = -1;  
	}
	else {
		if(this->l != nullptr) this->l->get(c); // caso o lado esquerdo esteja ocupado repita recursivamente
		else c = -1; 
	}
}
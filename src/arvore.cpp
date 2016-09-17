#include "arvore.h"

Arvore::Arvore(int c, std::string d) {
	this->chave = c; // configura a chave inicial
	this->dados = d; // configura o primeiro dado para armazenar
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
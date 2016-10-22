#include "arvore.h"

Arvore::Arvore(int c, std::string d) {
	this->chave = c; // configura a chave inicial
	this->dados = d; // configura o primeiro dado para armazenar
	this->r = this->l = nullptr;
	this->root = true;
}

Arvore::Arvore(int c, std::string d, bool isroot) {
	this->chave = c; // configura a chave inicial
	this->dados = d; // configura o primeiro dado para armazenar
	this->r = this->l = nullptr;
	this->root = isroot;
}

Arvore::~Arvore() {
	if(!this->root) return; // não deve percorrer as outras arvores caso seja uma raiz
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

// essa função copia totalmente os elementos de uma arvore para outra
void Arvore::operator=(Arvore *b) {
	this->chave = b->chave;
	this->dados = b->dados;
	this->l = b->l;
	this->r = b->r;
	this->root = b->root;
}

bool Arvore::inserir(int c, std::string d) {
	if(c == this->chave) return false; // não é nescesário inserir, pois já existe
	if(c > this->chave) { // caso essa chave seja maior que a atual então va para a direita na arvore
		if(this->r != nullptr) return this->r->inserir(c, d); // caso o lado direito esteja ocupado repita recursivamente
		else { // se não estiver ocupado encontramos onde colocar
			this->r = new Arvore(c, d, false); // colocando o novo dado, note que essa arvore não é a raiz
			return true; // retornando com sucesso
		}
	}
	else {
		if(this->l != nullptr) return this->l->inserir(c, d); // caso o lado esquerdo esteja ocupado repita recursivamente
		else { // se não estiver ocupado encontramos onde colocar
			this->l = new Arvore(c, d, false); // colocando o novo dado, note que essa arvore não é a raiz
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
		    return ""; // se não estiver ocupado então chegou no dead end
		}  
	}
	else {
		if(this->l != nullptr) return this->l->get(c); // caso o lado esquerdo esteja ocupado repita recursivamente
		else {
            c = -1;
		   return ""; // se não estiver ocupado então chegou no dead end
		} 
	}
}

bool Arvore::remover(int c) {
	Arvore *ptr_P = nullptr; // ponteiro para o pai
	Arvore *ptr_F = nullptr; // ponteiro para o filho a ser removido

	this->remover_auxiliar(c, ptr_P, ptr_F); // encontrando os ponteiros alvos

	if(ptr_P == nullptr && ptr_F == nullptr) return false; // nesse caso a função auxiliar não encontrou

	if(ptr_P == nullptr) { // esse é p caso onde queremos apagar a raiz da arvore
		if(ptr_F->l == nullptr &&  ptr_F->r == nullptr) return false; // nesse caso não pode deletar pois a arvore ficaria vazia

		//nesse caso apenas o ponteiro a direira possui subarvore
		else if(ptr_F->l == nullptr && ptr_F->r != nullptr) {
			*this = ptr_F->r; // copiamos todos os dados do ponteiro a direita para a raiz
			this->root = true; // avisamos que o ponteiro da direita é a nova raiz
			ptr_F->root = false; // avisamos que a antiga raiz não é mais uma raiz
			delete ptr_F; // deletamos a raiz
		}
		else if(ptr_F->l != nullptr && ptr_F->r == nullptr) { // esse caso é oposto apenas a esquerda existe subarvore
			*this = ptr_F->l; // transformamos a raiz no ponteiuro a esquerda
			this->root = true; // avisamos que ele é a nova raiz
			ptr_F->root = false; // a antiga raiz não é mais raiz
			delete ptr_F; // deletamos a antiga raiz
		}
		else { // nesse caso existe sub arvore dos dois lados
			Arvore *aux = ptr_F->r; // salvamos um ponteiro para a direita
			Arvore *ant_aux = nullptr; // esse ponteiro vai guardar o ponteiro imediatamente pai do "aux"
			// descobrimos quem é o ponteiro mais a esquerda do ponteiro que por sua vez está a direita da raiz
			while(aux->l != nullptr) {
				ant_aux = aux;
				aux = aux->l;
			}
			if(ant_aux != nullptr) { // se existe ponteiro a esquerda do ponteiro a direita da raiz então cai nessa condição
				ant_aux->l = aux->r; // o pai do ponteiro mais a esquerda agora aponta para a direita do seu fiho
				// dessa forma se aux for deletado não será perdido nenhum ponteiro
			}
			else ptr_F->r = aux->r; // se não a raiz da arvore aponta para a "direita da direita" pulando uma casa
			// transformamos a raiz no aux
			ptr_F->chave = aux->chave;
			ptr_F->dados = aux->dados;
			// e deletamos o aux
			delete aux;
			/* note que deletar o aux não fará nenhim ponteiro se perder pois:
			o aux teve seu pai apontando para seu imediatamente a direira e ele não tem nanhum filho a esquerda
			*/
		}
	}
	else { // caindo aqui significa que o ponteiro a ser deletado não é a raiz da nossa arvore
		if(ptr_F->l == nullptr && ptr_F->r == nullptr) { // nesse caso tentamos deletar o nó folha
 			// o pai aponta para nada já que não existe subarvores no folho a ser deletado
			if(ptr_P->r == ptr_F) ptr_P->r = nullptr;
			else ptr_P->l = nullptr;

			delete ptr_F; // deletamos o filho
		}
		else if(ptr_F->l == nullptr && ptr_F->r != nullptr) { // nesse caso existe subarvore a direita apenas
			// o pai imediatamente a cima tem o ponteiro que apontava o filho agora "apontando para o unico filho de seu fiho"
			if(ptr_P->r == ptr_F) ptr_P->r = ptr_F->r;
			else ptr_P->l = ptr_F->r;

			delete ptr_F;// e deletamos o filho a ser deletado sem risco de perder ponteiros
			// pois sṍ avia um "filho do fiho" e esse foi salvo
		}
		else if(ptr_F->l != nullptr && ptr_F->r == nullptr) { // esse caso é oposto ao anterior e se executa de forma espelhada
			if(ptr_P->r == ptr_F) ptr_P->r = ptr_F->l;
			else ptr_P->l = ptr_F->l;
			delete ptr_F;
		}
		else { // esse é o caso especial onde existe filhos tanto a esquerda quando a direita do elemento a ser deletado
			Arvore *aux = ptr_F->r; // começamos apontando para o filho a direira
			Arvore *ant_aux = nullptr; // esse ponteiro apontará para o pai do "aux"
			// descobrimos que é o elemento mais a esquerda do elemento a direita do elemento a ser deletado
			while(aux->l != nullptr) {
				ant_aux = aux;
				aux = aux->l;
			}
			if(ant_aux != nullptr) { // se existe elemento a esquerda do elemento a direita do a ser deletado
				ant_aux->l = aux->r; //fazemos ele apontar para o unico filho do elemento mais a esquerda
				 // e o elemento mais a esquerda do elemento a direita agora aponta para a direita do elemento a ser deletado
				aux->r = ptr_F->r;
			}
			// nesse momento fazemos o ponteiro pai do elemento a ser deletado apontar com o ponteiro que antes indicava o filho
			// para o novo filho(o lemento mais a esquerda do elemento a direita)
			if(ptr_P->r == ptr_F) ptr_P->r = aux;
			else ptr_P->l = aux;

 			// o elemento mais a esquerda do elemento a direita agora aponta pela esquerda para o elemento a esquerda do elemento a ser deletado
			aux->l = ptr_F->l;

			delete ptr_F; // finalmente deletamos quem deve ser deletado
			/* note que nenhuma subarvore se perdeu pois:
			a subarvore a esquerda do elemento a ser deletado foi salva no elemento mais a esquerda do elemento a direita dele
			a subarvore a direita do elemento a ser deletado foi salva a direita do elemento mais a esquerda do elemento a direita dele
			a unica subarvore do elemento mais a esquerda do elemento a direita foi salva no elemento a direita do seu pai
			*/
		}
	}
	return true;
}

// esse função vai guardar em ptr_F o elemento a ser deletado e em ptr_P o elemento pai dele
void Arvore::remover_auxiliar(int c, Arvore *&ptr_P, Arvore *&ptr_F) {
	if(c == this->chave) {
		ptr_F = this;
	}
	else if(this->r != nullptr && c == this->r->chave) {
		ptr_P = this;
		ptr_F = this->r;
	}
	else if(this->l != nullptr && c == this->l->chave) {
		ptr_P = this;
		ptr_F = this->l;
	}
	else if(this->r != nullptr && c > this->chave) {
		ptr_P = this;
		this->r->remover_auxiliar(c, ptr_P, ptr_F);
	}
	else if(this->l != nullptr && c < this->chave) {
		ptr_P = this;
		this->l->remover_auxiliar(c, ptr_P, ptr_F);
	}
	else {
		ptr_P = ptr_F = nullptr;
	}
}
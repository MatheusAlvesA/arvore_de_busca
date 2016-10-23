#Arvore de Busca Binaria

 - Autor:

 Matheus Alves de Andrade

Esse algoritmo implementa uma estrutura de dado conhecida como arvore de busca,
de forma bem simples a arvore apenas possui os campos de de chave e dados sendo
a chave: um int e o dado: uma string;
A forma como escolhi implementar essa arvore pode ser considerada "diferente".
Na minha implementação cada nó da arvore é também uma arvore, sendo assim
quando inserimos um elemento é executado o comando new Arvore(chave, valor)
isso implica em algumas diferenças, são elas:
A arvore possui um atributo bool root que guarda se essa arvore é a raiz ou se
ela possui um pai acima dela.
A arvore só deleta recursivamente os elementos abaixo dela se ela for uma raiz
caso contrario qualquer remoção de elemento acarretaria a remoção de todos
os elementos abaixo dele.

##Implementação

O código escrito em c++ possui apenas as funções escenciais para o funcionamento
da arvore de buaca...
 - Inserir

Coloca novos dados 
 - get

Retorna um dado a partir da chave
 - remover

Remove a partir da chave um elemento armazenado na arvore

 - Construtor e Destrutor

São responsávei por setar os valores iniciais e liberar a memoria alocada, respectivamente

 - ehCompleta()

Retorna se a arvore é completa

 - eCheia()

Retorna se a arvore é cheia

 - enesimoElemento(int n)

Retorna o enesimo elemento no percurso de ordem simétrica

##Observação...
 O código está incompleto e ainda precisa ser melhorado, versão 0.5 iniciada em 17 de setembro de 2016
 
  versão 1.0, falta os incrementos

  versão 1.5 funções extras adicionadas ara enesimo e descrobrir se é cheia ou completa.


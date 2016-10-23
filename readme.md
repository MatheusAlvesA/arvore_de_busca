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

 - toString()

Retorna uma string contendo a arvore

 - mediana()

 Retorna calor mediano da arvore

 - enesimoElemento(int)

 Retorna qual é o enesimo elemento em um percurso de ordem simétrica

  - posicao(int)

 Retorna qual é a posição do elemento buscado quando procurado em umpercurso de ordem simétrica

##Como Compilar
Esse algoritmo foi desenvolvido em C++ no sistema Ubuntu, para compilar está disponível um arquivo makefile então apenas execute o comando make.
 Se preferir pode executar o comando de compilação: g++ -Wall -std=c++11 testes.cpp src/arvore.cpp -I include/ -o bin/arvore
 
 O arquivo binário estará disponível na asta bin/ ao final da compilação.

##Como Usar
Execute o programa via linha de comando do terminal linux e passe por parâmetro os arquivos contendo as inserções na arvore e os comandos.

 - Por exemplo
 ./bin/arvore inserts.txt comandos.txt

 O formato do arquivo inserts.txt deve ser:

 ... 0 1 2 3 4 5 6 7 8 9 10 42 2016 ...

 Já o arquivo comandos.txt deve ser:

ENESIMO N

POSICAO N

MEDIANA

CHEIA

COMPLETA

IMPRIMA

REMOVA N

Onde N é um valor inteiro

##Observação...
 O código está incompleto e ainda precisa ser melhorado, versão 0.5 iniciada em 17 de setembro de 2016
 
  versão 1.0, falta os incrementos

  versão 1.5 funções extras adicionadas para enesimo e descrobrir se é cheia ou completa.

  versão 1.9 quase tudo pronto, mas o toString não funciona corretamente. O algoritmo precisa de mais testes
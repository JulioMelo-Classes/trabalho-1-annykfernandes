
# Como executar o programa:
1 - entrar em trabalho-1-annykfernandes/build

2 - execute o comando abaixo:
```
cmake --build .
```

3 - execute o comando abaixo:
```
./forca ../data/palavras.txt ../data/scores.txt
```

4 - jogar o jogo, have fun.

# Avaliação

## Código | Funcionalidades
1. Classe forca 5/10
- Ok, o principal problema aqui foi o uso de variáveis globais. Você já sabe de ITP que não deve usá-las. No caso
do seu Forca.cpp existem várias, se você precisava daquelas variáveis deveria colocar elas como atributos da classe
ou usá-las localmente nas funções onde são necessárias.

2. Interface textual 10/10

3. Execução completa do jogo 10/15
- No nível médio e fácil não são sorteadas as letras de handcap.
- Quando o usuário digita mais de uma vez a mesma letra o jogo considera como um novo palpite, o que está errado.
- A maneira como você escolheu processar as dificuldades não usa o valor da frequencia média, assim o jogo depende
das frequencias terem sido pré planejadas por quem escreveu o arquivo de palavras. Embora não seja ruim vai contra
o documento de especificação então vou penalizar você.

4. Validação dos arquivos de texto 5/5
- Você fez algumas validações então vou considerar 100%

5. Arquivos de teste de validação dos casos de erro 0/5
- A ideia aqui era vc colocar arquivos de teste que mostrassem os casos de erro de validação

6. Arquivos de teste de validação dos níveis de dificuldade 1/5
- Vou considerar o arquivo que já está aqui como um arquivo possível mas a ideia era que houvessem mais arquivos de palavras
mostrando a funcionalidade de dificuldade e especialmente o fim de jogo quando não há palavras daquela dificuldade.

7. Observações gerais
- Tente não usar variáveis globais da próxima vez
- Gostei da ideia de dividir a parte de arquivos, embora a classe Player lembre mais uma representação do Score do que do jogador em si =).

## Código | Boas práticas

1. Documentação do código e readme 5/10
- As classes implementadas não foram documentadas

2. Organização e indentação 5/10
- Vou penalizar pela forma como você usou os includes além do uso de variáveis globais em Forca.cpp

3. Compilação automatizada 5/5


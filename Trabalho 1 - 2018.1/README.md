# CŔÉDITOS
## Gabriele Luz - https://github.com/gabrieleluz

# Simulação de um cartório
Um cartório é uma repartição pública ou privada que tem como principal função a custódia de documentos com fé pública, ou seja, é uma organização burocrática que organiza documentos importantes. Desta forma, nosso objetivo é simular uma versão simplificada de um cartório que gerencia a aquisição e transferência de bens através do atendimento de clientes pelos guichês do cartório.

Cada simulação deve receber como entrada a quantidade de guichês e clientes bem como informações das operações a serem executadas.  Ademais, ao final a simulação deve gerar um relatório parcial informando a situação de cada guichê e um relatório final sobre todos bens dos CPFs envolvidos na simulação.

## A simulação
Para cada simulação, informamos que o cartório contém M guichês, recebe N clientes durante um dia e L níveis de prioridade. Cada cliente tem os seguintes dados: Código de pessoa física (CPF), operação, o bem, CPF de terceiro envolvido na operação e sua prioridade. Cada dado tem a seguinte forma:
- CPF cliente: inteiro;
- Operação: caractere ‘A’ para aquisição e ‘T’ para transferência;
- Bem: string;
- CPF terceiros: inteiro;
- Prioridade: inteiro.
A entrada de cada cliente é gerenciada por L filas, onde cada fila representa uma prioridade. 

Deve-se escolher o cliente referente a fila de maior prioridade e alocá-lo em um guichê disponível utilizando a estratégia de round–robin iniciando do guichê 0 (zero), ou seja, se o cliente anterior foi alocado no guichê k mod M, então o presente cliente de ser alocado no guichê k + 1 mod M ficando a seguinte ordem dos guichês selecionados:

  0 , 1, 2 , . . . , M − 1 , 0 , 1 , 2 , . . . , M − 1 , 0 , . . . .

Cada cliente realiza apenas uma operação, mas não existe restrição da quantidade de vezes que um cliente é atendido. Cada guichê atende a um cliente por vez e armazena os documentos de cada cliente em uma pilha. Ao finalizar os atendimentos, deve ser impresso o relatório parcial de cada guichê, onde será informado a quantidade de documentos armazenados no guichê seguido dos dados de cada documento. Após a impressão dos relatórios parciais, deve-se gerar o relatório final que informa a quantidade de CPFs envolvidos nas operações e imprimir as operações de cada CPF, onde a chave para ordenação é o CPF. 

## Entrada 
A entrada é constituída por uma única simulação enviada pela entrada padrão. A primeira linha contém três inteiros L, M e N separados por um espaço em branco, onde 
  1 ≤ L, M, N ≤ 2 32 − 1 . L 
será a quantidade de níveis de prioridades, M será a quantidade de guichês e N a quantidade de clientes envolvidos na simulação. 

As próximas N linhas deve conter os seguintes valores C , CT , P , O e B onde 1 ≤ C ≤ 2 32 − 1 representa o CPF do cliente, 1 ≤ CT ≤ 2 32 − 1 o CPF do terceiro envolvido, 1 ≤ P ≤ L a prioridade do cliente C , O ∈ { A, T } o caractere referente a operação e B a string de tamanho no máximo 25 referente ao nome do bem envolvido na transação.

## Saída

A saída é constituída por dois relatórios para que devem ser enviados pela saída padrão seguindo a formatação descrita nessa seção. 

### Relatório Parcial 
Antes do relatório parcial deve ser impressa a mensagem “ -:| RELATÓRIO PARCIAL |:- ” e seguido de um inteiro M referente a quantidade de guichês envolvidos na simulação, na linha seguinte deve ser impresso o texto ” Guiche k : P k ” onde k é o número do guichê e um inteiro P k referente a quantidade de documentos empilhados no guichê k e nas próximas P k linhas informaŕa os valores de cada operação na formatação “ [CPFc,CPFt,O,B] ” onde “CPFc” é referente ao CPF do cliente atendido, “CPFt” o cpf do terceiro envolvido na operação, “O” o caractere referente a operação e “B” uma string referente ao nome do bem onde deve-se substituir espaços em brancos por underlines e utilizar os símbolos em maiúsculos (ex: entrada: “CasA b” relatório parcial: ”CASA_B”).
A ordem e impressão de cada guichê deve ser a mesma de atendimento. 


### Relatório Final
Relatório Final
Antes do relatório final deve ser impressa a mensagem " -:| RELATÓRIO FINAL |:- ”.
Na linha seguinte um inteiro K informa a quantidade de CPFs envolvidos na simulação e o relatório deve seguir a forma- tação " -:[ CPF ` : B ` ” , onde "CPF ` ” um inteiro que indica o ` -ésimo CPF e B ` um inteiro referente a quantidade de bens envolvidos nas operações do CPF ` seguindo por uma lista ordenada crescente (alfanumericamente) dos B ` bens com a seguinte formatação: \ tSBem , onde \ t é o símbolo de tabulação, "S” deve ser + para aquisição e - para transferência, e "Bem” o nome do bem com espaços em brancos substituídos por underlines e símbolos em maiúsculos.

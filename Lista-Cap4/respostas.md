# Lista de Exercícios – Capítulo 4: Comandos de Decisão

Respostas das questões teóricas (Parte I). As questões práticas estão nos arquivos `exercicio07.c` a `exercicio28.c`.

---

## Questão 01 – Expressões condicionais: atribuição vs. igualdade

**a)** `if (x = 0)` é uma **atribuição**, não uma comparação: `x` passa a valer `0` e o valor da expressão é `0`. Como `0` é falso, o bloco do `if` **nunca** é executado (e, se houver `else`, ele é que roda). Além do erro de lógica, o valor original de `x` é perdido. Já `if (x == 0)` apenas compara, sem alterar `x`.

**b)** Em C não existe um tipo lógico nativo (no ANSI C): a condição é um valor numérico. **Zero** (0 ou 0.0) é avaliado como **falso**; **qualquer valor diferente de zero** (positivo ou negativo, inteiro ou real) é **verdadeiro**. Os operadores relacionais e lógicos devolvem `1` para verdadeiro e `0` para falso.

**c)** `if (x = -5)` atribui `-5` a `x` e a expressão vale `-5`. Como é diferente de zero, é considerado verdadeiro e o bloco **é executado** — sempre, independentemente do valor anterior de `x`.

---

## Questão 02 – Associação do else e aninhamento

**a)** Será impresso **"Opção B"**. Apesar da indentação sugerir outra coisa, o `else` pertence ao `if (y > 10)`. Como `x > 10` é verdadeiro, entra no `if` interno; `y > 10` é falso (y = 5), então executa o `else` → "Opção B".

**b)** Regra: um `else` sempre se associa ao **`if` mais próximo anterior que ainda não tenha `else`**, dentro do mesmo bloco. A indentação não tem efeito para o compilador.

**c)**
```c
int x = 15, y = 5;
if (x > 10) {
    if (y > 10)
        printf("Opção A\n");
} else {
    printf("Opção B\n");
}
```
Agora "Opção B" só aparece quando `x <= 10`.

---

## Questão 03 – Operador ternário vs. if-else

**a)** A expressão `(media >= 7.0) ? 'A' : 'R'` avalia a condição; se for verdadeira, o resultado é `'A'`, senão `'R'`. Esse resultado é atribuído a `situacao`. Com `media = 6.8`, a condição é falsa e `situacao` recebe **`'R'`**.

**b)**
```c
media = (nota1 + nota2) / 2.0;
if (media >= 7.0)
    situacao = 'A';
else
    situacao = 'R';
```

**c)** Não. O ternário é um **operador**: produz um único **valor** a partir de expressões, por isso serve para escolher entre dois valores (em atribuições, argumentos de `printf` etc.). Ele não aceita blocos com vários comandos, declarações, laços ou `return`. Quando cada caminho precisa executar várias instruções, usa-se `if-else`. Ternários aninhados também prejudicam a legibilidade.

---

## Questão 04 – switch-case e fall-through

**a)** Saída:
```
Prata
Ouro
```
`codigo = 2` desvia para `case 2`, imprime "Prata". Como não há `break`, a execução continua no `case 3` e imprime "Ouro"; aí encontra o `break` e sai do `switch`.

**b)** O `break` encerra o `switch` e pula para a instrução após a chave de fechamento. Sem ele, a execução "cai" para os `case` seguintes — fenômeno chamado **fall-through** (queda/passagem direta).

**c)** A expressão do `switch` deve ser de **tipo inteiro**: `int`, `char`, `short`, `long` (com ou sem `unsigned`) e `enum`. **Não** é permitido `float` ou `double`, porque os rótulos `case` precisam ser constantes inteiras comparadas por igualdade exata, e valores reais têm problemas de precisão (ex.: 0.1 + 0.2 ≠ 0.3).

---

## Questão 05 – Curto-circuito

**a)** Saída: **`a = 0, b = 5, c = 8`**. Como `a != 0` é falso, o `&&` já sabe que o resultado é falso e **não avalia** `++b`; b continua 5. Vai para o `else`: `c = 10 - 2 = 8`.

**b)** Avaliação de curto-circuito: a expressão é avaliada da esquerda para a direita e para assim que o resultado está definido.
- **`&&` (E):** se o operando da esquerda é falso, o resultado é falso e o da direita não é avaliado.
- **`||` (OU):** se o operando da esquerda é verdadeiro, o resultado é verdadeiro e o da direita não é avaliado.

**c)** Com `if (a == 0 || ++b > 5)`: `a == 0` é verdadeiro, então `++b` **não é executado**. Entra no `if`: **b = 5** e **c = 20**.

---

## Questão 06 – else-if e intervalos

**a)** Para `idade = 65` a saída é:
```
Idoso
Adulto
Jovem
```
Os três `if` são independentes; cada um é testado separadamente e 65 satisfaz `>= 60`, `>= 18` e `>= 12`. Só o último tem `else`, por isso "Criança" não aparece.

**b)** Em uma sequência de `if` independentes **todas** as condições são testadas, e várias podem ser verdadeiras. Em uma cadeia `else-if`, os testes são feitos em ordem e, assim que uma condição é verdadeira, seu bloco é executado e o **resto da cadeia é ignorado** — no máximo um bloco roda.

**c)**
```c
int idade = 25;
if (idade >= 60)
    printf("Idoso\n");
else if (idade >= 18)
    printf("Adulto\n");
else if (idade >= 12)
    printf("Jovem\n");
else
    printf("Criança\n");
```

# Simulado — Capítulos 1, 2 e 3 — Respostas

**Disciplina:** Programação Imperativa e Funcional (PIF) — CESAR School, 2026.2
**Docente:** Prof. Danilo Farias Soares da Silva

> Parte I (questões 01 a 06) respondida neste documento.
> Parte II (questões 8 a 15) está nos arquivos `.c` desta pasta, um por questão.
> Observação: a lista não tem Questão 07 — a numeração pula da 06 para a 8.

---

## PARTE I — Questões teóricas e analíticas

### Questão 01 — Sensibilidade a caixa (case sensitivity)

**Resposta: alternativa (c).**

Todos os pares (`valor`/`VALOR`, `peso`/`Peso`, `taxa`/`TAXA`) são identificadores **totalmente distintos** para o compilador, porque C diferencia maiúsculas de minúsculas.

Por que as outras estão erradas:

- **(a)** `numero` e `Numero` são duas variáveis diferentes, cada uma com seu próprio endereço de memória.
- **(b)** O ponto de entrada é `main`, todo em minúsculas. `Main` é só um identificador qualquer; um programa sem `main` compila, mas falha na ligação (*linker*: `undefined reference to 'main'`).
- **(d)** A diferenciação faz parte da própria definição da linguagem C. Não depende do sistema operacional.

---

### Questão 02 — Erros no código do estudante

Código original:

```c
#include <stdio.h>
#include <stdlib.h>;
int Main()
{
int idade = 20;
printf( A idade do aluno eh: %d anos.. , idade);
cout << endl;
system("PAUSE");
return 0;
}
```

**Os três erros principais:**

1. **`printf` sem aspas na string de formato.** O texto `A idade do aluno eh: %d anos..` precisa ficar entre aspas duplas, porque é uma *string literal*. Sem as aspas, o compilador lê `A` como uma variável não declarada (`error: 'A' undeclared`).
   Correto: `printf("A idade do aluno eh: %d anos.\n", idade);`

2. **`cout << endl;` é C++, não C.** `cout` e `endl` pertencem à biblioteca `<iostream>` do C++ e não existem em C (`error: 'cout' undeclared`, `error: 'endl' undeclared`). Em C, a quebra de linha é feita com a sequência de escape `\n` dentro do `printf`.
   Correto: `printf("\n");`

3. **`int Main()` com "M" maiúsculo.** Como C diferencia maiúsculas de minúsculas, `Main` não é o ponto de entrada do programa. O arquivo até compila, mas a ligação falha com `undefined reference to 'main'`.
   Correto: `int main()`

**Problema adicional (estrutural):** `#include <stdlib.h>;` → diretivas de pré-processador (`#include`, `#define`) **não terminam com ponto e vírgula**. O GCC emite `warning: extra tokens at end of #include directive`; outros compiladores podem tratar isso como erro.

Código corrigido:

```c
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int idade = 20;
    printf("A idade do aluno eh: %d anos.\n", idade);
    printf("\n");
    system("PAUSE");   /* funciona apenas no Windows */
    return 0;
}
```

---

### Questão 03 — Atribuição composta e avaliação sequencial

Valores iniciais: `a = 2`, `b = 4`, `c = 5`, `d = 10`.

| Linha | Como é avaliada | Resultado |
|---|---|---|
| `a += b + c;` | `a = 2 + (4 + 5)` | **a = 11** |
| `b *= c = d - 2;` | Da direita para a esquerda: primeiro `c = 10 - 2 = 8`, depois `b = 4 * 8` | **c = 8, b = 32** |
| `d %= a + 3;` | `d = 10 % (11 + 3) = 10 % 14` | **d = 10** |
| `a += b += c += 5;` | Da direita para a esquerda: `c = 8 + 5 = 13` → `b = 32 + 13 = 45` → `a = 11 + 45 = 56` | **c = 13, b = 45, a = 56** |

Os operadores compostos (`+=`, `*=`, `%=`) têm precedência menor que os aritméticos. Por isso, `a + 3` e `b + c` são calculados antes da atribuição.

**Valores finais: a = 56, b = 45, c = 13, d = 10.**

---

### Questão 04 — Expressões lógicas, relacionais e precedência

`i = 2`, `j = 3`, `k = 0`, `x = 2.5`, `y = 5.0`. Ordem de precedência: aritméticos → relacionais (`<`, `<=`, `>=`) → igualdade (`==`) → `&&` → `||`. O `!` é unário e tem a maior precedência de todas.

| Item | Expressão | Avaliação passo a passo | Resultado |
|---|---|---|---|
| a | `i < j + 2` | `2 < 5` | **1** |
| b | `2 * i - 5 <= j - 4` | `(4 - 5) <= (3 - 4)` → `-1 <= -1` | **1** |
| c | `!k && (x + y >= 7.5)` | `!0 = 1`; `7.5 >= 7.5 = 1`; `1 && 1` | **1** |
| d | `!(i == j) \|\| (y / x == 2.0)` | `i == j` é 0, então `!0 = 1`; o `\|\|` faz curto-circuito e já resulta em 1 (de qualquer forma, `5.0 / 2.5 == 2.0` também é 1) | **1** |
| e | `i == 2 && j == 4 \|\| k == 0` | `&&` vem antes de `\|\|`: `(1 && 0) \|\| 1` → `0 \|\| 1` | **1** |

---

### Questão 05 — `for`, `while` e `do-while`

**a) Diferença entre `while` e `do-while`**

- O **`while`** testa a condição **antes** de executar o bloco (laço pré-testado). Se a condição já começa falsa, o bloco é executado **zero vezes**.
- O **`do-while`** executa o bloco primeiro e testa a condição **depois** (laço pós-testado). O bloco é executado **pelo menos uma vez**, mesmo que a condição seja falsa desde o início.

Por isso, o `do-while` é ideal para menus e validação de entrada: é preciso pedir o dado pelo menos uma vez antes de saber se ele é válido.

**b) Quando o `for` é mais elegante que o `while`**

Quando a repetição é **controlada por contador**, isto é, quando se sabe (ou se calcula) de antemão quantas vezes o laço vai rodar. Exemplos: percorrer de 1 a N, iterar sobre os índices de um vetor, imprimir uma tabela de N linhas. O `for` junta as três partes do controle no cabeçalho — inicialização, condição e incremento (`for (i = 1; i <= n; i++)`) —, deixando o laço mais legível e diminuindo o risco de esquecer o incremento e criar um laço infinito. O `while` fica melhor quando o número de repetições é indeterminado e depende de um evento (valor sentinela, resposta do usuário, fim de arquivo).

**c) `while (condicao);` com ponto e vírgula**

É um **erro de lógica**, não de compilação: o código compila normalmente (no máximo, alguns compiladores emitem um *warning*). O `;` vira uma **instrução vazia** e passa a ser o corpo do laço. O bloco `{ ... }` logo abaixo deixa de pertencer ao `while` e se torna um bloco comum, executado uma única vez depois do laço.

- Se `condicao` for **verdadeira**: o laço repete a instrução vazia, que nunca altera a condição. O resultado é um **laço infinito** — o programa "trava" consumindo CPU e o bloco abaixo nunca chega a ser executado.
- Se for falsa: o laço termina na hora e o bloco abaixo é executado uma vez, sem nenhuma repetição.

---

### Questão 06 — Escopo de bloco, `break` e `continue`

**a) Por que dá erro de compilação no `printf`**

A variável `soma` é declarada **dentro do bloco do `for`** (`int soma = 0;`). Em C, uma variável declarada dentro de `{ }` só existe dentro daquele bloco (**escopo de bloco**). Quando o laço termina, `soma` sai de escopo e deixa de existir. No `printf` final, ela não está mais declarada, e o compilador acusa `error: 'soma' undeclared`.

Há ainda um segundo problema de lógica: mesmo que compilasse, `soma` seria **recriada e zerada a cada iteração**, e nunca acumularia nada.

**b) Iterações executadas e o efeito de `continue` / `break`**

| `i` | O que acontece |
|---|---|
| 1, 2, 3, 4 | Executam o corpo inteiro (somam `i * i`) |
| 5 | `continue` → pula o resto do corpo e vai direto para o `i++`; o 25 **não** é somado |
| 6, 7 | Executam o corpo inteiro |
| 8 | `break` → sai do laço imediatamente; o 64 **não** é somado |
| 9, 10 | Nunca chegam a ser avaliados |

- O **`continue`** interrompe só a iteração atual e passa para a próxima (no `for`, executa o incremento e testa a condição de novo).
- O **`break`** encerra o laço por completo, e a execução segue na primeira instrução depois do `for`.

As iterações que efetivamente somam são as de **i = 1, 2, 3, 4, 6 e 7**.

**c) Código corrigido e saída**

Basta declarar e inicializar `soma` **antes** do laço, no escopo da função `main`:

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i;
    int soma = 0;          /* declarada fora do for: escopo da main */

    for (i = 1; i <= 10; i++) {
        if (i == 5) continue;
        if (i == 8) break;
        soma += i * i;
    }

    printf("Soma final = %d\n", soma);
    system("PAUSE");       /* funciona apenas no Windows */
    return 0;
}
```

Cálculo: 1² + 2² + 3² + 4² + 6² + 7² = 1 + 4 + 9 + 16 + 36 + 49 = **115**

Saída no console:

```
Soma final = 115
```

---

## PARTE II — Questões práticas (arquivos `.c`)

| Questão | Arquivo | Assunto |
|---|---|---|
| 8 | `q08_esfera.c` | Área e volume da esfera com `pow()` |
| 9 | `q09_heron.c` | Área do triângulo pela fórmula de Heron com `sqrt()` |
| 10 | `q10_tempo.c` | Segundos → horas, minutos e segundos com `/` e `%` |
| 11 | `q11_salario.c` | Holerite com gratificação de 5% e IR de 8% |
| 12 | `q12_nota.c` | Validação de nota com `do-while` |
| 13 | `q13_fatorial.c` | Fatorial com `long long int` e `%lld` |
| 14 | `q14_senha.c` | Autenticação com no máximo 3 tentativas |
| 15 | `q15_floyd.c` | Triângulo de Floyd com laços aninhados |

Compilação (programas que usam `<math.h>` precisam do `-lm` no Linux):

```bash
gcc q08_esfera.c -o q08 -lm
./q08
```

# Lista de Exercícios – Capítulo 1: Conceitos Básicos

**Disciplina:** Programação Imperativa e Funcional (PIF) — CESAR School 2026.2
**Livro-base:** *Treinamento em Linguagem C* — Victorine Viviane Mizrahi

As questões práticas estão em arquivos `.c` separados nesta pasta (ver índice no final).

---

## Questões 01, 02 e 03

Questões práticas: [`exercicio01.c`](exercicio01.c), [`exercicio02.c`](exercicio02.c), [`exercicio03.c`](exercicio03.c).

---

## Questão 04 — Erros do programa

Código original:

```c
#include <stdio.h>
#include <stdlib.h>;
int Main{}
(
printf( Existem %d semanas no ano.,52);
cout << endl;
system("PAUSE");
return 0;
)
```

| # | Trecho | Erro | Correção |
|---|--------|------|----------|
| 1 | `#include <stdlib.h>;` | Diretivas do pré-processador não terminam com `;` | `#include <stdlib.h>` |
| 2 | `Main` | C é *case-sensitive*: o ponto de entrada obrigatório é `main`, em minúsculas. Com `Main` o linker não encontra `main` | `main` |
| 3 | `Main{}` | A lista de parâmetros de uma função usa parênteses `()`, não chaves | `int main()` |
| 4 | `(` ... `)` | O corpo da função é delimitado por chaves `{ }`, não por parênteses | `{` ... `}` |
| 5 | `printf( Existem %d semanas no ano.,52);` | O texto de controle do `printf` é uma string e precisa estar entre aspas duplas | `printf("Existem %d semanas no ano.", 52);` |
| 6 | `cout << endl;` | `cout`/`endl` são da biblioteca `<iostream>` do **C++**, não existem em C | `printf("\n");` |

Versão corrigida: [`exercicio04.c`](exercicio04.c)

```c
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Existem %d semanas no ano.", 52);
    printf("\n");
    system("PAUSE");
    return 0;
}
```

---

## Questão 05 — O programa está correto em ANSI C?

**Não.** Faltam:

1. **`#include <stdio.h>`** — necessário para o protótipo de `printf()`. Sem ele a função é usada sem declaração (declaração implícita, que gera aviso no C89 e é erro a partir do C99).
2. **`#include <stdlib.h>`** — necessário para o protótipo de `system()`.
3. **Tipo de retorno de `main`** — o correto é `int main()`. O "int implícito" era tolerado em compiladores antigos, mas foi removido do padrão no C99.
4. **`return 0;`** — `main` deve devolver um valor inteiro ao sistema operacional indicando término normal.

Versão correta:

```c
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Linguagem C");
    system("pause");
    return 0;
}
```

---

## Questão 06 — Erros de sintaxe e de lógica

```c
main()
{
int a=1; b=2; c=3:
printf("0s números são: %d%d%d\n, a, b, c, d);
system("pause");
}
```

**Erros de sintaxe:**

1. Falta `#include <stdio.h>` (para `printf`) e `#include <stdlib.h>` (para `system`).
2. `main()` sem tipo de retorno: deve ser `int main()`, com `return 0;` no final.
3. `int a=1; b=2; c=3:` — o `;` após `a=1` **encerra a declaração**, então `b` e `c` nunca são declaradas (erro: identificador não declarado). O correto é separar com vírgulas: `int a=1, b=2, c=3;`.
4. `c=3:` — termina com **dois-pontos** em vez de ponto-e-vírgula.
5. A string do `printf` **não foi fechada**: falta a aspa dupla depois de `\n` (`"...\n", a, b, c`).
6. `d` é usada mas **nunca foi declarada**.

**Erros de lógica:**

7. `"0s"` está escrito com o **dígito zero** em vez da letra **O** maiúscula ("Os números...").
8. Há **4 argumentos** (`a, b, c, d`) para apenas **3 especificadores** `%d`. Mesmo que `d` existisse, ela seria ignorada.
9. `%d%d%d` sem separadores imprime os números colados: `123`, o que torna a saída ilegível.

Versão corrigida:

```c
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 1, b = 2, c = 3;
    printf("Os números são: %d %d %d\n", a, b, c);
    system("pause");
    return 0;
}
```

---

## Questão 07 — Saída exata de cada `printf()`

Legenda: `⏎` = quebra de linha (`\n`), `→` = tabulação (`\t`).

| Item | Saída |
|------|-------|
| a) `"\n\tBom dia! Shirley."` | `⏎` `→Bom dia! Shirley.` (o cursor fica no fim da linha, sem quebra) |
| b) `"Você já tomou café? \n"` | `Você já tomou café? ⏎` (há um espaço antes da quebra) |
| c) `"\n\nA solução não existe!\nNão insista."` | `⏎⏎A solução não existe!⏎Não insista.` |
| d) `"Duas\tlinhas\tde\tsaída\nou\tuma?"` | `Duas→linhas→de→saída⏎ou→uma?` |
| e) `"%s\n%s\n%s\n", "um", "dois", "três"` | `um⏎dois⏎três⏎` |

Como aparece no console:

```
a)

        Bom dia! Shirley.

b)
Você já tomou café?

c)


A solução não existe!
Não insista.

d)
Duas    linhas  de      saída
ou      uma?

e)
um
dois
três
```

> **Duas respostas:**
> - Em (d), o `\t` avança o cursor até a **próxima parada de tabulação**, normalmente de 8 em 8 colunas. Por isso os espaços entre as palavras não têm todos o mesmo tamanho.
> - Em (e), cada `%s` é substituído, na ordem, pela string correspondente da lista de argumentos.

---

## Questão 08 — Comportamento do programa

```c
printf("\n\t\"Primeiro programa\"");
```

Sequências de escape da string de controle, em ordem:

| Escape | Significado | Efeito |
|--------|-------------|--------|
| `\n` | nova linha | o cursor desce para o início da linha seguinte |
| `\t` | tabulação horizontal | o cursor avança até a próxima parada de tabulação (coluna 8) |
| `\"` | aspas duplas literais | imprime o caractere `"` sem encerrar a string |
| `Primeiro programa` | texto comum | impresso como está |
| `\"` | aspas duplas literais | imprime o `"` de fechamento |

Saída exata:

```

        "Primeiro programa"Pressione qualquer tecla para continuar. . .
```

Primeiro sai uma linha em branco. Depois vem uma tabulação e o texto **entre aspas**. Como a string não termina com `\n`, a mensagem de `system("PAUSE")` (no Windows) aparece **na mesma linha**, logo após o texto. O programa fica parado esperando uma tecla e depois retorna `0`.

---

## Questão 09 — `%c` com constantes de caractere

```c
printf("%c%c%cPrimeiro programa", '\n', '\t', '\"');
printf("%c", "\"");
```

**Primeiro `printf`:** cada `%c` recebe, na ordem, uma **constante de caractere**. Em C, uma constante de caractere é apenas o **código numérico** do caractere na tabela ASCII (`'\n'` = 10, `'\t'` = 9, `'\"'` = 34). Ela é passada ao `printf` como um inteiro, e o `%c` imprime o caractere que corresponde a esse código. Por isso o efeito é **o mesmo** que escrever as sequências de escape direto na string: `printf("\n\t\"Primeiro programa")`.

**Segundo `printf` (há um erro):** `"\""` está entre **aspas duplas**, então é uma **string** (um vetor `{'"', '\0'}`), e não um caractere. O que chega ao `printf` é o **endereço** dessa string, mas `%c` espera um caractere. O resultado é **comportamento indefinido**: normalmente sai um caractere "lixo" (o byte menos significativo do endereço), e não as aspas. O GCC avisa com `-Wformat`: *format '%c' expects argument of type 'int', but argument 2 has type 'char *'*. O correto seria `printf("%c", '\"');` (ou `'"'`).

Saída, supondo a correção para `'\"'`:

```

        "Primeiro programa"Pressione qualquer tecla para continuar. . .
```

(Sem a correção, no lugar das aspas de fechamento aparece um caractere imprevisível.)

---

## Questão 10 — *Case sensitive*

**Alternativa correta: b) Verdadeiro.**

*Case sensitive* significa que o compilador C trata letras maiúsculas e minúsculas como **caracteres diferentes**. Assim, `peso`, `Peso` e `PESO` são **três identificadores distintos**: podem ser três variáveis diferentes, cada uma no seu próprio espaço de memória. Isso não depende do compilador, porque é regra do padrão da linguagem. Na prática:

- palavras-chave e funções da biblioteca precisam ser escritas exatamente como definidas (`int`, `main`, `printf`; `Int`, `Main` ou `PRINTF` não funcionam, como na Questão 04);
- erros de digitação de maiúscula/minúscula geram erros de "identificador não declarado";
- por convenção, constantes de `#define` costumam ser escritas em MAIÚSCULAS e variáveis em minúsculas, justamente para aproveitar essa distinção.

---

## Questão 11 — Classificação de constantes

| Constante | Classificação | Tipo base em C |
|-----------|---------------|----------------|
| `\r` | Sequência de escape (retorno de carro, *carriage return*, código 13) | `char` |
| `2130` | Constante inteira decimal | `int` |
| `-123` | Constante inteira decimal (negativa) | `int` |
| `33.28` | Constante de ponto flutuante | `double` |
| `0XFA` | Constante inteira **hexadecimal** (prefixo `0x`/`0X`) = 250 em decimal | `int` |
| `0101` | Constante inteira **octal** (prefixo `0`) = 65 em decimal | `int` |
| `2.0e30` | Constante de ponto flutuante em notação científica (2,0 × 10³⁰) | `double` |
| `\xDC` | Sequência de escape hexadecimal (código 220, `▄` na CP437) | `char` |
| `'\"'` | Constante de caractere (sequência de escape: aspas duplas, código 34) | `char` |
| `'\\'` | Constante de caractere (sequência de escape: barra invertida, código 92) | `char` |
| `'F'` | Constante de caractere (código ASCII 70) | `char` |
| `0` | Constante inteira (zero) | `int` |
| `'\0'` | Constante de caractere: caractere **nulo** (código 0), que marca o fim das strings | `char` |
| `"F"` | Constante **string** (ocupa 2 bytes: `'F'` + `'\0'`) | `char[]` (vetor de `char`) |
| `-4567.89` | Constante de ponto flutuante (negativa) | `double` |

> **Observações:**
> - Constantes de ponto flutuante sem sufixo são `double`. Para que sejam `float` é preciso o sufixo `f` (ex.: `33.28f`).
> - No padrão ISO C, a constante de caractere (`'F'`) tem tecnicamente tipo `int`, mas representa um valor do tipo `char`, que é a classificação usada pelo livro.
> - O sinal `-` em `-123` e `-4567.89` é o operador unário de negação aplicado à constante positiva.

---

## Questão 12 — Declarações de variáveis

| Instrução | Status | Justificativa |
|-----------|--------|---------------|
| a) `int a;` | **Correto** | Declara a variável `a` do tipo inteiro. |
| b) `float b;` | **Correto** | Declara `b` como ponto flutuante de precisão simples. |
| c) `double float c;` | **Incorreto** | `double` e `float` são **dois tipos base distintos**, e uma declaração só pode ter um tipo base. `double` não é um modificador de `float`. Use `double c;` ou `float c;`. |
| d) `unsigned char d;` | **Correto** | `unsigned` é um modificador válido para `char`: faixa de 0 a 255. |
| e) `unsigned e;` | **Correto** | Quando o tipo base é omitido, o modificador assume `int`: equivale a `unsigned int e;`. |
| f) `long float f;` | **Incorreto** | `long` não pode modificar `float` no padrão ANSI C. Era sinônimo de `double` no C antigo (K&R), mas foi removido. Para mais precisão, use `double f;`. |
| g) `long g;` | **Correto** | Equivale a `long int g;` (o `int` fica implícito). |
| h) `long double h;` | **Correto** | `long double` é o tipo de ponto flutuante de **precisão estendida** previsto no padrão ANSI. |

---

## Questão 13 — Arquivos de inclusão (`.h`)

**Alternativa correta: c)** São arquivos de texto ASCII padrão com protótipos de funções, definições de constantes, macros e tipos.

Um *header* **não** contém o código compilado das funções (que fica nas bibliotecas binárias, ligadas na linkedição). Ele contém apenas as **declarações**, para que o compilador saiba o nome, os parâmetros e o tipo de retorno de cada função antes de ela ser usada.

---

## Questão 14 — Objetivo de incluir `<stdio.h>`

**Alternativa correta: a)** Instruir o compilador a carregar as definições (protótipos) das funções da biblioteca padrão antes de compilar o código-fonte.

O `#include` faz o pré-processador **inserir o conteúdo do header** no ponto da diretiva. Assim, quando o compilador encontra `printf(...)`, ele já conhece a declaração da função e consegue verificar se a chamada está correta. A ligação com o código binário da função é feita depois, pelo **linkeditor**.

---

## Questão 15 — Classificação de `#include`

**Alternativa correta: c)** Uma diretiva especial para o pré-processador C, executada antes da compilação.

`#include` não é uma instrução C: não gera código de máquina e não termina com `;`. É uma ordem ao pré-processador para substituir a linha pelo conteúdo do arquivo indicado.

---

## Questão 16 — Quem interpreta as diretivas `#`

**Alternativa correta: c)** O pré-processador, a fase do compilador que altera o programa-fonte antes da compilação propriamente dita.

As etapas do processo de construção do executável são:

**pré-processamento** (resolve `#include`, `#define` etc.) → **compilação** (gera código objeto) → **linkedição** (une os objetos e as bibliotecas no executável).

---

## Questão 17 — Flexibilidade de espaçamento

| Instrução | Correta? |
|-----------|----------|
| a) `printf ( "Primeiro programa" );` | **Sim** |
| b) `printf( "Primeiro programa" );` | **Sim** |
| c) `printf("Primeiro programa");` | **Sim** |
| d) `printf "Primeiro programa" ;` | **Não**: faltam os parênteses da chamada de função |

**O que isso mostra:** C é uma linguagem de **formato livre**. Espaços, tabulações e quebras de linha **entre os elementos** (tokens) do programa são ignorados pelo compilador, então (a), (b) e (c) são equivalentes. O espaçamento serve apenas para a legibilidade. Já os **parênteses** fazem parte da sintaxe de chamada de função e não podem ser omitidos, por isso (d) não compila.

O espaço só é significativo **dentro** de uma string (`"Primeiro programa"` ≠ `"Primeiro  programa"`) e **entre** palavras que precisam estar separadas (`int a`, e não `inta`).

---

## Questões práticas

| Questão | Arquivo |
|---------|---------|
| 01 | [`exercicio01.c`](exercicio01.c) |
| 02 | [`exercicio02.c`](exercicio02.c) |
| 03 | [`exercicio03.c`](exercicio03.c) |
| 04 | [`exercicio04.c`](exercicio04.c) (versão corrigida) |
| 18 | [`exercicio18.c`](exercicio18.c) |
| 19 | [`exercicio19.c`](exercicio19.c) |
| 20 | [`exercicio20.c`](exercicio20.c) |
| 21 | [`exercicio21a.c`](exercicio21a.c) (1 `printf`), [`exercicio21b.c`](exercicio21b.c) (2 `printf`), [`exercicio21c.c`](exercicio21c.c) (emoldurado) |
| 22 | [`exercicio22.c`](exercicio22.c) |
| 23 | [`exercicio23.c`](exercicio23.c) |
| 24 | [`exercicio24.c`](exercicio24.c) |
| 25 | [`exercicio25.c`](exercicio25.c) |
| 26 | [`exercicio26.c`](exercicio26.c) |
| 27 | [`exercicio27.c`](exercicio27.c) |
| 28 | [`exercicio28.c`](exercicio28.c) |

### Compilação (VS Code + MinGW)

```bash
gcc -Wall -o exercicio01 exercicio01.c
./exercicio01
```

> **Nota sobre caracteres especiais:** as questões 20, 21c, 22 e 24 (e o "ê" da 19) usam códigos da **Codepage 437/850**, como `\xC9` e `\xDB`, que é a codificação padrão do console do Windows em português. No terminal do Windows eles aparecem como molduras e blocos. Em terminais Linux/macOS (UTF-8), ou se o console estiver em `chcp 65001`, aparecem símbolos estranhos.
>
> Na questão 24, os nomes acentuados (MÁRIO, SÉRGIO) usam escapes de 1 byte por um motivo prático: em UTF-8, `Á` ocupa 2 bytes, e o `printf` conta **bytes**, não letras. Com isso, `%-12s` desalinharia a coluna.

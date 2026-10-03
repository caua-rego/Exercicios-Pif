# Lista de Exercícios – Capítulo 2: Operadores

**Disciplina:** Programação Imperativa e Funcional (PIF) — CESAR School 2026.2
**Livro-base:** *Treinamento em Linguagem C* — Victorine Viviane Mizrahi

As questões práticas (Parte II) estão em arquivos `.c` separados nesta pasta (ver índice no final). As questões teóricas da Parte I também têm um `.c` de verificação, para conferir as respostas compilando.

---

## Questão 01 — Truncamento e coerção implícita

```c
int valor_inteiro;
valor_inteiro = 2.97;
printf("O valor armazenado eh: %d\n", valor_inteiro);
```

**a)** Será exibido **`2`**.

**b)** A constante `2.97` é um `double`, mas a variável é `int`. Na atribuição o compilador faz uma **conversão implícita de tipo** (coerção) de `double` para `int`. Nessa conversão a parte fracionária é simplesmente **descartada**, não arredondada: 2.97 vira 2 (e -2.97 viraria -2). O fenômeno chama-se **truncamento**. O compilador costuma avisar (*implicit conversion from 'double' to 'int' changes value from 2.97 to 2*), mas o programa compila e executa.

**c)** O programador pode controlar a conversão de forma explícita:

| Objetivo | Como fazer | Resultado |
|----------|-----------|-----------|
| Deixar claro que se quer truncar | *cast* explícito: `valor = (int) 2.97;` | 2 |
| Arredondar para o inteiro mais próximo | `valor = (int) (2.97 + 0.5);` (para positivos) ou `valor = (int) round(2.97);` com `<math.h>` | 3 |
| Manter a precisão | declarar a variável como `float` ou `double` | 2.97 |

Verificação: [`exercicio01.c`](exercicio01.c)

---

## Questão 02 — `<conio.h>` vs. biblioteca padrão

**a)** `<conio.h>` **não faz parte do padrão ANSI/ISO C**. Ela nasceu nos compiladores para MS-DOS/Windows (Turbo C, Borland, depois MinGW) e manipula o console diretamente. Em Linux, macOS e servidores o GCC/Clang **não têm esse header**: o programa nem compila. Mesmo quando existe, o comportamento de `getch()`/`getche()` varia entre compiladores. Código que depende dela deixa de ser **portável**.

**b)** Em `<stdio.h>` os equivalentes padronizados são:

| Legada (`<conio.h>`) | Padrão (`<stdio.h>`) | Observação |
|----------------------|----------------------|------------|
| `getch()` / `getche()` | `getchar()` (ou `getc(stdin)` / `fgetc(stdin)`) | lê um caractere; a entrada é *bufferizada*, só chega após [ENTER] |
| `putch()` | `putchar()` (ou `putc()` / `fputc()`) | escreve um caractere |
| — | `scanf("%c", &c)` | também lê um caractere |

A leitura padrão é **com buffer**: o texto só é entregue ao programa depois do ENTER. Por isso o `'\n'` do ENTER fica no buffer e pode ser lido, por engano, pela próxima chamada de leitura.

**c)** Trecho robusto, que ignora `'\n'` residuais:

```c
int c, sobra;   /* int, e nao char, para poder comparar com EOF */

/* pula quebras de linha que sobraram de leituras anteriores */
do {
    c = getchar();
} while (c == '\n');

/* descarta o resto da linha atual (inclusive o ENTER) */
while ((sobra = getchar()) != '\n' && sobra != EOF)
    ;
```

Alternativa só com `scanf()`: `scanf(" %c", &ch);`. O **espaço antes de `%c`** instrui o `scanf` a pular todos os espaços em branco pendentes (inclusive `'\n'`) antes de ler o caractere.

Programa completo: [`exercicio02.c`](exercicio02.c)

---

## Questão 03 — Bases numéricas e ASCII

```c
int numero;
scanf("%d", &numero);
printf("Decimal: %d | Hexadecimal: %x | Octal: %o | Caractere ASCII: %c\n",
       numero, numero, numero, numero);
```

O mesmo valor é passado quatro vezes e cada especificador o apresenta de uma forma: `%d` em base 10, `%x` em base 16 com letras minúsculas (`%X` daria maiúsculas), `%o` em base 8 e `%c` como o caractere que tem esse código na tabela ASCII. Para a entrada `65`, a saída é:

```
Decimal: 65 | Hexadecimal: 41 | Octal: 101 | Caractere ASCII: A
```

Programa completo: [`exercicio03.c`](exercicio03.c)

---

## Questão 04 — Atribuição composta e precedência

Os operadores de atribuição (`=`, `+=`, `*=`...) têm **a menor precedência** entre os operadores binários e são avaliados **da direita para a esquerda**. Logo, em `x op= expressao`, toda a expressão à direita é calculada antes.

Valores iniciais: `a = 1, b = 2, c = 3, d = 4`.

| Instrução | Avaliação passo a passo | Resultado |
|-----------|-------------------------|-----------|
| `a += b + c;` | `a = a + (b + c)` = 1 + 5 | **a = 6** |
| `b *= c = d + 2;` | direita → esquerda: `c = d + 2` = 6; depois `b = b * c` = 2 × 6 | **c = 6, b = 12** |
| `d %= a + a + a;` | `d = d % (a + a + a)` = 4 % 18 | **d = 4** |
| `d -= c -= b -= a;` | `b = b - a` = 12 − 6 = 6; `c = c - b` = 6 − 6 = 0; `d = d - c` = 4 − 0 | **b = 6, c = 0, d = 4** |
| `a += b += c += 7;` | `c = c + 7` = 7; `b = b + c` = 6 + 7 = 13; `a = a + b` = 6 + 13 | **c = 7, b = 13, a = 19** |

**Valores finais:** `a = 19`, `b = 13`, `c = 7`, `d = 4`.

Verificação: [`exercicio04.c`](exercicio04.c)

---

## Questão 05 — Expressões relacionais e lógicas

Dados: `int i = 1, j = 2, k = 3, n = 2; float x = 3.3, y = 4.4;`

Precedência relevante (da maior para a menor): `!` e `-` unário → `*` → `+ -` → `< <= > >=` → `== !=` → `&&` → `||`.

| Item | Expressão | Avaliação | Resultado |
|------|-----------|-----------|-----------|
| a) | `i < j + 3` | 1 < 5 | **1** |
| b) | `2 * i - 7 <= j - 8` | −5 <= −6 | **0** |
| c) | `-x + y >= 2.0 * y` | 1.1 >= 8.8 | **0** |
| d) | `x == y` | 3.3 == 4.4 | **0** |
| e) | `!(n - j)` | !(0) | **1** |
| f) | `!n - j` | `(!n) - j` = 0 − 2 = −2 | **−2** (valor aritmético; como condição vale *verdadeiro*, pois é ≠ 0) |
| g) | `i && j && k` | 1 && 2 && 3 (todos ≠ 0) | **1** |
| h) | `i \|\| j - 3 && k` | `&&` antes de `\|\|`: `i \|\| ((j - 3) && k)` = 1 \|\| (−1 && 3); como `i` é verdadeiro, o `\|\|` nem avalia o resto (curto-circuito) | **1** |
| i) | `i < j && 2 >= k` | 1 && 0 | **0** |
| j) | `i == 2 \|\| j == 4 \|\| k == 5` | 0 \|\| 0 \|\| 0 | **0** |

> No item **f)** o `!` tem precedência maior que o `-` binário, então ele se aplica só a `n`. Em **e)** os parênteses forçam a subtração primeiro. A diferença entre os dois mostra por que parênteses são importantes em expressões lógicas.

Verificação: [`exercicio05.c`](exercicio05.c)

---

## Questão 06 — Incremento prefixado e pós-fixado

**a)** Nos dois casos a variável termina **incrementada em 1**. A diferença está no **valor que a expressão devolve**:

- `++n` (**prefixado**): primeiro incrementa `n`, depois entrega o **novo** valor. Trecho A: `n = 6`, `x = 6`.
- `m++` (**pós-fixado**): entrega o valor **antigo** de `m` e só depois incrementa. Trecho B: `m = 6`, `y = 5`.

Saída:

```
Trecho A: n = 6, x = 6
Trecho B: m = 6, y = 5
```

**b)** `printf("%d\t%d\t%d\n", n, n+1, n++);` é **comportamento indefinido** por dois motivos:

1. O padrão C **não define a ordem** em que os argumentos de uma função são avaliados. Um compilador pode avaliar `n++` antes de `n` (e então `n` já aparece incrementado), outro pode avaliar depois.
2. A mesma variável `n` é **modificada e lida na mesma expressão sem um ponto de sequência** entre as operações, o que o padrão proíbe explicitamente.

Assim, para `n = 6`, um compilador pode imprimir `6 7 6`, outro `7 8 6`, e o GCC avisa com `-Wsequence-point`. A forma correta é fazer a modificação em uma instrução separada: `printf("%d\t%d\t%d\n", n, n + 1, n); n++;`.

Verificação: [`exercicio06.c`](exercicio06.c)

---

## Questões práticas (Parte II)

| Questão | Tema | Arquivo |
|---------|------|---------|
| 07 | Data `dd/mm/aaaa` → `aaaa/mm/dd` com `scanf("%d/%d/%d")` | [`exercicio07.c`](exercicio07.c) |
| 08 | Quadrado e décima parte (divisão real) | [`exercicio08.c`](exercicio08.c) |
| 09 | Quatro operações, *cast* na divisão e operador `? :` para divisor zero | [`exercicio09.c`](exercicio09.c) |
| 10 | Celsius → Fahrenheit e Kelvin | [`exercicio10.c`](exercicio10.c) |
| 11 | Graus → radianos com `#define PI` | [`exercicio11.c`](exercicio11.c) |
| 12 | Antecessor e sucessor com `--` e `++` | [`exercicio12.c`](exercicio12.c) |
| 13 | Áreas do quadrado, retângulo e triângulo retângulo | [`exercicio13.c`](exercicio13.c) |
| 14 | Fórmula de Heron com `sqrt()` (`-lm`) | [`exercicio14.c`](exercicio14.c) |
| 15 | Média simples e ponderada (pesos 1, 1, 2, 2) | [`exercicio15.c`](exercicio15.c) |
| 16 | Degraus da escada com conversão m → cm e `ceil()` (`-lm`) | [`exercicio16.c`](exercicio16.c) |
| 17 | Área e circunferência do círculo | [`exercicio17.c`](exercicio17.c) |
| 18 | Área e volume da esfera com `4.0/3.0` | [`exercicio18.c`](exercicio18.c) |
| 19 | Salário do encanador com 8% de IR | [`exercicio19.c`](exercicio19.c) |
| 20 | Hipotenusa com `pow()` e `sqrt()` (`-lm`) | [`exercicio20.c`](exercicio20.c) |
| 21 | Caractere → código ASCII | [`exercicio21.c`](exercicio21.c) |
| 22 | Maiúscula → minúscula com `- 'A' + 'a'` | [`exercicio22.c`](exercicio22.c) |
| 23 | Horário de término do experimento com `/` e `%` | [`exercicio23.c`](exercicio23.c) |
| 24 | km/h → m/s | [`exercicio24.c`](exercicio24.c) |
| 25 | Salário com gratificação de 5% e imposto de 7% | [`exercicio25.c`](exercicio25.c) |
| 26 | Arame para cerca com 3 fios | [`exercicio26.c`](exercicio26.c) |
| 27 | Três dados com `rand() % 6 + 1` | [`exercicio27.c`](exercicio27.c) |
| 28 | Salário anual e imposto progressivo com `? :` | [`exercicio28.c`](exercicio28.c) |

### Compilação

```bash
gcc -Wall -o exercicio07 exercicio07.c
./exercicio07
```

As questões **01, 14, 16 e 20** usam `<math.h>` e precisam do *linker* da biblioteca matemática:

```bash
gcc -Wall -o exercicio14 exercicio14.c -lm
```

> **Observações:**
> - Nas questões 21 e 22, o `scanf(" %c", ...)` usa o espaço antes de `%c` justamente pelo motivo explicado na Questão 02: descartar o `'\n'` que ficaria no buffer.
> - Na questão 09, a divisão por zero é tratada com o operador condicional porque o `if` só aparece no capítulo seguinte.
> - Na questão 23, `total %= 24 * 3600` faz o horário "dar a volta" caso o experimento termine depois da meia-noite.

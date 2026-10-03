# Lista de Exercícios – Capítulo 3: Laços de Repetição

**Disciplina:** Programação Imperativa e Funcional (PIF) — CESAR School 2026.2
**Livro-base:** *Treinamento em Linguagem C* — Victorine Viviane Mizrahi

As questões práticas (Parte II) estão em arquivos `.c` separados nesta pasta (ver índice no final). As questões teóricas que pedem código corrigido ou reescrito (02, 03, 05 e 06) também têm o seu `.c`.

---

## Questão 01 — `for`, `while` e `do-while`

**a)** A diferença está no **momento do teste**:

| Estrutura | Quando testa a condição | Execuções mínimas do bloco |
|-----------|-------------------------|----------------------------|
| `while` | **antes** de cada iteração (pré-teste) | **0**: se a condição já for falsa na entrada, o corpo nunca executa |
| `do-while` | **depois** de cada iteração (pós-teste) | **1**: o corpo executa uma vez e só então a condição é avaliada |

**b)** Cada laço tem o seu uso natural:

- **`for`**: quando o número de repetições é **conhecido** ou controlado por um contador (percorrer de 1 a N, tabelas, vetores). Inicialização, teste e incremento ficam juntos no cabeçalho, o que deixa a intenção clara e evita esquecer o incremento.
- **`while`**: quando **não se sabe** quantas iterações haverá e o teste deve vir **antes** da primeira execução: ler dados até um valor sentinela, processar um arquivo até o fim, repetir enquanto houver trabalho.
- **`do-while`**: quando o corpo precisa executar **ao menos uma vez**: menus interativos (mostrar o menu, ler a opção, repetir até escolher "sair") e **validação de entrada** (pedir o valor, verificar, pedir de novo se inválido).

**c)** `while (condicao);` **não é erro de compilação**: o `;` sozinho é uma *instrução vazia* e é um corpo válido para o laço. É um **erro de lógica** (a menos que seja intencional, como na Questão 06). Se `condicao` for verdadeira e nada dentro do laço a alterar, o programa fica **em laço infinito**, travado nessa linha. Se a condição for falsa, o laço é pulado e o bloco `{ ... }` que vem logo depois executa **uma única vez**, pois já não pertence ao `while`.

---

## Questão 02 — Escopo e tempo de vida de variáveis de bloco

```c
int i;
for (i = 1; i < 10; i++) {
    int soma = 0;
    soma += i * i;
}
printf("Soma final = %d\n", soma);
```

**a)** A variável `soma` foi declarada **dentro do bloco** `{ }` do `for`. O seu **escopo** vai da declaração até a chave que fecha o bloco. Fora dele o identificador `soma` **não existe**, então o compilador acusa *'soma' undeclared* na linha do `printf`.

**b)** Mesmo com o `printf` dentro do laço, a cada iteração a variável é **criada de novo e inicializada com 0**, e ao fim da iteração ela é destruída. Logo `soma += i * i` sempre resulta em `0 + i * i`: o programa imprimiria **1, 4, 9, 16, ..., 81**, isto é, só o quadrado da iteração atual, e **nunca o acumulado**.

**c)** Código corrigido ([`exercicio02.c`](exercicio02.c)):

```c
int i;
int soma = 0;               /* declarada FORA do laço, no escopo de main */

for (i = 1; i < 10; i++) {
    soma += i * i;
}

printf("Soma final = %d\n", soma);   /* 285 */
```

Conceitos:

- **Escopo (visibilidade):** a região do código em que um identificador pode ser usado. Uma variável declarada dentro de um bloco `{ }` só é visível nesse bloco (e nos blocos internos a ele).
- **Variável de bloco (local automática):** é criada quando a execução entra no bloco e destruída quando sai. Esse é o seu **tempo de vida**. Por isso `soma` dentro do `for` "renasce" zerada em cada iteração.
- Para **acumular** um valor ao longo do laço, a variável precisa viver mais que uma iteração, ou seja, ser declarada em um escopo **externo** ao laço.

---

## Questão 03 — Flexibilidade do `for`

**a)** Trecho A, `for (a = 36; a > 0; a /= 2)`, usa divisão **inteira**. Sequência impressa (separada por tabulações):

```
36	18	9	4	2	1
```

Depois do 1, `a /= 2` dá `1 / 2 = 0`, a condição `a > 0` falha e o laço termina.

**b)** Trecho B omite a inicialização e o incremento: toda a lógica está no teste. A cada volta, `getch()` lê um caractere do teclado e o guarda em `ch`; se não for `'X'`, o corpo imprime `ch + 1`, que é o **caractere seguinte na tabela ASCII** (`'a'` vira `'b'`, `'1'` vira `'2'`). Quando o usuário digita `X`, o teste falha e o laço acaba.

Os parênteses em `(ch = getch())` são **obrigatórios** porque o operador `!=` tem **precedência maior** que o `=`. Sem eles a expressão seria lida como `ch = (getch() != 'X')`, ou seja, `ch` receberia o resultado da comparação, **0 ou 1**, e o caractere lido se perderia. O laço imprimiria apenas os caracteres de código 1 ou 2.

**c)** `for (;;)` roda para sempre porque não há condição a falhar. A saída programática é testar uma condição **dentro do corpo** e usar **`break`**, que encerra o laço e passa o controle à instrução seguinte. Alternativas: `return` (encerra a função) ou `exit()` (encerra o programa de forma controlada).

```c
for (;;) {
    printf("Laco Infinito\n");
    contador++;
    if (contador == 3)
        break;
}
```

Programa com os três trechos: [`exercicio03.c`](exercicio03.c) (o Trecho B foi adaptado para `getchar()`, já que `getch()` não é padrão, como visto no Capítulo 2).

---

## Questão 04 — `break` vs. `continue`

**a) `break`:** encerra **imediatamente** o laço (`for`, `while` ou `do-while`) em que está, sem executar o restante do corpo e **sem reavaliar a condição**. A execução continua na **primeira instrução após o laço**. (Dentro de um `switch` ele encerra o `switch`.)

**b) `continue`:** abandona o **restante do corpo** da iteração atual e salta para o início da **próxima iteração**. Em um `for`, a expressão executada **imediatamente** após o `continue` é a **terceira do cabeçalho, o incremento** (ex.: `i++`); só então a condição de teste é reavaliada. Em `while` e `do-while` o `continue` pula direto para o teste da condição, por isso é preciso cuidado para não deixar de incrementar o contador e cair em laço infinito.

**c)** O `break` só afeta o laço **mais interno** em que está escrito. Em dois `for` aninhados, um `break` no laço interno encerra **apenas o interno**; o laço externo segue normalmente, executa o seu incremento e inicia a próxima iteração, o que provavelmente recomeçará o laço interno do zero. Para sair dos dois é preciso uma variável de controle (*flag*) testada também no externo, ou um `return`.

---

## Questão 05 — Operador vírgula e múltiplas variáveis de controle

```c
for (i = 0, j = 10; i < j; i++, j--)
    printf("i = %d, j = %d | soma = %d\n", i, j, i + j);
```

**a)** O laço executa **5 iterações**. A cada volta `i` sobe 1 e `j` desce 1, então eles se aproximam 2 unidades por iteração. Após 5 iterações, `i = 5` e `j = 5`, e `5 < 5` é falso.

**b)** Saída (a soma é sempre 10, pois o que `i` ganha `j` perde):

```
i = 0, j = 10 | soma = 10
i = 1, j = 9 | soma = 10
i = 2, j = 8 | soma = 10
i = 3, j = 7 | soma = 10
i = 4, j = 6 | soma = 10
```

**c)** Com `while`, a inicialização vai para antes do laço e o incremento para o fim do corpo ([`exercicio05.c`](exercicio05.c)):

```c
i = 0;
j = 10;
while (i < j) {
    printf("i = %d, j = %d | soma = %d\n", i, j, i + j);
    i++;
    j--;
}
```

---

## Questão 06 — Laço sem corpo e incremento pós-fixado

```c
int x = 0;
while (x++ < 5);
printf("Valor final de x = %d\n", x);
```

**a)** Será impresso **`Valor final de x = 6`**.

**b)** `x++` entrega o valor **antigo** de `x` para a comparação e **só depois** incrementa. Portanto, a cada teste, compara-se o valor atual e `x` cresce 1, **mesmo quando o teste falha**:

| Teste | Comparação feita | Resultado | `x` após o `++` |
|-------|------------------|-----------|-----------------|
| 1 | 0 < 5 | verdadeiro | 1 |
| 2 | 1 < 5 | verdadeiro | 2 |
| 3 | 2 < 5 | verdadeiro | 3 |
| 4 | 3 < 5 | verdadeiro | 4 |
| 5 | 4 < 5 | verdadeiro | 5 |
| 6 | 5 < 5 | **falso** (sai do laço) | **6** |

O corpo (vazio) executa 5 vezes, mas o teste é avaliado 6 vezes, e o sexto também incrementa.

**c)** Versão explícita com o mesmo resultado ([`exercicio06.c`](exercicio06.c)):

```c
int x = 0;
while (x < 5) {
    x++;        /* x vai de 0 ate 5 */
}
x++;            /* o ultimo teste (5 < 5) tambem incrementava -> 6 */
printf("Valor final de x = %d\n", x);
```

---

## Questões práticas (Parte II)

| Questão | Tema | Arquivo |
|---------|------|---------|
| 07 | Contagem 0–100 com `for`, `while` e `do-while` (três funções) | [`exercicio07.c`](exercicio07.c) |
| 08 | Validação de nota 0.0–10.0 com `do-while` | [`exercicio08.c`](exercicio08.c) |
| 09 | Acumulador de reais com sentinela negativa | [`exercicio09.c`](exercicio09.c) |
| 10 | 100 múltiplos de 3, 10 por linha | [`exercicio10.c`](exercicio10.c) |
| 11 | Intervalo [A, B] crescente ou decrescente | [`exercicio11.c`](exercicio11.c) |
| 12 | Tabela Celsius / Fahrenheit / Kelvin de 5 em 5 | [`exercicio12.c`](exercicio12.c) |
| 13 | Fatorial com `long long int` e tratamento de negativo | [`exercicio13.c`](exercicio13.c) |
| 14 | Quadrados de 1 a 100 e soma (338350) | [`exercicio14.c`](exercicio14.c) |
| 15 | Múltiplos de 3 **e** de 5 até NUM | [`exercicio15.c`](exercicio15.c) |
| 16 | Senha 2026 com 3 tentativas | [`exercicio16.c`](exercicio16.c) |
| 17 | Estatísticas da turma com sentinela −1.0 | [`exercicio17.c`](exercicio17.c) |
| 18 | Inversão de dígitos com `%` e `/` | [`exercicio18.c`](exercicio18.c) |
| 19 | N-ésimo termo de Fibonacci e listagem | [`exercicio19.c`](exercicio19.c) |
| 20 | Tabela ASCII 32–126 com `%X` | [`exercicio20.c`](exercicio20.c) |
| 21 | Jogo de adivinhar a letra com `rand()` | [`exercicio21.c`](exercicio21.c) |
| 22 | Triângulo de Floyd | [`exercicio22.c`](exercicio22.c) |
| 23 | Quadrado vazado de lado L (3–20) | [`exercicio23.c`](exercicio23.c) |
| 24 | Padrão em X com diagonais (N ímpar, 3–19) | [`exercicio24.c`](exercicio24.c) |
| 25 | Teste de primalidade contando divisores | [`exercicio25.c`](exercicio25.c) |
| 26 | Primos em [A, B] e soma | [`exercicio26.c`](exercicio26.c) |
| 27 | Caixa eletrônico (cédulas de 100, 50, 20, 10, 5 e 2) | [`exercicio27.c`](exercicio27.c) |
| 28 | Folha de pagamento com menu `do-while` + `switch` | [`exercicio28.c`](exercicio28.c) |

### Compilação

```bash
gcc -Wall -o exercicio07 exercicio07.c
./exercicio07
```

Nenhuma questão desta lista precisa de `-lm`.

> **Observações:**
> - Na questão 13, `long long int` guarda com exatidão até 20!; o programa avisa quando N passa de 20.
> - Na questão 26, o teste de primalidade vai só até a raiz quadrada do número (`i * i <= numero`), o que reduz muito o trabalho em intervalos grandes.
> - Na questão 27, valores como 1 ou 3 não podem ser compostos só com as cédulas disponíveis; o programa informa o resto que ficou sem pagar.
> - A questão 28 trata entrada não numérica no menu (descarta a linha e repete) para o laço não ficar infinito.

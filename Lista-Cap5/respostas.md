# Lista de Exercícios – Capítulo 5: Funções

Respostas das questões teóricas (Parte I). As questões práticas estão nos arquivos `exercicio07.c` a `exercicio28.c`.

---

## Questão 01 – Anatomia de uma função e o papel do protótipo

**a)**
- **Protótipo:** `float celsius(float);` — fica antes da `main()` e declara ao compilador que existe uma função chamada `celsius`, que recebe um `float` e devolve um `float`.
- **Chamada:** `c = celsius(f);` — dentro da `main()`, transfere o controle para a função, passando o valor de `f` como argumento; o valor devolvido é atribuído a `c`.
- **Definição:** `float celsius(float fahr) { return (fahr - 32.0) * 5.0 / 9.0; }` — é o corpo da função, onde o cálculo realmente acontece.

**b)** O protótipo permite que o compilador conheça o tipo de retorno, a quantidade e os tipos dos parâmetros *antes* de encontrar a chamada. Assim ele consegue verificar se a chamada está correta (número e tipo dos argumentos) e fazer as conversões necessárias. Se o protótipo fosse omitido e a função fosse definida depois da `main()`, o compilador encontraria a chamada sem saber nada sobre a função: em compiladores antigos ele assumiria que ela retorna `int` e não verificaria os parâmetros (o `float` retornado seria interpretado errado); nos compiladores modernos isso gera aviso ou erro de "declaração implícita de função".

**c)** O tipo da função é `float`. O tipo de uma função é o tipo do valor que ela devolve com `return`, porque é esse valor que "ocupa o lugar" da chamada dentro de uma expressão (`c = celsius(f)`). Os parâmetros são apenas dados de entrada; uma mesma função pode receber parâmetros de vários tipos, mas só devolve um valor de um tipo.

---

## Questão 02 – O comando return e suas limitações

**a)** Uma função em C devolve **no máximo um valor** pelo `return`. O programador queria devolver a soma e a média ao mesmo tempo. Porém `return soma, media;` usa o **operador vírgula**: as duas expressões são avaliadas, mas o resultado da expressão é apenas o último valor (`media`). A soma é descartada.

**b)** Em uma função `void`, `return;` encerra a função imediatamente e devolve o controle a quem chamou, sem devolver valor. Em `imprime_mensagem()`, se `erro < 0`, a mensagem "Erro invalido" é impressa e o segundo `printf` não é executado. Ele **não é obrigatório** no final de uma função `void`: ao chegar à chave de fechamento `}` a função retorna automaticamente. Ele só é útil para sair antes do fim.

**c)**
```c
int calcular_media(int a, int b, int c) {
    return (a + b + c) / 3;
}

int calcular_soma(int a, int b, int c) {
    return a + b + c;
}
```
Como o `return` devolve só um valor, cada resultado diferente precisa da sua própria função (ou do uso de ponteiros/structs, que ainda não fazem parte do conteúdo).

---

## Questão 03 – Funções void, parâmetros e assinaturas

**a)**
| Protótipo | Parâmetros de entrada | Valor de retorno |
|---|---|---|
| `void exibe_mensagem(char* msg);` | Sim (uma string) | Não (`void`) |
| `int obter_codigo(void);` | Não | Sim (`int`) |
| `void limpar_tela(void);` | Não | Não |

**b)** Uma função com retorno produz um valor que pode ser usado em uma expressão (atribuído, comparado, impresso). Um procedimento (`void`) apenas executa uma ação e não produz valor. Exemplos: calcular a área de um círculo → função que retorna `float`; exibir um menu na tela → procedimento `void`.

**c)** Não é válida. `limpar_tela()` é do tipo `void`, ou seja, não devolve nenhum valor; não há o que atribuir a `x`. O compilador acusa erro ("void value not ignored as it ought to be").

---

## Questão 04 – Recursão: caso base, passo recursivo e pilha de execução

**a)** Caso base: `n == 0`, que retorna `1`. Passo recursivo: `n * fatorial(n - 1)`. Sem o caso base, a função chamaria a si mesma indefinidamente (`fatorial(-1)`, `fatorial(-2)`, ...), nunca parando.

**b)** Rastreamento de `fatorial(4)`:

Empilhamento (chamadas):
```
fatorial(4) -> 4 * fatorial(3)
  fatorial(3) -> 3 * fatorial(2)
    fatorial(2) -> 2 * fatorial(1)
      fatorial(1) -> 1 * fatorial(0)
        fatorial(0) -> caso base, retorna 1
```
Desempilhamento (retornos):
```
        fatorial(0) retorna 1
      fatorial(1) retorna 1 * 1 = 1
    fatorial(2) retorna 2 * 1 = 2
  fatorial(3) retorna 3 * 2 = 6
fatorial(4) retorna 4 * 6 = 24
```
Resultado: **24**.

**c)** A cada chamada, um novo bloco (registro de ativação) é colocado na pilha de execução, guardando o parâmetro `n`, as variáveis locais e o endereço de retorno. Esse bloco só é liberado quando a chamada termina. Sem caso base, os blocos se acumulam sem parar até a pilha (memória limitada) se esgotar, causando **estouro de pilha** (*stack overflow*) e o encerramento do programa (ex.: *segmentation fault*).

---

## Questão 05 – #define, constantes e macros com argumentos

**a)**
- `SQR(2+3)` vira `((2+3)*(2+3))` → **25**.
- `DOBRO(2+3)` vira `2+3*2` → pela precedência, `2 + 6` → **8** (e não 10).

O pré-processador faz substituição de texto, sem calcular nada antes. `SQR` tem parênteses de proteção em volta de cada `x` e da expressão inteira, então o argumento é tratado como um bloco. `DOBRO` não tem, e a multiplicação acaba sendo aplicada só ao `3`.

**b)** `#define` é uma diretiva do pré-processador, não um comando C; ela substitui o texto até o fim da linha. Se houvesse `;`, ele seria copiado em toda substituição e geraria erros (ex.: `x = PI; * 2`). Os identificadores em maiúsculas são uma convenção para diferenciar visualmente constantes e macros de variáveis e funções.

**c)** Em `#define PRN (n) printf("%d", n)` há um espaço entre o nome e o parêntese; o pré-processador entende que `PRN` é uma constante simples cujo texto é `(n) printf("%d", n)`, e não uma macro com argumento. O correto é `#define PRN(n) printf("%d", n)`, sem espaço. Diferença entre macro e função: a macro é expandida pelo pré-processador (copiada no código a cada uso, sem verificação de tipos e sem custo de chamada), enquanto a função é compilada uma única vez, verifica os tipos dos parâmetros e é chamada em tempo de execução.

---

## Questão 06 – #include, #undef e compilação condicional

**a)** `#include <stdio.h>` procura o arquivo nos diretórios padrão do compilador — usado para bibliotecas do sistema. `#include "areas.h"` procura primeiro no diretório do próprio projeto (do arquivo fonte) e depois nos padrões — usado para cabeçalhos criados pelo programador.

**b)** `#undef SOMA` remove a definição da macro `SOMA`; a partir daquela linha, `SOMA` deixa de existir e usá-la gera erro. A forma `#undef SOMA(x,y)` está incorreta porque o `#undef` recebe apenas o **nome** da macro, sem a lista de parâmetros.

**c)** Será impresso **"Modo normal"**. A decisão é tomada no **pré-processamento**, antes da compilação: como `DEBUG` não está definido, o pré-processador descarta o bloco do `#ifdef` e mantém só o do `#else`. As diretivas (`#ifdef`, `#else`, `#endif`, `#define` etc.) são consumidas pelo pré-processador e não geram código de máquina, por isso não existem no executável final — o compilador só recebe o código que sobrou.

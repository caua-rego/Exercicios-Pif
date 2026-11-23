# Simulado – 2ª Unidade (Capítulos 4, 5, 7 e 8)

Respostas das questões de múltipla escolha. As questões de código estão em `exercicioNN.c` (03, 04, 07, 08, 09, 12, 13, 14, 15, 18, 19 e 20).

| Questão | Resposta |
|---|---|
| 01 | **b** |
| 02 | **c** |
| 05 | **d** |
| 06 | **a** |
| 10 | **c** |
| 11 | **b** |
| 16 | **c** |
| 17 | **d** |

## Justificativas

**Questão 01 – b) Y e, em seguida, Z.**
O `else` pertence ao `if` mais próximo sem `else`, ou seja, ao `if (b > 5)`. Como `a > 5` é verdadeiro e `b > 5` é falso (b = 3), imprime `Y`. O `printf("Z\n")` está fora dos `if` e sempre executa.

**Questão 02 – c) 5.**
`op = 2` entra no `case 2` (`t = 2`); sem `break` ocorre *fall-through* para o `case 3` (`t = 5`), onde há `break`.

**Questão 05 – d) 3 7.**
A passagem é por valor: `troca()` recebe cópias de `x` e `y` e troca apenas as cópias locais `a` e `b`. As variáveis da `main()` não mudam.

**Questão 06 – a) 10.**
`f(4) = 4 + f(3) = 4 + 3 + f(2) = 4 + 3 + 2 + f(1) = 4 + 3 + 2 + 1 = 10`.

**Questão 10 – c) 15.**
`m[0][2] = 3`, `m[1][1] = 5`, `m[2][0] = 7` → 3 + 5 + 7 = 15 (diagonal secundária).

**Questão 11 – b) 9 PROVA2026.**
`strcat` concatena "2026" ao final de "PROVA", resultando em "PROVA2026". `strlen` conta os caracteres até o `'\0'`, sem contá-lo: 9.

**Questão 16 – c) 1 9.**
`b = a` copia todos os membros de `a` para `b` (atribuição de estruturas é permitida). Depois só `b.x` é alterado; `a.x` continua 1.

**Questão 17 – d) 8.**
Em uma união todos os membros ocupam a mesma área de memória; o tamanho é o do maior membro (`char[8]` e `double`, ambos com 8 bytes), já alinhado para `double`.

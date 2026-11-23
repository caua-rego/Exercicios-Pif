/* Questão 21 - Soma de tempos */
#include <stdio.h>

typedef struct {
    int horas, minutos, segundos;
} Tempo;

Tempo somaTempo(Tempo a, Tempo b);
Tempo leTempo(int numero);

int main(void)
{
    Tempo t1 = leTempo(1), t2 = leTempo(2), total;

    total = somaTempo(t1, t2);
    printf("Soma: %02d:%02d:%02d\n", total.horas, total.minutos, total.segundos);

    return 0;
}

Tempo leTempo(int numero)
{
    Tempo t;
    printf("Tempo %d (horas minutos segundos): ", numero);
    scanf("%d %d %d", &t.horas, &t.minutos, &t.segundos);
    return t;
}

/* soma campo a campo e normaliza: 60 s = 1 min, 60 min = 1 h */
Tempo somaTempo(Tempo a, Tempo b)
{
    Tempo r;
    r.segundos = a.segundos + b.segundos;
    r.minutos = a.minutos + b.minutos + r.segundos / 60;
    r.segundos %= 60;
    r.horas = a.horas + b.horas + r.minutos / 60;
    r.minutos %= 60;
    return r;
}

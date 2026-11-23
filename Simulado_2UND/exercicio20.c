/* Questão 20 - Duracao de sessoes (estruturas por valor) (Cap. 8) */
#include <stdio.h>

typedef struct {
    int hora;
    int minuto;
} Horario;

int duracao(Horario ini, Horario fim);

int main(void)
{
    Horario inicio, fim;
    int minutos;

    printf("Horario de inicio (hh mm): ");
    scanf("%d %d", &inicio.hora, &inicio.minuto);
    printf("Horario de fim (hh mm): ");
    scanf("%d %d", &fim.hora, &fim.minuto);

    minutos = duracao(inicio, fim);
    if (minutos < 0) {
        printf("O horario de fim deve ser depois do inicio.\n");
        return 1;
    }

    printf("Duracao: %d minutos (%dh%02dmin)\n", minutos, minutos / 60, minutos % 60);

    return 0;
}

/* Recebe as estruturas por valor e devolve a diferenca em minutos */
int duracao(Horario ini, Horario fim)
{
    return (fim.hora * 60 + fim.minuto) - (ini.hora * 60 + ini.minuto);
}

/* Questão 23 - Estacionamento */
#include <stdio.h>

#define TARIFA_HORA 5.00f

typedef struct {
    int hora, minuto;
} Hora;

typedef struct {
    char placa[10];
    Hora entrada, saida;
} Veiculo;

int permanenciaMinutos(Veiculo v);

int main(void)
{
    Veiculo v;
    int minutos, horasCobradas;

    printf("Placa: ");
    scanf("%9s", v.placa);
    printf("Entrada (hh mm): ");
    scanf("%d %d", &v.entrada.hora, &v.entrada.minuto);
    printf("Saida (hh mm): ");
    scanf("%d %d", &v.saida.hora, &v.saida.minuto);

    minutos = permanenciaMinutos(v);
    if (minutos <= 0) {
        printf("Horario de saida invalido.\n");
        return 1;
    }

    /* fracao de hora e cobrada como hora cheia */
    horasCobradas = minutos / 60;
    if (minutos % 60 != 0)
        horasCobradas++;

    printf("Veiculo %s: %dh%02dmin de permanencia\n", v.placa, minutos / 60, minutos % 60);
    printf("Horas cobradas: %d\n", horasCobradas);
    printf("Valor a pagar: R$ %.2f\n", horasCobradas * TARIFA_HORA);

    return 0;
}

int permanenciaMinutos(Veiculo v)
{
    return (v.saida.hora * 60 + v.saida.minuto) - (v.entrada.hora * 60 + v.entrada.minuto);
}

/* Questão 09 - Indice de massa corporal com funcoes (Cap. 5) */
#include <stdio.h>

float calculaIMC(float peso, float altura);
void classificaIMC(float imc);

int main(void)
{
    float peso, altura, imc;

    printf("Peso (kg): ");
    scanf("%f", &peso);
    printf("Altura (m): ");
    scanf("%f", &altura);

    if (peso <= 0 || altura <= 0) {
        printf("Peso e altura devem ser positivos.\n");
        return 1;
    }

    imc = calculaIMC(peso, altura);
    printf("IMC = %.2f\n", imc);
    classificaIMC(imc);

    return 0;
}

float calculaIMC(float peso, float altura)
{
    return peso / (altura * altura);
}

void classificaIMC(float imc)
{
    if (imc < 18.5f)
        printf("Abaixo do peso\n");
    else if (imc < 25.0f)
        printf("Peso normal\n");
    else if (imc < 30.0f)
        printf("Sobrepeso\n");
    else
        printf("Obesidade\n");
}

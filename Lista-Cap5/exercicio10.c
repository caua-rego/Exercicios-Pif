/* Questão 10 - Area da esfera com #define */
#include <stdio.h>

#define PI 3.14159

float area(float r);

int main(void)
{
    float raio;

    printf("Raio da esfera: ");
    scanf("%f", &raio);

    if (raio < 0) {
        printf("O raio nao pode ser negativo.\n");
        return 1;
    }

    printf("Area da superficie = %.2f\n", area(raio));

    return 0;
}

/* Area da superficie da esfera: 4 * PI * r * r */
float area(float r)
{
    return 4 * PI * r * r;
}

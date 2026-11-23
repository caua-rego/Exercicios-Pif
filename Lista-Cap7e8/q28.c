/* Questão 28 - Mini biblioteca (questao avancada) */
#include <stdio.h>
#include <string.h>

#define MAX_LIVROS 10
#define TAM_TEXTO 60

typedef struct {
    char titulo[TAM_TEXTO];
    char autor[TAM_TEXTO];
    int ano;
    int disponivel;   /* 1 = disponivel, 0 = emprestado */
} Livro;

void exibeMenu(void);
void leLinha(char destino[], int tamanho);
int cadastrarLivro(Livro acervo[], int total);
void listarLivros(Livro acervo[], int total);
int buscarPorTitulo(Livro acervo[], int total, char titulo[]);
void buscarLivro(Livro acervo[], int total);
void emprestarLivro(Livro acervo[], int total);
void devolverLivro(Livro acervo[], int total);

int main(void)
{
    Livro acervo[MAX_LIVROS];
    int total = 0, opcao;

    do {
        exibeMenu();
        if (scanf("%d", &opcao) != 1) {
            opcao = -1;
        }
        while (getchar() != '\n');   /* limpa o resto da linha */

        switch (opcao) {
        case 1: total = cadastrarLivro(acervo, total); break;
        case 2: listarLivros(acervo, total); break;
        case 3: buscarLivro(acervo, total); break;
        case 4: emprestarLivro(acervo, total); break;
        case 5: devolverLivro(acervo, total); break;
        case 0: printf("Encerrando...\n"); break;
        default: printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}

void exibeMenu(void)
{
    printf("\n===== MINI BIBLIOTECA =====\n");
    printf("1 - Cadastrar livro\n");
    printf("2 - Listar todos\n");
    printf("3 - Buscar por titulo\n");
    printf("4 - Emprestar\n");
    printf("5 - Devolver\n");
    printf("0 - Sair\n");
    printf("Opcao: ");
}

void leLinha(char destino[], int tamanho)
{
    fgets(destino, tamanho, stdin);
    destino[strcspn(destino, "\n")] = '\0';
}

/* devolve o novo total de livros */
int cadastrarLivro(Livro acervo[], int total)
{
    if (total == MAX_LIVROS) {
        printf("Acervo cheio! Limite de %d livros.\n", MAX_LIVROS);
        return total;
    }

    printf("Titulo: ");
    leLinha(acervo[total].titulo, TAM_TEXTO);
    printf("Autor: ");
    leLinha(acervo[total].autor, TAM_TEXTO);
    printf("Ano: ");
    scanf("%d", &acervo[total].ano);
    while (getchar() != '\n');
    acervo[total].disponivel = 1;

    printf("Livro cadastrado!\n");
    return total + 1;
}

void listarLivros(Livro acervo[], int total)
{
    int i;
    if (total == 0) {
        printf("Nenhum livro cadastrado.\n");
        return;
    }
    for (i = 0; i < total; i++)
        printf("%d. %s - %s (%d) [%s]\n", i + 1, acervo[i].titulo, acervo[i].autor,
               acervo[i].ano, acervo[i].disponivel ? "disponivel" : "emprestado");
}

/* devolve o indice do livro com o titulo exato, ou -1 */
int buscarPorTitulo(Livro acervo[], int total, char titulo[])
{
    int i;
    for (i = 0; i < total; i++)
        if (strcmp(acervo[i].titulo, titulo) == 0)
            return i;
    return -1;
}

void buscarLivro(Livro acervo[], int total)
{
    char titulo[TAM_TEXTO];
    int indice;

    printf("Titulo a buscar: ");
    leLinha(titulo, TAM_TEXTO);
    indice = buscarPorTitulo(acervo, total, titulo);

    if (indice == -1)
        printf("Livro nao encontrado.\n");
    else
        printf("Encontrado: %s - %s (%d) [%s]\n", acervo[indice].titulo, acervo[indice].autor,
               acervo[indice].ano, acervo[indice].disponivel ? "disponivel" : "emprestado");
}

void emprestarLivro(Livro acervo[], int total)
{
    char titulo[TAM_TEXTO];
    int indice;

    printf("Titulo para emprestar: ");
    leLinha(titulo, TAM_TEXTO);
    indice = buscarPorTitulo(acervo, total, titulo);

    if (indice == -1)
        printf("Livro nao encontrado.\n");
    else if (!acervo[indice].disponivel)
        printf("Este livro ja esta emprestado.\n");
    else {
        acervo[indice].disponivel = 0;
        printf("Emprestimo registrado.\n");
    }
}

void devolverLivro(Livro acervo[], int total)
{
    char titulo[TAM_TEXTO];
    int indice;

    printf("Titulo para devolver: ");
    leLinha(titulo, TAM_TEXTO);
    indice = buscarPorTitulo(acervo, total, titulo);

    if (indice == -1)
        printf("Livro nao encontrado.\n");
    else if (acervo[indice].disponivel)
        printf("Este livro nao estava emprestado.\n");
    else {
        acervo[indice].disponivel = 1;
        printf("Devolucao registrada.\n");
    }
}

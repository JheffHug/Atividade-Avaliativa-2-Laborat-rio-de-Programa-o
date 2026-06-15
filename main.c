/******************************************************************************

Grupo:

Jheferson Hugo Farias da Silva - Matrícula: 2023046579
Allexis Ryan Campos Silva - Matrícula: 20240015408

*******************************************************************************/
#include <stdio.h>
#include <string.h>

#define MAX_REGISTROS 50
#define MAX_LETRAS 30

char banco_dados[MAX_REGISTROS][MAX_LETRAS];

// Procura um nome e retorna o índice
int buscarNome(char nome[]) {
    int i;

    for(i = 0; i < MAX_REGISTROS; i++) {
        if(strcmp(banco_dados[i], nome) == 0) {
            return i;
        }
    }

    return -1;
}

// Incluir nome
void incluir() {
    char nome[MAX_LETRAS];
    int i;

    printf("Digite o nome: ");
    scanf(" %[^\n]", nome);

    // Verifica duplicidade
    if(buscarNome(nome) != -1) {
        printf("Erro! Nome ja existe.\n");
        return;
    }

    // Procura posição vazia
    for(i = 0; i < MAX_REGISTROS; i++) {
        if(banco_dados[i][0] == '\0') {
            strcpy(banco_dados[i], nome);
            printf("Nome cadastrado com sucesso!\n");
            return;
        }
    }

    printf("Banco de dados cheio!\n");
}

// Buscar nome
void buscar() {
    char nome[MAX_LETRAS];
    int pos;

    printf("Digite o nome para buscar: ");
    scanf(" %[^\n]", nome);

    pos = buscarNome(nome);

    if(pos != -1) {
        printf("Nome encontrado na linha %d\n", pos);
    }
    else {
        printf("Nome nao encontrado.\n");
    }
}

// Modificar nome
void modificar() {
    char nomeAntigo[MAX_LETRAS];
    char novoNome[MAX_LETRAS];
    int pos;

    printf("Digite o nome que deseja alterar: ");
    scanf(" %[^\n]", nomeAntigo);

    pos = buscarNome(nomeAntigo);

    if(pos == -1) {
        printf("Nome nao encontrado.\n");
        return;
    }

    printf("Digite o novo nome: ");
    scanf(" %[^\n]", novoNome);

    // Verifica duplicidade
    if(buscarNome(novoNome) != -1) {
        printf("Erro! Esse nome ja existe.\n");
        return;
    }

    strcpy(banco_dados[pos], novoNome);

    printf("Nome alterado com sucesso!\n");
}

// Apagar nome
void apagar() {
    char nome[MAX_LETRAS];
    int pos;

    printf("Digite o nome para apagar: ");
    scanf(" %[^\n]", nome);

    pos = buscarNome(nome);

    if(pos == -1) {
        printf("Nome nao encontrado.\n");
        return;
    }

    banco_dados[pos][0] = '\0';

    printf("Nome removido com sucesso!\n");
}

// Listar todos
void listar() {
    int i;
    int encontrou = 0;

    printf("\n===== LISTA DE NOMES =====\n");

    for(i = 0; i < MAX_REGISTROS; i++) {
        if(banco_dados[i][0] != '\0') {
            printf("[%d] %s\n", i, banco_dados[i]);
            encontrou = 1;
        }
    }

    if(!encontrou) {
        printf("Nenhum nome cadastrado.\n");
    }
}

int main() {

    int opcao;

    do {
        printf("\n===== MENU =====\n");
        printf("1 - Incluir\n");
        printf("2 - Buscar\n");
        printf("3 - Modificar\n");
        printf("4 - Apagar\n");
        printf("5 - Listar Todos\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                incluir();
                break;

            case 2:
                buscar();
                break;

            case 3:
                modificar();
                break;

            case 4:
                apagar();
                break;

            case 5:
                listar();
                break;

            case 0:
                printf("Encerrando...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while(opcao != 0);

    return 0;
}

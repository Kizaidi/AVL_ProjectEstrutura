#include <stdio.h>
#include <stdlib.h>
#include "assinaturas.h"
#include "funcoes.h"

void exibirMenu() {
    printf("\nMenu:\n");
    printf("1. Inserir aluno\n");
    printf("2. Buscar aluno\n");
    printf("3. Imprimir árvore em ordem\n");
    printf("4. Calcular distância entre dois nós\n");
    printf("0. Sair\n");
}

int main() {
    AVLNode* raiz = NULL;
    int opcao;

    do {
        exibirMenu();
        printf("\nDigite a opção desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                Aluno novoAluno;
                printf("\nDigite o número do aluno: ");
                scanf("%d", &novoAluno.numero);
                printf("Digite o nome do aluno: ");
                scanf("%s", novoAluno.nome);
                printf("Digite a data de nascimento do aluno (DD/MM/AAAA): ");
                scanf("%s", novoAluno.data_nascimento);
                raiz = inserir(raiz, novoAluno);
                printf("Aluno inserido com sucesso!\n");
                break;
            }
            case 2: {
                int numeroBusca;
                printf("\nDigite o número do aluno a ser buscado: ");
                scanf("%d", &numeroBusca);
                AVLNode* resultadoBusca = buscar(raiz, numeroBusca);
                if (resultadoBusca != NULL) {
                    printf("Aluno encontrado: %s\n", resultadoBusca->aluno.nome);
                } else {
                    printf("Aluno não encontrado.\n");
                }
                break;
            }
            case 3: {
                printf("\nImpressão em ordem:\n");
                imprimirEmOrdem(raiz);
                break;
            }
            case 4: {
                int numero1, numero2;
                printf("\nDigite o número do primeiro aluno: ");
                scanf("%d", &numero1);
                printf("Digite o número do segundo aluno: ");
                scanf("%d", &numero2);
                int distancia = distanciaEntreNos(raiz, numero1, numero2);
                if (distancia != -1) {
                    printf("A distância entre os alunos é: %d\n", distancia);
                } else {
                    printf("Pelo menos um dos alunos não foi encontrado na árvore.\n");
                }
                break;
            }
            case 0: {
                printf("\nEncerrando o programa...\n");
                break;
            }
            default:
                printf("\nOpção inválida! Por favor, escolha uma opção válida.\n");
        }
    } while (opcao != 0);

    return 0;
}

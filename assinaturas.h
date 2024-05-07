#ifndef ASSINATURAS_H
#define ASSINATURAS_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int numero;
    char nome[50];
    char data_nascimento[11]; // Formato: DD/MM/AAAA
} Aluno;

typedef struct AVLNode {
    Aluno aluno;
    struct AVLNode *esquerda;
    struct AVLNode *direita;
    int altura;
} AVLNode;

AVLNode* criarNo(Aluno aluno);
int altura(AVLNode* no);
int maximo(int a, int b);
AVLNode* rotacaoDireita(AVLNode* y);
AVLNode* rotacaoEsquerda(AVLNode* x);
int fatorBalanceamento(AVLNode* no);
AVLNode* inserir(AVLNode* raiz, Aluno aluno);
AVLNode* buscar(AVLNode* raiz, int numero);
void imprimirEmOrdem(AVLNode* raiz);
int distanciaEntreNos(AVLNode* raiz, int numero1, int numero2); // Assinatura adicionada
AVLNode* encontrarLCA(AVLNode* raiz, int numero1, int numero2); // Adicionado protótipo

// Declaração da função distanciaAteRaiz
int distanciaAteRaiz(AVLNode* raiz, int numero, int distancia);

#endif

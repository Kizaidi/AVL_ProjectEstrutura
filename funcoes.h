#ifndef FUNCOES_H
#define FUNCOES_H

#include "assinaturas.h"

AVLNode* criarNo(Aluno aluno) {
    AVLNode* novoNo = (AVLNode*)malloc(sizeof(AVLNode));
    novoNo->aluno = aluno;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    novoNo->altura = 1;
    return novoNo;
}

int altura(AVLNode* no) {
    if (no == NULL) {
        return 0;
    }
    return no->altura;
}

int maximo(int a, int b) {
    return (a > b) ? a : b;
}

AVLNode* rotacaoDireita(AVLNode* y) {
    AVLNode* x = y->esquerda;
    AVLNode* T2 = x->direita;

    x->direita = y;
    y->esquerda = T2;

    y->altura = maximo(altura(y->esquerda), altura(y->direita)) + 1;
    x->altura = maximo(altura(x->esquerda), altura(x->direita)) + 1;

    return x;
}

AVLNode* rotacaoEsquerda(AVLNode* x) {
    AVLNode* y = x->direita;
    AVLNode* T2 = y->esquerda;

    y->esquerda = x;
    x->direita = T2;

    x->altura = maximo(altura(x->esquerda), altura(x->direita)) + 1;
    y->altura = maximo(altura(y->esquerda), altura(y->direita)) + 1;

    return y;
}

int fatorBalanceamento(AVLNode* no) {
    if (no == NULL) {
        return 0;
    }
    return altura(no->esquerda) - altura(no->direita);
}

AVLNode* inserir(AVLNode* raiz, Aluno aluno) {
    if (raiz == NULL) {
        return criarNo(aluno);
    }

    if (aluno.numero < raiz->aluno.numero) {
        raiz->esquerda = inserir(raiz->esquerda, aluno);
    } else if (aluno.numero > raiz->aluno.numero) {
        raiz->direita = inserir(raiz->direita, aluno);
    } else {
        return raiz;
    }

    raiz->altura = 1 + maximo(altura(raiz->esquerda), altura(raiz->direita));

    int balanceamento = fatorBalanceamento(raiz);

    if (balanceamento > 1 && aluno.numero < raiz->esquerda->aluno.numero) {
        return rotacaoDireita(raiz);
    }

    if (balanceamento < -1 && aluno.numero > raiz->direita->aluno.numero) {
        return rotacaoEsquerda(raiz);
    }

    if (balanceamento > 1 && aluno.numero > raiz->esquerda->aluno.numero) {
        raiz->esquerda = rotacaoEsquerda(raiz->esquerda);
        return rotacaoDireita(raiz);
    }

    if (balanceamento < -1 && aluno.numero < raiz->direita->aluno.numero) {
        raiz->direita = rotacaoDireita(raiz->direita);
        return rotacaoEsquerda(raiz);
    }

    return raiz;
}

AVLNode* buscar(AVLNode* raiz, int numero) {
    if (raiz == NULL || raiz->aluno.numero == numero) {
        return raiz;
    }

    if (numero < raiz->aluno.numero) {
        return buscar(raiz->esquerda, numero);
    } else {
        return buscar(raiz->direita, numero);
    }
}

void imprimirEmOrdem(AVLNode* raiz) {
    if (raiz != NULL) {
        imprimirEmOrdem(raiz->esquerda);
        printf("Número: %d, Nome: %s, Data de Nascimento: %s\n", raiz->aluno.numero, raiz->aluno.nome, raiz->aluno.data_nascimento);
        imprimirEmOrdem(raiz->direita);
    }
}

int distanciaEntreNos(AVLNode* raiz, int numero1, int numero2) {
    AVLNode* no1 = buscar(raiz, numero1);
    AVLNode* no2 = buscar(raiz, numero2);

    if (no1 == NULL || no2 == NULL) {
        return -1;
    }

    AVLNode* lca = encontrarLCA(raiz, no1->aluno.numero, no2->aluno.numero);

    int distancia1 = distanciaAteRaiz(lca, no1->aluno.numero, 0);
    int distancia2 = distanciaAteRaiz(lca, no2->aluno.numero, 0);

    return distancia1 + distancia2;
}

AVLNode* encontrarLCA(AVLNode* raiz, int numero1, int numero2) {
    if (raiz == NULL) {
        return NULL;
    }

    if ((numero1 < raiz->aluno.numero && numero2 > raiz->aluno.numero) ||
        (numero1 > raiz->aluno.numero && numero2 < raiz->aluno.numero)) {
        return raiz;
    }

    if (numero1 < raiz->aluno.numero && numero2 < raiz->aluno.numero) {
        return encontrarLCA(raiz->esquerda, numero1, numero2);
    }

    if (numero1 > raiz->aluno.numero && numero2 > raiz->aluno.numero) {
        return encontrarLCA(raiz->direita, numero1, numero2);
    }

    return raiz;
}

int distanciaAteRaiz(AVLNode* raiz, int numero, int distancia) {
    if (raiz == NULL) {
        return -1;
    }

    if (raiz->aluno.numero == numero) {
        return distancia;
    }

    int distanciaEsquerda = distanciaAteRaiz(raiz->esquerda, numero, distancia + 1);
    int distanciaDireita = distanciaAteRaiz(raiz->direita, numero, distancia + 1);

    return (distanciaEsquerda != -1) ? distanciaEsquerda : distanciaDireita;
}

#endif

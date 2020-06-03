//2. Escreva uma função que receba como parâmetro duas pilhas e verifique de elas são iguais. Duas pilhas são iguais se possuem os mesmos elementos, na mesma ordem.

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>


typedef struct nodo_a {
	int dado;
	struct nodo_a *prox;

} nodo_b;

typedef nodo_b *pNodo;
typedef nodo_b *pPilha;

void push(pPilha *p, int x) {
	pNodo no;
	no = (pNodo)malloc(sizeof(nodo_b));
	if (no != NULL) {
		no->dado = x;
		no->prox = *p;
		*p = no;
	}
}

int pop(pPilha *p) {
	pNodo no;
	int x = 0;
	no = *p;
	x = (*p)->dado;
	*p = (*p)->prox;
	free(no);
	return x;
}

int pilha_vazia(pPilha *p) {
	return (*p == NULL ? 1 : 0);
}

void mostra_pilha(pPilha *p) {
  pPilha ponteiro;
  ponteiro = *p;
  
  for( int i=0 ; (ponteiro != NULL) ;i++) {
    printf("Posicao %2i valor=%2i\n",i,(*ponteiro).dado);
    ponteiro = (*ponteiro).prox;
  }
  printf("Fim da pilha\n\n");
  
}

void pilhasIguais(pNodo N1, pNodo N2) {
	double faixa = 1;

	if ((N1 == NULL) || (N2 == NULL)) {
		printf(" Um das Pilhas Está vazia ");
	} else {
		while ((N1 != NULL) && (N2 != NULL) && (faixa)) {
			if (N1->dado != N2->dado) {
				faixa = 0;
			} else {
				N1 = N1->prox;
				N2 = N2->prox;
			}
		}
	}
	if ((N1 == NULL) && (N2 == NULL) && (faixa)) {
		printf("Pilhas Iguais\n--------------\n");
	} else {
		printf("Pilhas Diferentes\n--------------\n");
	  
	}
}

void main() {
	pPilha P1 = NULL, P2 = NULL;

	/* cria pilha um */
	push(&P1, 8);
	push(&P1, 23);
	push(&P1, 3);
	
	mostra_pilha(&P1);
	

	push(&P2, 8);
	push(&P2, 23);
	push(&P2, 3);
	mostra_pilha(&P2);

	if (!pilha_vazia(&P1) && !pilha_vazia(&P2)) {
		pilhasIguais(P1, P2);
	}

	pPilha P3 = NULL, P4 = NULL;

	push(&P3, 8);
	push(&P3, 23);
	push(&P3, 4);
	mostra_pilha(&P3);

	pilhasIguais(P1, P3);

	push(&P4, 4);
	push(&P4, 23);
	push(&P4, 8);
	mostra_pilha(&P4);

	pilhasIguais(P1, P4);

}
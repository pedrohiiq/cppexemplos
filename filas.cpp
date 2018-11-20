#include <stdio.h>
#include <cstdlib>

//exemplo de fila

struct fila {
	int tam;
	int *seq;
	int recente;
	int antigo;
	int nItens;
};

void criarFila( fila *f, int t) {
	f -> tam = t;
	f -> seq = (int*) std::malloc (t * (sizeof 1));
	f -> antigo = 0;
	f -> nItens = 0;
}

int olhar( fila * f ) { //equivalente ao metodo peek
	return (f -> seq[f -> antigo]);
}

//inserir insere um novo valor no vetor, ao lado do (atualmente) mais recente,
//e faz o apontador de mais recente apontar p/ esse novo valor.
int inserir( fila *f, int n ) {
	if (f -> nItens >= f -> tam) {
		return 0; //num deu :/
	} else {
		if (f -> recente == f -> tam - 1) {
			f -> recente = 0;
		} else {
			f -> recente++;
		}
		f -> seq[f -> recente] = n;
		f -> nItens++;
		return 1; //deu bom
	}
}

//a funcao tirar nao realmente tira o dado da memoria, somente
//faz os outros metodos da fila ignora-lo.
int tirar( fila *f ) {
	if (f -> nItens == 0) {
		return 1111; //deu ruim
	} else {
		int tmp = f -> seq[f -> antigo];
		printf("tmp: %d\n", tmp);
		if (f -> antigo == f -> tam - 1) {
			f -> antigo = 0;
		} else {
			f -> antigo++;
		}
		f -> nItens--;
		return tmp; //deu bom
	}
}

bool estaVazia( fila *f ) {
	return (f -> nItens == 0);
}

bool estaCheia( fila *f ) {
	return (f -> nItens == f -> tam);
}

int main() {
	fila f;
	criarFila(&f, 10);
	if (estaVazia(&f)) {
		printf("ta vazio\n");
	} else {
		printf("!tavazio\n");
	}
	if (estaCheia(&f)) {
		printf("ta cheio\n");
	} else {
		printf("!ta cheio\n");
	}
	inserir(&f, 10);
	if (estaVazia(&f)) {
		printf("ta vazio ainda\n");
	} else {
		printf("tem algum trem ali\n");
	}
	printf("%d estava ali, nao deve estar mais\n", tirar(&f));
	if (estaVazia(&f)) {
		printf("ta vazio de novo agr\n");
	} else {
		printf("tem algum trem ali (num devia)\n");
	}
	return 0;
}

//exemplo de lista agrupada
//exemplo de 

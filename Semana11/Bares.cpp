#include <bits/stdc++.h>
using namespace std;

const int TAM_VET = 4*21234;

vector<int> segmentos (TAM_VET, 0);

void adiciona_termo (int n, int inicio, int fim, int indice, int iniciot, int fimt){
	if (iniciot > fimt)
		return;

	if ((inicio == iniciot) && (fim == fimt)){
		segmentos[indice] += n;
		return;
	}

	int meio = iniciot + (fimt - iniciot)/2;

	if (meio > fim){
		adiciona_termo (n, inicio, fim, indice*2  , iniciot, meio);
		return;
	}
	if (meio < inicio){
		adiciona_termo (n, inicio, fim, indice*2+1, meio+1 , fimt);
		return;
	}	

	adiciona_termo (n, inicio, meio, indice*2  , iniciot, meio);
	adiciona_termo (n, meio  , fim , indice*2+1, meio+1 , fimt);
}

int get_menor (int comeco, int fim, int indice, int comecot, int fimt){
	if (comecot == fimt)
		return segmentos[indice];

	int meio = comecot + (fimt- comecot)/2;

	//fazer essa parte
}

int main() {
	int n_bares, n_op;
	cin >> n_bares >> n_op;

	for (int bar = 1 ; bar <= n_bares ; bar++){
		int pessoas;
		cin >> pessoas;

		adiciona_termo (pessoas, bar, bar, 0, 1, n_bares);
	}

	for (int op = 1 ; op <= n_op ; op++){
		int operacao;
		cin >> operacao;

		if (operacao == 1){
			int comeco, fim, soma;
			cin >> comeco >> fim >> soma;

			adiciona_termo (soma, comeco, fim, 0, 1, n_bares);
		}
		else if (operacao == 2){
			int comeco, fim;
			cin >> comeco >> fim;

			int menor = get_menor (comeco, fim, 0, 1, n_bares);
		}
	}
}
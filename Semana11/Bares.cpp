#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int TAM_VET = 4*212345;

vector<ll> segmentos (TAM_VET, 0);

void imprime_arvore (int n){
	int logaritmo = log2 (n) + 1;

	int indice = 1;
	for (int i = 1 ; i <= logaritmo+1 ; i++){
		for (int j = 1 ; j <= pow(2, i-1) ; j++){
			cout << segmentos[indice] << "	";
			indice++;
		}
		cout << endl;
	}
}

void imprime_estado (int n, int inicio, int fim, int indice, int iniciot, int fimt){
	cout << "n: " << n << "	inicio: " << inicio << "	fim: " << fim << "	indice: " << indice
	<< "	iniciot: " << iniciot << "	fimt: " << fimt << endl;
}

void imprime_adicao (int soma, int comeco, int fim, int n_bares){
	cout << "Adicionou " << soma << " entre " << comeco << " e " << fim << endl;
	imprime_arvore (n_bares);
	cout << endl << endl;
}

void adiciona_termo (ll n, int inicio, int fim, int indice, int iniciot, int fimt){
	//imprime_estado (n, inicio, fim, indice, iniciot, fimt);

	if ((iniciot > fimt)||(inicio > fim))
		return;

	if ((inicio == iniciot) && (fim == fimt)){
		//cout << "Adicionou:" << endl;
		//imprime_estado (n, inicio, fim, indice, iniciot, fimt);
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
	adiciona_termo (n, meio+1, fim , indice*2+1, meio+1 , fimt);
}

ll get_menor (int comeco, int fim, int indice, int comecot, int fimt){
	if ((comecot > fimt)||(comeco > fim))
		return 0;

	//encontrou o menor
	if (comecot == fimt)
		return segmentos[indice];

	int meio = comecot + (fimt- comecot)/2;

	//encontrar o intervalo

	//quando o intervalo esta em alguma metade
	if (meio > fim)
		return segmentos[indice] + get_menor(comeco, fim, indice*2, comecot, meio);

	if (meio < comeco) 
		return segmentos[indice] + get_menor(comeco, fim, indice*2+1, meio+1, fimt);

	return segmentos[indice] + min (get_menor(comeco, meio, indice*2, comecot, meio), get_menor(meio+1, fim, indice*2+1, meio+1, fimt));
}

int main() {
	int n_bares, n_op;
	cin >> n_bares >> n_op;

	for (int bar = 1 ; bar <= n_bares ; bar++){
		int pessoas;
		cin >> pessoas;

		adiciona_termo (pessoas, bar, bar, 1, 1, n_bares);
	}

	//imprime_arvore (n_bares);

	for (int op = 1 ; op <= n_op ; op++){
		int operacao;
		cin >> operacao;

		if (operacao == 1){
			int comeco, fim, soma;
			cin >> comeco >> fim >> soma;

			adiciona_termo (soma, comeco, fim, 1, 1, n_bares);
			//imprime_adicao (soma, comeco, fim, n_bares);
		}
		else if (operacao == 2){
			int comeco, fim;
			cin >> comeco >> fim;

			ll menor = get_menor (comeco, fim, 1, 1, n_bares);
			cout << menor << endl;
		}
	}
}
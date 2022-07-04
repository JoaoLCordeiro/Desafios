#include <bits/stdc++.h>
using namespace std;

const int NGRANDE = 987654321;

vector<vector<int>> vetor_resultados (30000, vector<int> (5, NGRANDE));
vector<int> vetor_moedas (5,0);

int encontra_possibilidades (int valor, int moeda_max){
	if (valor < 0)
		return (0);

	if ((valor <= 1) || (moeda_max == 0))
		return (1);

	if (vetor_resultados[valor][moeda_max] != NGRANDE){
		return (vetor_resultados[valor][moeda_max]);
	}

	int soma_possibilidades = 0;
	
	for (int i = 0 ; i < 5 ; i++)
		if (vetor_moedas[i] <= vetor_moedas[moeda_max])
			soma_possibilidades += encontra_possibilidades (valor - vetor_moedas[i], i);

	vetor_resultados[valor][moeda_max] = soma_possibilidades;
	return soma_possibilidades;
}

int main() {
	vetor_moedas[0] = 1;
	vetor_moedas[1] = 5;
	vetor_moedas[2] = 10;
	vetor_moedas[3] = 25;
	vetor_moedas[4] = 50;

	int n;
	while (cin >> n){
		int aux = encontra_possibilidades (n, 50);
		cout << aux << "\n";
	}
}
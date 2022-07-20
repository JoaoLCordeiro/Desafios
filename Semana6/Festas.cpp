#include <bits/stdc++.h>
using namespace std;

vector<int> grafo (1e3, 0); 
int n_convidados, n_amizades;

int acha_ponta (int indice){
	int i_aux = indice;
	while (grafo[i_aux] != i_aux){
		i_aux = grafo[i_aux];
	}

	return (i_aux);
}

int main() {
	cin >> n_convidados >> n_amizades;

	int festas = n_convidados;

	//todos começam apontando pra ele mesmo
	for (int i = 0 ; i < n_convidados ; i++)
		grafo[i] = i;

	int A,B;
	for (int i = 0 ; i < n_amizades ; i++){
		cin >> A >> B;

		int ponta_A, ponta_B;
		ponta_A = acha_ponta (A);
		ponta_B = acha_ponta (B);

		if (ponta_A != ponta_B){
			grafo[ponta_A] = ponta_B;
			festas--;
		}
	}

	cout << festas << endl;
}
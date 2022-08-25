#include <bits/stdc++.h>
using namespace std;

using pairit = pair<int,int>;

vector<pair<int,int>> cartas (512345, pair(0,0));
vector<int> grafo	(512345, -1);

int acha_dist (int origem, int destino){
	vector<int> visitado (512345, -1);

	int dist_o = 0;
	int dist_d = 0;

	while (true){
		if (origem != -1){
			if (visitado[origem] != -1)
				return (visitado[origem] + dist_o);

			visitado[origem] = dist_o;
			origem = grafo[origem];
			dist_o++;
		}

		if (destino != -1){
			if (visitado[destino] != -1)
				return (visitado[destino] + dist_d);

			visitado[destino] = dist_d;
			destino = grafo[destino];
			dist_d++;
		}
	}
}

void imprime_cartas (int n){
	for (int carta = 1 ; carta <= n ; carta++)
		cout << "{" << cartas[carta].first << ", " << cartas[carta].second << "} ";
	cout << endl;
}

void imprime_grafo (int n){
	for (int carta = 1 ; carta <= n ; carta++)
		cout << "{" << carta << ":" << grafo[carta] << "} ";
	cout << endl;
}

int main() {
	int n_cartas;
	cin >> n_cartas;
	for (int carta = 1 ; carta <= n_cartas ; carta++){
		int num;
		cin >> num;
		if (cartas[num].first == 0)
			cartas[num].first = carta;
		else
			cartas[num].second = carta;
	}

	for (int aresta = 1 ; aresta <= n_cartas-1 ; aresta++){
		int origem, destino;
		cin >> origem >> destino;

		if (grafo[origem] != -1)
			grafo[grafo[origem]]	= origem;

		grafo[origem] = destino;
	}

	//imprime_cartas(n_cartas/2);
	//imprime_grafo(n_cartas);

	//grafo pronto

	n_cartas = n_cartas/2;

	int soma = 0;
	for (int figura = 1 ; figura <= n_cartas ; figura++){
		int distancia = acha_dist (cartas[figura].first, cartas[figura].second);
		soma += distancia;
	}

	cout << soma << endl;;
}
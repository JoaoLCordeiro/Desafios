#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> cartas (512345, pair(0,0));
vector<int> grafo	(512345, 0);

int acha_dist (int origem, int destino){
	vector<int> visitado (512345, -1);

	bool achou = false;
	int dist_o = 0;
	int dist_d = 0;
	while (! achou){
		visitado[origem] = dist_o;
		visitado[destino] = dist_d;

		dist_o++;
		dist_d++;

		origem = grafo[origem];
		destino = grafo[destino];

		if ((visitado[origem] != -1) || (visitado[destino] != -1)){
			if (visitado[origem] != -1){
				return (visitado[origem] + dist_d);
			}
			else{
				return (visitado[destino] + dist_o);
			}
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

	int origem, destino;
	cin >> origem >> destino;
	grafo[origem] = destino;

	for (int aresta = 1 ; aresta <= n_cartas-1 ; aresta++){
		int origem, destino;
		cin >> origem >> destino;

		if ((grafo[origem] == 0) && (grafo[destino] == 0))
			grafo[origem] = destino;
		else if (grafo[destino] == 0)
			grafo[destino] = origem;
		else
			grafo[origem] = destino;
	}

	imprime_cartas(n_cartas/2);
	imprime_grafo(n_cartas);

	//grafo pronto

	n_cartas = n_cartas/2;

	int soma = 0;
	for (int figura = 1 ; figura <= n_cartas ; figura++){
		int distancia = acha_dist (cartas[figura].first, cartas[figura].second);
		cout << "A distancia das cartas com " << figura << " é: " << distancia << endl;
		soma += distancia;
	}

	cout << soma;
}
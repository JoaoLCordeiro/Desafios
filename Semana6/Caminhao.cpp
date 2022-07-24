#include <bits/stdc++.h>
using namespace std;
#define oo 112345678

vector<vector<int>> matriz_estradas (100, vector<int> (100, oo));

void imprime_matriz (int n){
	for (int i = 0 ; i < n ; i++){
		for (int j = 0 ; j < n ; j++)
			cout << matriz_estradas[i][j] << "	";
		cout << endl;
	}
}

int main() {
	int n_cidades, n_estradas;
	cin >> n_cidades >> n_estradas;

	//registra o tamanho das estradas entre cidades
	//se tiver mais de uma estrada, pega a menor
	for (int i = 0 ; i < n_estradas ; i++){
		int origem, destino, comprimento;
		cin >> origem >> destino >> comprimento;

		if (matriz_estradas[origem][destino] > comprimento){
			matriz_estradas[origem][destino] = comprimento;
			matriz_estradas[destino][origem] = comprimento;
		}
	}

	//zera a distancia dentro da cidade
	for (int i = 0 ; i < n_cidades ; i++)
		matriz_estradas[i][i] = 0;

	for (int desvio = 0 ; desvio < n_cidades ; desvio++)
		for (int origem = 0 ; origem < n_cidades ; origem++)
			for (int destino = 0 ; destino < n_cidades ; destino++)
				matriz_estradas[origem][destino] = min(matriz_estradas[origem][destino], matriz_estradas[origem][desvio] + matriz_estradas[desvio][destino]);

	//imprime_matriz (n_cidades);

	int menor_distancia_max = oo;
	int cid_menor_dist_max  = 0;
	for (int destinos = 0 ; destinos < n_cidades ; destinos++){
		int distancia_max = 0;

		//procura a maior distancia à aquela cidade
		for (int origens = 0 ; origens < n_cidades ; origens++){
			if (matriz_estradas[origens][destinos] > distancia_max)
				distancia_max = matriz_estradas[origens][destinos];
		}

		if (distancia_max < menor_distancia_max){
			menor_distancia_max = distancia_max;
			cid_menor_dist_max = destinos;
		}
	}

	cout << menor_distancia_max << endl;
}
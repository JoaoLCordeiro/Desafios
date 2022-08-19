#include <bits/stdc++.h>
using namespace std;
using ii = pair<int,int>

const int L = 1e4+15
const int R = 1e4+15;
int cts = 1;
vector<int> vis (L);
vector<int>	grafo (L+R);

int raiz;

int acha_raiz(int start){
	int aux = start;
	while (grafo[aux] != 0)
		aux = grafo[aux];
	return aux;
}

int main() {
	int n_vertices;
	cin >> n_vertices;

	for (int vertice = 1 ; vertice <= n_vertices ; vertice++){
		int origem, destino;
		cin >> origem >> destino;

		//pega o pai e a profundidade
		grafo[destino] = origem;
	}

	raiz = acha_raiz(1);

	
}
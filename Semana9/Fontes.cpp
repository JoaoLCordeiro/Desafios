#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll quant_duvidas = 0;

void dfs (int v, vector<int> &passou, vector<bool> &escolhido, vector<vector<int>> &grafo){
	passou[v]++;
	escolhido[v] = true;
	for (auto filho : grafo[v]){
		if (passou[v] <= 2)
			if (! escolhido[filho])
				dfs(filho, passou, escolhido, grafo);
	}
}

void imprime_passou(vector<int> passou){
	for (auto num : passou)
		cout << num << " ";
	cout << endl;
}

void imprime_resultado (vector<int> &passou){
	ll cont = 0;
	for (auto n_passadas : passou){
		if (n_passadas > 1)
			cont++;
	}
	cout << cont << endl;
}

int main() {
	int quant_vertices, quant_arestas;
	cin >> quant_vertices >> quant_arestas;

	vector<vector<int>> grafo (quant_vertices+1);
	vector<int>			arestas (quant_vertices+1, 0);
	vector<int>			passou (quant_vertices+1, 0);

	for (int i = 0 ; i < quant_arestas ; i++){
		int v1, v2;
		cin >> v1 >> v2;

		grafo[v1].push_back(v2);
		arestas[v2]++;
	}

	for (int v = 1 ; v <= quant_vertices ; v++){
		vector<bool>		escolhido (quant_vertices+1, false);
		//eh uma fonte
		if (arestas[v] == 0){
			dfs (v, passou, escolhido, grafo);
		}
	}

	//imprime_passou (passou);
	imprime_resultado(passou);
}
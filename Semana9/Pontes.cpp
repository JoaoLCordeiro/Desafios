#include <bits/stdc++.h>
using namespace std;
using parint = pair<int,int>;

vector <vector <int>> grafo (100);
int tk = 0;

vector<int> tin (100, -1);
vector<int> low (100);

vector<parint>	pontes;
set<int>		articulacoes;

int minimo(int a, int b){
	if (a < b)
		return a;
	else
		return b;
}

void dfs(int v1, int pai){
	tin[v1] = low[v1] = tk++;
	int ch = 0;

	for (auto v2 : grafo[v1]){
		if (v2 == pai)
			continue;
		else if (tin[v2] == -1){
			dfs(v2, v1);
			ch++;

			if (((low[v2] >= tin[v1]) && (pai != v1)) || ((ch >= 2) && (pai == v1)))
				articulacoes.insert(v1);

			if (low[v2] > tin[v1])
				pontes.push_back(parint(v1,v2));

			low[v1] = minimo(low[v1], low[v2]);
		}
		else{
			low[v1] = minimo(low[v1], low[v2]);
		}
	}
}

void limpa_pontes(){
	while (! pontes.empty()){
		pontes.pop_back();
	}
}

void limpa_articulacoes(){
	articulacoes.clear();
}

void reseta_tin_low(){
	for (int i = 0 ; i < 100 ; i++){
		tin[i] = -1;
		low[i] = 0;
	}
}

void limpa_grafo(){
	for (int i = 0 ; i < 100 ; i++){
		while (! grafo[i].empty())
			grafo[i].pop_back();
	}
}

int main() {
	int quant_testes;
	cin >> quant_testes;

	for (int teste = 0 ; teste < quant_testes ; teste++){
		int n_vertices, n_arestas;
		cin >> n_vertices >> n_arestas;

		for (int aresta = 0 ; aresta < n_arestas ; aresta++){
			int v1, v2;
			cin >> v1 >> v2;
			v1--;
			v2--;

			grafo[v1].push_back(v2);
			grafo[v2].push_back(v1);
		}

		for (int vertice = 0 ; vertice < n_vertices ; vertice++)
			dfs(vertice, vertice);

		cout << pontes.size() << endl;
		tk = 0;
		limpa_pontes();
		limpa_articulacoes();
		limpa_grafo();
		reseta_tin_low();
	}
}
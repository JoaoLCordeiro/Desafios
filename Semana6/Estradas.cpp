#include <bits/stdc++.h>
using namespace std;
#define oo 112345678

struct aresta{
	int origem, destino, peso;
};

vector<int>		v_paradas;
vector<aresta>	v_arestas;
vector<int>		v_distancias (1e4, oo);

void acha_custo_menor (int origem, int n_paradas){
	v_distancias[origem] = 0;
	for (int i = 0 ; i < n_paradas-1 ; i++){
		for (auto a : v_arestas){
			if ((v_distancias[a.origem] != oo) && (v_distancias[a.destino] > v_distancias[a.origem] + a.peso))
				v_distancias[a.destino] = v_distancias[a.origem] + a.peso;
		}
	}

	/*for (auto a : v_arestas){
		if ((v_distancias[a.origem] != oo) && (v_distancias[a.destino] > v_distancias[a.origem] + a.peso))
			return (- oo);
	}*/
}

int main() {
	int n_paradas;
	cin >> n_paradas;

	v_paradas.push_back(0);
	for (int i = 1 ; i <= n_paradas ; i++){
		int peso;
		cin >> peso;
		v_paradas.push_back(peso);
	}

	int n_ruas;
	cin >> n_ruas;

	aresta aresta_aux;

	for (int i = 0 ; i < n_ruas ; i++){
		int origem, destino;
		cin >> origem >> destino;

		aresta_aux.origem	= origem;
		aresta_aux.destino	= destino;
		aresta_aux.peso 	= v_paradas[destino] - v_paradas[origem];

		v_arestas.push_back(aresta_aux);
	}

	int n_consultas;
	cin >> n_consultas;

	acha_custo_menor (1, n_paradas);

	/*cout << endl;
	for (int i = 0 ; i < n_ruas ; i++)
		cout << v_arestas[i].origem << " " << v_arestas[i].destino << " " << v_arestas[i].peso << "		";
	cout << endl;

	cout << endl;
	for (int i = 1 ; i <= n_paradas ; i++)
		cout << v_distancias[i];
	cout << endl;*/

	for (int i = 0 ; i < n_consultas ; i++){
		int destino;
		cin >> destino;

		if ((v_distancias[destino] < 3) || (v_distancias[destino] == oo))
			cout << "Não, Edsger..." << endl;
		else
			cout << v_distancias[destino] << endl;
	}
}
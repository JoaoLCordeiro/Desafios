#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;
const int N = 1e5+15, B = ceil(sqrt(N));
vector<vector<ii>> g (N);


vector<ii> cartas (512345, pair(0,0));

vector<int> depth (N);
vector<int> up (N);
vector<int> bup (N);

void stdt_decompose(int u, int p, int w) {
	up[u]		= p;
	depth[u]	= depth[p] + 1;
	bup[u]		= depth[u] % B ? bup[p] : p;
	for (auto [v, w] : g[u]) 
		if (v != p)
			stdt_decompose(v, u, w);
}

int std_lca(int a, int b) {
	if (!(depth[a]/B > depth[b]/B))
		swap(a, b);
	while (depth[a]/B > depth[b]/B)
		a = bup[a];
	if (!(depth[a] > depth[b]))
		swap(a, b);
	while (depth[a] > depth[b])
		a = up[a];
	while (a != b){
		a = up[a];
		b = up[b];
	}
	return a;
}

int main() {
	int n_cartas;
	cin >> n_cartas;

	for	(int carta = 1 ; carta <= n_cartas ; carta++){
		int num;
		cin >> num;
		if (cartas[num].first == 0)
			cartas[num].first = carta;
		else
			cartas[num].second = carta;
	}

	for	(int carta = 1 ; carta <= n_cartas-1 ; carta++){
		int origem, destino;
		cin >> origem >> destino;

		g[origem].push_back(ii(destino, 1));
		g[destino].push_back(ii(origem, 1));
	}

	stdt_decompose(1, 1, 0);

	int soma = 0;

	for (int consulta = 1 ; consulta <= n_cartas/2 ; consulta++) {
		int origem, destino;
		origem	= cartas[consulta].first;
		destino	= cartas[consulta].second;
		soma += depth[origem] + depth[destino] - 2 * depth[std_lca(origem, destino)];
	}
	cout << soma << endl;
}
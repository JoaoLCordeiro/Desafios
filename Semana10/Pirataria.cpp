#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const	ll	N	= 1000;
const	ll	inf	= 1123456789;

vector<ll> ix(N), dist(N), par(N);
vector<vector<ll>> res (N);

struct edge { ll u, v, cap; };
vector<edge> edges;

bool caminho_minimo (ll vertice1, ll vertice2){
	fill(dist.begin(), dist.end(), inf);
	dist[vertice1] = 0;

	queue<ll> fila;
	fila.push(vertice1);

	while(! fila.empty()){
		//u guarda o primeiro da fila e tira ele dela
		ll u = fila.front();
		fila.pop();

		if (u == vertice2)
			break;

		for (ll i : res[u]){
			edge e	= edges[i];
			ll v	= e.v;

			if (e.cap && dist[v] == inf){
				dist[v]	= dist[u] + 1;
				par[v]	= u;
				ix[v]	= i;
				fila.push(v);
			} 
		}
	}

	return (dist[vertice2] < inf);
}

pair<ll,ll> ffek (ll vertice1, ll vertice2){
	ll min_cost = 0;
	ll max_flow = 0;

	while ( caminho_minimo (vertice1, vertice2) ){
		ll flow = inf;

		for (ll u = vertice2 ; u != vertice1 ; u = par[u]){
			flow = min(flow, edges[ix[u]].cap);
		}

		for (ll u = vertice2 ; u != vertice1 ; u = par[u]){
			edges[ix[u]].cap -= flow;
			edges[ix[u]^1].cap += flow;
		}

		min_cost += flow * dist[vertice2];
		max_flow += flow;
	}

	return {min_cost, max_flow};
}

int main() {
	ll quant_pcs, quant_conexoes;
	cin >> quant_pcs >> quant_conexoes;

	for (ll conexao = 0 ; conexao < quant_conexoes ; conexao++){
		ll pc1, pc2, vel;
		cin >> pc1 >> pc2 >> vel;

		pc1--;
		pc2--;

		res[pc1].push_back (edges.size());
		edges.push_back ({ pc1, pc2, vel });

		res[pc2].push_back (edges.size());
		edges.push_back ({ pc2, pc1, 0 });
	}

	auto [min_cost, max_flow] = ffek (0, quant_pcs-1);

	cout << max_flow << endl;
}
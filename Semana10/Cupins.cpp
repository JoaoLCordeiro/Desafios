#include <bits/stdc++.h>
using namespace std;
using ll = long long;

using ii = pair<int, int>;
const int N = 1e5+15;
vector<vector<ii>> g (N);
#define NEUTRAL 0
#define OP(X, Y) max(X, Y)

const int L = log2(N);
vector<ll> depth (N, 0);
vector<vector<ll>> weiop (N, vector<ll>(L+1));
vector<vector<ll>> up (N, vector<ll>(L+1));

void bl_euler_tour(int u, int p, int w) {
	up[u][0] = p;
	weiop[u][0] = w;
	depth[u] = depth[p] + 1;
	for (auto [v, w] : g[u])
		if (v != p)
			bl_euler_tour(v, u, w);
}

void bl_init(int u, int n) {
	depth[u] = 0;
	bl_euler_tour(u, u, 0);
	for (int l = 0; l < L; l++){
		for (int u = 0; u < n; u++) {
			int a = up[u][l];
			up[u][l+1] = up[a][l];
			weiop[u][l+1] = OP(weiop[u][l], weiop[a][l]);
		}
	}
}

int bl_lca(int a, int b) {
	if (!(depth[b] < depth[a]))
		swap(a, b);

	int diff = depth[a] - depth[b];
	for (int l = L; l >= 0; l--)
		if (diff & (1 << l))
			a = up[a][l];

	if (a == b)
		return a;

	for (int l = L; l >= 0; l--)
		if (up[a][l] != up[b][l]){
			a = up[a][l];
			b = up[b][l];
		}
	
	return up[a][0];
}

ll bl_op(int a, int b) {
	if (!(depth[a] > depth[b]))
		swap(a, b);

	ll res = NEUTRAL;
	ll diff = depth[a] - depth[b];

	for (int l = L; l >= 0; l--)
		if (diff & (1 << l)){
			res = OP(res, weiop[a][l]); 
			a = up[a][l];
		}

	if (a == b)
		return res;

	for (int l = L; l >= 0; l--)
		if (up[a][l] != up[b][l]){
			res = OP(res, OP(weiop[a][l], weiop[b][l]));
			a = up[a][l];
			b = up[b][l];
		}

	return OP(res, OP(weiop[a][0], weiop[b][0]));
}

int absoluto(int a, int b){
	if (a - b < 0)
		return (b - a);
	else
		return (a - b);
}

int main() {
	int n_lugares;
	cin >> n_lugares;
	int n_tuneis = n_lugares - 1;
	for (int orig = 1 ; orig <= n_tuneis ; orig++){
		int dest, custo; 
		cin >> dest >> custo;
		g[orig].push_back(ii(dest, custo));
		g[dest].push_back(ii(orig, custo));
	}

	bl_init(0, n_lugares);

	int n_consultas;
	cin >> n_consultas;
	while (n_consultas--) {
		int u, v; cin >> u >> v;
		cout << bl_op(u, v) + bl_op(v, u) << "\n";
	}
}
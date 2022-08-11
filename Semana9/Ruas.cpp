#include <bits/stdc++.h>
using namespace std;
using ll = double;
using dupla = pair<int,int>;
using dupla_ll = pair<ll,int>;

vector<dupla> cidades;

//comecam os itens usados no prim

const ll oo = numeric_limits<ll>::max();
const int N = 3123;

vector<ll> d (N, oo);
vector<bool> vis (N, false);

/////////////////////////////////

ll absoluto (int a, int b){
	ll resultado = a - b;
	if (resultado < 0)
		return (-resultado);
	else
		return (resultado);
}

//c1 = cidade1, c2 = cidade2
void adiciona_estrada (int c1, int c2, vector<vector<ll>> &estradas, int custo){
	if (c1 == c2){
		estradas[c1][c2] = 0;
		return;
	}

	ll delta_x = absoluto (cidades[c1].first, cidades[c2].first);
	ll delta_y = absoluto (cidades[c1].second, cidades[c2].second);

	//distancia euclidiana
	ll dx2 = delta_x*delta_x;
	ll dy2 = delta_y*delta_y;
	dx2 += dy2;
	dx2 = sqrt(dx2);
	dx2 *= custo;

	estradas[c1][c2] = dx2;
	estradas[c2][c1] = dx2;
}

ll prim (int comeco, int n_v, vector<vector<ll>> &estradas){
	ll sum = 0;
	priority_queue < dupla_ll , vector<dupla_ll> , greater <dupla_ll> > Q;

	Q.push(dupla_ll(d[comeco] = 0, comeco));

	while (! Q.empty()){
		auto [c, u] = Q.top();
		Q.pop();

		if (vis[u])
			continue;

		vis[u] = true;

		sum += c;
		for (int i = 1; i <= n_v ; i++)
			if (!vis[i] && estradas[u][i] < d[i])
				Q.push(dupla_ll(d[i] = estradas[u][i], i));
	}

	return sum;
}

void imprime_estradas(int n_cidades, vector<vector<ll>> &estradas){
	for (int i = 1 ; i <= n_cidades ; i++){
		for (int j = 1 ; j <= n_cidades ; j++)
			cout << estradas[i][j] << "	";
		cout << endl;
	}
}

int main() {
	int num_cidades, custo_terra, custo_asfalto;
	cin >> num_cidades >> custo_terra >> custo_asfalto;

	for (int cidade = 0 ; cidade < num_cidades ; cidade++){
		int x,y;
		cin >> x >> y;
		cidades.push_back(dupla(x,y));
	}

	vector<vector<ll>> estradas (num_cidades+1, vector<ll> (num_cidades+1, -1));

	int num_estradas;
	cin >> num_estradas;

	for (int estrada = 0 ; estrada < num_estradas ; estrada++){
		int cidade1, cidade2;
		char t_estrada;

		cin >> cidade1 >> cidade2 >> t_estrada;

		//se for de terra, colocamos o custo de asfaltar
		if (t_estrada == 't')
			adiciona_estrada (cidade1, cidade2, estradas, custo_terra);
		//se for asfaltada, colocamos 0 pois ja esta asfaltada
		else{
			estradas[cidade1][cidade2] = 0;
			estradas[cidade2][cidade1] = 0;
		}
	}

	for (int i = 1 ; i <= num_cidades ; i++)
		for (int j = 1 ; j <= num_cidades ; j++)
			//caso nao exista estrada
			if (estradas[i][j] == -1)
				adiciona_estrada (i, j, estradas, custo_asfalto);

	//aqui temos todas as possiveis estradas, agora encontramos o menor custo para conectar todas

	std::cout << std::fixed;
    std::cout << std::setprecision(15);

	//imprime_estradas (num_cidades, estradas);

	//cout << endl;
	cout << prim(1, num_cidades, estradas) << endl;
}
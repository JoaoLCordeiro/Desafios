#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using parll = pair<ll,ll>;
using pedido = tuple<ll,ll,ll>;

priority_queue<pedido, vector<pedido>, greater<pedido>> v_pedidos;
vector<parll> pedidos;

void imprime_vetor(){
	while (! v_pedidos.empty()){
		auto a = v_pedidos.top();
		v_pedidos.pop();
		cout << "{" << get<0>(a) << ", " << get<1>(a) << ", " << get<2>(a) << "} ";
	}
	cout << endl;
}

int main() {
	ll n_espacos, n_operacoes;
	cin >> n_espacos >> n_operacoes;

	//coloca as operacoes em ordem de onde comecam
	for (ll op = 1 ; op <= n_operacoes ; op++){
		ll a, l , d;
		cin >> a >> l >> d;
		v_pedidos.push(make_tuple(a,l,d));
	}

	//imprime_vetor ();

	//imprimem a quantia de cada espaco
	for (ll espaco = 1 ; espaco <= n_espacos ; espaco++){
		ll c_atual = 0;

		//coloca os pedidos que devem ser atendidos na fila
		while ((!v_pedidos.empty()) && (get<0>(v_pedidos.top()) == espaco)){
			ll first = 1;
			ll second = 1;

			first	= get<2>(v_pedidos.top());
			second	= get<1>(v_pedidos.top()) * get<2>(v_pedidos.top());

			pedidos.push_back(parll (first, second));
			v_pedidos.pop();
		}

		//passa pelos pedidos atuais e verifica se deve somar agora
		//USAR INDICE
		auto it = pedidos.begin();
		for (int indice = 0 ; indice < pedidos.size() ; indice++){
			if (pedidos[indice].second % pedidos[indice].first == 0)
				c_atual++;
			pedidos[indice].second--;
			it++;
			if (pedidos[indice].second == 0){
				it--;
				indice--;
				pedidos.erase(it);
			}
		}

		cout << c_atual << " ";
	}

	cout << endl;
}
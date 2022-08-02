#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//retorna o valor absoluto da subtração, o delta
ll absoluto (ll a, ll b){
	if (a > b)
		return (a-b);
	else
		return (b-a);
}

ll menor (ll a, ll b){
	if (a > b)
		return b;
	else
		return a;
}

ll conta_div_comum (ll x, ll y){
	vector<ll> divs_comum_x (0);

	ll sqrt_x = sqrt(x);

	for (ll i = 1; i <= sqrt_x ; i++){
		if (x % i == 0){
			divs_comum_x.push_back(i);
			divs_comum_x.push_back(x/i);
		}
	}

	ll cont_divs = 0;
	for (ll i : divs_comum_x){
		if (y % i == 0)
			cont_divs++;
	}

	return cont_divs;
}

int main() {
	int quant_testes;
	cin >> quant_testes;

	for (int i = 0 ; i < quant_testes ; i++){
		ll xA, yA, xB, yB;
		cin >> xA >> yA >> xB >> yB;

		ll x = absoluto(xA, xB);
		ll y = absoluto(yA, yB);

		ll quant_div_comum = conta_div_comum (x, y);

		cout << quant_div_comum + 1 << endl;
	}
}
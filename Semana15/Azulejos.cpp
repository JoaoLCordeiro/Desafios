#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool ehQuadrado(ll n){
	ll raiz = sqrt(n);

	return (n == raiz * raiz);
}

void imprime_resultado (ll quant){
	if (quant % 2 != 0){
		cout << "NO" << endl;
		return;
	}

	ll quadrados_2 = quant/2;

	if (ehQuadrado(quadrados_2)){
		cout << "YES" << endl;
		return;
	}

	if (quant % 4 != 0){
		cout << "NO" << endl;
		return;
	}

	ll quadrados_4 = quant/4;

	if (ehQuadrado(quadrados_4)){
		cout << "YES" << endl;
		return;
	}

	cout << "NO" << endl;
	return;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0 ; i < n ; i++){
		ll quant;
		cin >> quant;

		imprime_resultado(quant);
	}
}
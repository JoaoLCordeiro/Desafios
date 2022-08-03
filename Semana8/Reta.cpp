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

ll mdc (ll a, ll b){
	if (b == 0)
		return a;
	return mdc (b, a%b);
}

int main() {
	int quant_testes;
	cin >> quant_testes;

	for (int i = 0 ; i < quant_testes ; i++){
		ll xA, yA, xB, yB;
		cin >> xA >> yA >> xB >> yB;

		ll x = absoluto(xA, xB);
		ll y = absoluto(yA, yB);

		ll max_div_comum = mdc (x, y);

		cout << max_div_comum + 1 << endl;
	}
}
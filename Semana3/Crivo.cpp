#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> v_primos (15, 0);
ll v_conjunto = 0;

ll faz_somatorio (ll comeco, ll fim, ll n_primos){
	ll potencia = pow (2, n_primos);
	potencia--;

	ll soma = 0;

	do{
		v_conjunto += 1;		//passa pro proximo
		ll mult = 1;

		for (int i = 0 ; i < n_primos ; i++)
			if ((v_conjunto & (1ll << i)) != 0)	//o bit é 1
				mult *= v_primos[i];

		ll extra = 0;
		if ((comeco % mult) == 0)
			extra = 1;

		if ((__builtin_popcountll(v_conjunto) %  2) == 0)
			soma -= ((fim/mult) - (comeco/mult) + extra);
		else
			soma += ((fim/mult) - (comeco/mult) + extra);

	}while (v_conjunto != potencia);

	return ((fim - comeco + 1) - soma);
}

int main() {
	ll comeco, fim;
	cin >> comeco >> fim;

	ll n_primos;
	cin >> n_primos;

	for (int i = 0 ; i < n_primos ; i++)
		cin >> v_primos[i];

	ll somatorio = faz_somatorio (comeco, fim, n_primos);

	cout << somatorio << "\n";
}
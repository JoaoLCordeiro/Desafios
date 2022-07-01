#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int CONSTANTE = 1000000007;

vector<ll> fatoriais (10001, 0);

ll fatorial (int valor){
	if (fatoriais[valor] == 0){
		ll fat = 1;
		for (int i = valor ; i > 1; i--){
			fat = fat * i;
			fat = fat % CONSTANTE;
		}
		fatoriais[valor] = fat;
		return (fat);
	}
	else
		return (fatoriais[valor]);
}

ll fast_pow(ll a, ll b) {
	if (b == 0)
		return 1;

	if (b == 1)
		return a;

	ll res = fast_pow(a, b/2);
	res = (res * res) % CONSTANTE;
	if (b % 2)
		res = (res * a) % CONSTANTE;
	
	return res;
}

int main() {
	int n_colunas, n_coringas;
	cin >> n_colunas >> n_coringas;

	vector<int> v_valores (n_colunas);
	vector<int> v_coringas (n_colunas, 0);

	for (int i = 0 ; i < n_colunas ; i++)
		cin >> v_valores[i];
	
	for (int i = 0 ; i < n_coringas ; i++){
		int linha, coluna;
		cin >> linha >> coluna;
		v_coringas[coluna-1]++;
	}


	ll acima = 1;
	ll abaixo = 1;
	ll mult = 1;
	for (int i = 0 ; i < n_colunas ; i++){
		acima = fatorial (v_valores[i]);
		abaixo = fatorial (v_valores[i] + v_coringas[i] - n_colunas);
		abaixo = fast_pow (abaixo, CONSTANTE-2);

		ll aux = acima * abaixo;
		aux = aux % CONSTANTE;

		mult = mult * aux;
		mult = mult % CONSTANTE;
	}

	cout << mult << "\n";
}
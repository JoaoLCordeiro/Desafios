#include <bits/stdc++.h>
using namespace std;
using ll = long long;

stack<ll> pilha_primos;

ll fast_pow(ll a, ll b){
	if (b == 0)
		return 1;

	if (b == 1)
		return a;

	ll res = fast_pow(a, b/2);
	res = res * res;
	if (b % 2)
		res = res * a;
	
	return res;
}

void factorize (ll n) {
	for (ll i = 2; i*i <= n; i++)
		while (n % i == 0){
			n /= i;
			pilha_primos.push(i);
		}
	if (n > 1){
		pilha_primos.push(n);
	}
}

void imprime_primos(){
	while (! pilha_primos.empty()){
		ll primo = pilha_primos.top();
		pilha_primos.pop();

		ll expoente = 1;
		while ((! pilha_primos.empty()) && (pilha_primos.top() == primo)){
			pilha_primos.pop();
			expoente++;
		}

		cout << primo << " " << expoente << endl;
	}
}

void imprime_pilha(ll numero, ll q_primos){
	cout << "Quantidade de Primos: " << q_primos << " Pilha " << numero << ": ";
	while (! pilha_primos.empty()){
		cout << pilha_primos.top() << " ";
		pilha_primos.pop();
	}
	cout << endl;
}

int main() {
	int quant_testes;
	cin >> quant_testes;

	for (int i = 0 ; i < quant_testes ; i++){
		ll quant_primos;
		cin >> quant_primos;

		ll numero = 1;
		for (ll j = 0 ; j < quant_primos ; j++){
			ll primo, expoente;
			cin >> primo >> expoente;

			numero *= fast_pow(primo, expoente);
		}
		numero--;

		factorize(numero);

		//imprime_pilha(numero, quant_primos);
		imprime_primos();
	}
}
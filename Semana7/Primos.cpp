#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<bool>	primos (1e5+1, true);
vector<int>		s_primos (12, true);

ll multiplicacao (int quant){
	ll mult = 1;
	for (int i = 0 ; i < quant ; i++)
		mult *= s_primos[i];

	return mult;
}

void imprime_vetor (int k){
	for (int i = 0 ; i < k ; i++)
		cout << s_primos[i] << " ";
	cout << endl;
}

int main() {
	int n, k;
	cin >> n >> k;

	primos[0]	= false;
	primos[1]	= false;

	for (int i = 2 ; i <= int(1e5/2) ; i++){
		for (int j = i*i ; j <= int(1e5) ; j += i)
			primos[j] = false;
	}

	/*int indice = n;
	for (int i = 0 ; i < k ; i++){
		while (primos[indice] == false)
			indice--;
		s_primos[i] = indice;
		indice--;
	}

	while (multiplicacao(k) > n){
		for (int i = 0 ; i < k-1 ; i++)
			s_primos[i] = s_primos[i+1];

		while (primos[indice] == false)
			indice--;
		s_primos[k-1] = indice;
	}

	imprime_vetor(k);*/
}
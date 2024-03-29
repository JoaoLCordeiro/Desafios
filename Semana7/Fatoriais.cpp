#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

vector<double> v_digitos (1e7+1, 0);
int maior_digito = 1;

double acha_log (int n){
	double digitos;

	if (maior_digito < n){
		digitos = v_digitos[maior_digito];
		for (int i = maior_digito+1 ; i <= n ; i++){
			digitos += log10 (i);
			v_digitos[i] = digitos;
		}
		maior_digito = n;
	}
	else
		digitos = v_digitos[n];

	return digitos;
}

int conta_digitos_f (int n, double digitos){
	if (n <= 1)
		return 1;

	return floor(digitos) + 1;
}

int ultimo_digito_f (int n, double digitos){
	if (n <= 1)
		return 1;

	double aux = digitos;

	aux -= int (aux);
	int digito = pow (10, aux);
	
	return digito;
}

int main() {
	int n_casos;
	cin >> n_casos;

	for (int i = 0 ; i < n_casos ; i++){
		int n;
		cin >> n;

		double logaritmo = acha_log (n);

		int n_digitos = conta_digitos_f (n, logaritmo);
		int digito_f  = ultimo_digito_f (n, logaritmo);
		cout << digito_f << " " << n_digitos << endl;
	}
}
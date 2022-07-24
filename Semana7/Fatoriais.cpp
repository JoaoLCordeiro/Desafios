#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

double acha_log (int n){
	double digitos = 0;

	for (int i = 2 ; i <= n ; i++)
		digitos += log10 (i);

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
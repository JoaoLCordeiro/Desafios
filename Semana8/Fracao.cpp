#include <bits/stdc++.h>
using namespace std;

int main() {
	int quant_testes;
	cin >> quant_testes;

	for (int i = 0 ; i < quant_testes ; i++){
		int numerador, denominador;
		cin >> numerador >> denominador;

		cout << "[";

		cout << numerador/denominador;

		if (numerador % denominador != 0){
			numerador = numerador % denominador;
			cout << ";" << denominador/numerador;
			
			int aux = numerador;
			numerador = denominador % numerador;
			denominador = aux;
		}

		while (numerador % denominador != 0){
			numerador = numerador % denominador;
			cout << "," << denominador/numerador;
			
			int aux = numerador;
			numerador = denominador % numerador;
			denominador = aux;
		}

		cout << "]" << endl;
	}
}
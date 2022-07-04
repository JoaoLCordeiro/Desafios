#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int dimensao;
	cin >> dimensao;

	ll potencia = pow (2, dimensao);
	cout << potencia << "\n";

	ll entradas = 0;
	while (entradas != potencia){
		for (int i = dimensao-1 ; i != -1 ; i--){
			if ((entradas & (1 << i)) != 0)
				cout << "_";
			else
				cout << "#";
		}
		cout << "\n";

		entradas++;
	}	
}
#include <bits/stdc++.h>
using namespace std;

int main() {
	int numero;
	cin >> numero;
	int numdiv2 = numero / 2;
	int numsqrt2 = sqrt(numero);

	if (numero < 4){
		cout << "0\n";
		return 0;
	}

	vector<bool> primalidade (numero + 1, true);
	primalidade[0] = false;
	primalidade[1] = false;
	for (int i = 2 ; i <= numsqrt2 ; i++){
		for (int j = i*i ; j < numero ; j = j + i){
			primalidade[j] = false;
		}
	}

	int cont = 0;

	if (primalidade[2] && primalidade[numero - 2])
		cont++;

	for (int i = 3 ; i <= numdiv2 ; i = i + 2){
		if (primalidade[i] && primalidade[numero - i])
			cont++;
	}

	cout << cont << "\n";
}
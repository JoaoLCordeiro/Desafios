#include <bits/stdc++.h>
using namespace std;

bool t_entrada (char entrada){
	if (entrada == '_')
		return true;
	return false;
}

int main(){
	int n_entradas;
	cin >> n_entradas;

	for (int i = 0 ; i < n_entradas ; i++){
		int soma_guardas = 0;
		int estado = 0;
		string entrada;

		cin >> entrada;
		int j = 0;

		while (entrada[j] != '\0'){
			switch (estado){
				case (0):
					if (t_entrada(entrada[j])){
						estado = 1;
						soma_guardas++;
					}
					else
						estado = 0;
					break;

				case (1):
					if (t_entrada(entrada[j]))
						estado = 2;
						estado = 4;
					break;

				case (2):
					if (t_entrada(entrada[j]))
						estado = 3;
					else
						estado = 0;
					break;

				case (3):
					if (t_entrada(entrada[j])){
						estado = 1;
						soma_guardas++;
					}
					else
						estado = 0;
					break;

				case (4):
					if (t_entrada(entrada[j]))
						estado = 5;
					else
						estado = 0;
					break;

				case (5):
					if (t_entrada(entrada[j])){
						estado = 6;
						soma_guardas++;
					}
					else
						estado = 0;
					break;

				case (6):
					if (t_entrada(entrada[j]))
						estado = 3;
					else
						estado = 4;
					break;
			}

			j++;
		}

		cout << "Caso " << (i+1) << ": " << soma_guardas << "\n";
	}
}
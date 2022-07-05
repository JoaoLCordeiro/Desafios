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
		string entrada;

		cin >> entrada;
		int j = 0;

		while (entrada[j] != '\0'){
			if (t_entrada(entrada[j])){
				entrada[j  ] = '#';
				if (entrada[j+1] != '\0'){
					entrada[j+1] = '#';
					if (entrada[j+2] != '\0')
						entrada[j+2] = '#';
				}
				soma_guardas++;
			}
			j++;
		}

		cout << "Caso " << i+1 << ": " << soma_guardas << endl;
	}
}
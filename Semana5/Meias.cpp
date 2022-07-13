#include <bits/stdc++.h>
using namespace std;

int				n_pilhas, n_retiradas;
vector<int>		v_pilhas ((int)1e5, 0);

int busca_binaria (int comeco, int fim, int procurado){
	int meio = comeco + (fim - comeco)/2;

	if (comeco > fim)
		return 0;

	if ((v_pilhas[meio] >= procurado) && (v_pilhas[meio-1] < procurado)){
		return meio;
	}

	if (v_pilhas[meio] < procurado)
		return (busca_binaria (meio+1, fim, procurado));
	else
		return (busca_binaria (comeco, meio-1, procurado));
}

int main() {
	cin >> n_pilhas;

	for (int i = 1 ; i <= n_pilhas ; i++){
		int aux;
		cin >> aux;
		v_pilhas[i] = v_pilhas[i-1] + aux;
	}
	
	cin >> n_retiradas;

	for (int i = 0 ; i < n_retiradas ; i++){
		int aux;
		cin >> aux;
		int indice = busca_binaria (1, n_pilhas, aux);
		cout << indice << endl;
	}
}
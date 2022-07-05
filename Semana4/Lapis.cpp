#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//const ll NGRANDE = 1987654321987654321;
const int NGRANDE = 987654321;

vector<int>		v_quadrados (10000, 0);

vector<vector<int>>	matriz_resultado (10000, vector<int>(10000, NGRANDE));

int n_quadrados, c_lapis;

int distribui_lapis (int n_lapis, int comeco){
	if (n_lapis == 0)
		return (v_quadrados[n_quadrados]);

	if (matriz_resultado[n_lapis][comeco] != NGRANDE)
		return (matriz_resultado[n_lapis][comeco]);

	//recursivamente, pega a maior soma com o lapis naquela posicao
	int soma_max = v_quadrados[comeco-c_lapis] - v_quadrados[comeco] + distribui_lapis (n_lapis - 1 , comeco + c_lapis);

	//coloca o lapis atual nas posicoes possiveis
	for (int i = comeco + 1 ; i <= n_quadrados - ((n_lapis-1) * c_lapis) ; i++){

		int soma_aux = v_quadrados[i-c_lapis] - v_quadrados[i] + distribui_lapis (n_lapis-1 , i+c_lapis);

		if (soma_aux > soma_max)
			soma_max = soma_aux;
	}

	matriz_resultado[n_lapis][comeco] = soma_max;

	return (soma_max);
}

int distribui_lapis (int n_lapis, int comeco){
	if (n_lapis == 0)
		return (v_quadrados[n_quadrados]);

	if (matriz_resultado[n_lapis][comeco] != NGRANDE)
		return (matriz_resultado[n_lapis][comeco]);

	//recursivamente, pega a maior soma com o lapis naquela posicao
	int soma_max = v_quadrados[comeco-c_lapis] - v_quadrados[comeco] + distribui_lapis (n_lapis - 1 , comeco + c_lapis);

	//coloca o lapis atual nas posicoes possiveis
	for (int i = comeco + 1 ; i <= n_quadrados - ((n_lapis-1) * c_lapis) ; i++){

		int soma_aux = v_quadrados[i-c_lapis] - v_quadrados[i] + distribui_lapis (n_lapis-1 , i+c_lapis);

		if (soma_aux > soma_max)
			soma_max = soma_aux;
	}

	matriz_resultado[n_lapis][comeco] = soma_max;

	return (soma_max);

	for (int lapis = n_lapis ; lapis >= 0 ; lapis--){
		
	}
}

int main(){
	int n_lapis;
	cin >> n_quadrados >> n_lapis >> c_lapis;

	for (int i = 1 ; i <= n_quadrados ; i++){
		cin >> v_quadrados[i];
		v_quadrados[i] += v_quadrados[i-1];
	}

	int soma = distribui_lapis(n_lapis, c_lapis);

	cout << soma << "\n";
}
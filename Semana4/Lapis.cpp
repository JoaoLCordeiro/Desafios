#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//const ll NGRANDE = 1987654321987654321;
const int NGRANDE = 987654321;

vector<bool>	escolhidos (10001, false);
vector<int>		v_quadrados (10000, 0);

vector<vector<int>>	matriz_resultado (10000, vector<int>(10000, NGRANDE));

int n_quadrados, c_lapis;

bool coloca_lapis (int i_fim_lapis, int quant){
	if (quant == 0)
		return true;

	if (coloca_lapis (i_fim_lapis-1, quant-1)){
		escolhidos[i_fim_lapis] = true;
		return true;
	}

	escolhidos[i_fim_lapis] = false;
	return false;
}

void tira_lapis (int i_fim_lapis, int quant){
	if (quant == 0)
		return;

	escolhidos[i_fim_lapis] = false;
	tira_lapis (i_fim_lapis-1, quant-1);
}

void reposiciona_lapis (int i_fim_lapis, int quant){
	escolhidos[i_fim_lapis] = true;
	escolhidos[i_fim_lapis - quant] = false;
}

int distribui_lapis (int n_lapis, int comeco){
	if (n_lapis == 0){
		return (v_quadrados[n_quadrados]);
	}

	if (matriz_resultado[n_lapis][comeco] != NGRANDE)
		return (matriz_resultado[n_lapis][comeco]);

	//coloca o lapis na primeira posicao possivel no momento
	coloca_lapis (comeco, c_lapis);

	//recursivamente, pega a maior soma com o lapis naquela posicao
	int soma_max = v_quadrados[comeco-c_lapis] - v_quadrados[comeco] + distribui_lapis (n_lapis - 1 , comeco + c_lapis);

	//coloca o lapis atual nas posicoes possiveis
	for (int i = comeco + 1 ; i <= n_quadrados - ((n_lapis-1) * c_lapis) ; i++){
		reposiciona_lapis (i, c_lapis);

		int soma_aux = v_quadrados[i-c_lapis] - v_quadrados[i] + distribui_lapis (n_lapis-1 , i+c_lapis);

		if (soma_aux > soma_max)
			soma_max = soma_aux;
	}

	tira_lapis (n_quadrados - ((n_lapis-1) * c_lapis), c_lapis);
	matriz_resultado[n_lapis][comeco] = soma_max;

	return (soma_max);
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
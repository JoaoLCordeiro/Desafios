#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<bool>	escolhidos (10001, false);
vector<int>		v_quadrados (10000, 0);
int n_quadrados, c_lapis;

ll soma_vetor (){
	ll soma = 0;
	for (int i = 1 ; i <= n_quadrados ; i++){
		if (! (escolhidos[i]))
			soma = soma + v_quadrados[i];
	}

	return soma;
}

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

ll distribui_lapis (int n_lapis, int comeco){
	if (n_lapis == 0)
		return (soma_vetor());

	//coloca o lapis na primeira posicao possivel no momento
	coloca_lapis (comeco, c_lapis);

	//recursivamente, pega a maior soma com o lapis naquela posicao
	ll soma_max = distribui_lapis (n_lapis - 1 , comeco + c_lapis);

	//tira o lapis pra ir pras proximas posicoes possiveis, com a maior soma atual ja guardada
	tira_lapis (comeco, c_lapis);

	//coloca o lapis atual nas posicoes possiveis
	for (int i = comeco + 1 ; i <= n_quadrados - ((n_lapis-1) * c_lapis) ; i++){
		coloca_lapis (i, c_lapis);

		ll soma_aux = distribui_lapis (n_lapis-1 , i+c_lapis);

		tira_lapis (i, c_lapis);

		if (soma_aux > soma_max)
			soma_max = soma_aux;
	}

	return (soma_max);
}

int main(){
	int n_lapis;
	cin >> n_quadrados >> n_lapis >> c_lapis;

	for (int i = 1 ; i <= n_quadrados ; i++)
		cin >> v_quadrados[i];

	ll soma = distribui_lapis(n_lapis, c_lapis);

	cout << soma << "\n";
}
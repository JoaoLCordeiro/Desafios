#include <bits/stdc++.h>
using namespace std;

int teleporta_passos (vector<int> &v_tp, int n_p, int origem, int n_passos){
	vector<int> escolhido		(n_p+1);
	vector<int> planeta_passo	(n_passos);

	int planeta_atual = origem;
	for (int passo = 1 ; passo <= n_passos ; passo++){
		//se o tp for pra ele mesmo
		if (v_tp[planeta_atual] == planeta_atual)
			return (planeta_atual);

		//testa o ciclo
		//nao encontrou o ciclo
		if (escolhido[planeta_atual] == 0){
			//guarda o passo que o movimento chegou ali
			escolhido[planeta_atual] = passo;

			//pega o planeta atual
			planeta_atual = v_tp[planeta_atual];

			//guarda o planeta que chegou naquele passo
			planeta_passo[passo] = planeta_atual;
		}
		//encontrou ciclo
		else{
			//encontra quantos passos devem ser feitos sem contar ciclos
			int passos_ciclo		= passo - escolhido[planeta_atual];
			int passos_restantes	= n_passos - passo + 1;				//remover o +1 na solução antiga
			int passos_andar		= passos_restantes % passos_ciclo;

			//anda os passos
			planeta_atual = planeta_passo[ escolhido[planeta_atual] + passos_andar - 1 ];
			/*for (int passo_r = 1 ; passo_r <= passos_restantes ; passo_r++)
				planeta_atual = v_tp[planeta_atual];*/
			return planeta_atual;
		}
	}
	return planeta_atual;
}

int main() {
	int n_planetas, n_consultas;
	cin >> n_planetas >> n_consultas;

	vector<int>		v_teleporte		(n_planetas+1);

	for (int planeta = 1 ; planeta <= n_planetas ; planeta++){
		int destino;
		cin >> destino;

		v_teleporte[planeta] = destino;
	}

	for (int consulta = 0 ; consulta < n_consultas ; consulta++){
		int origem, n_passos;
		cin >> origem >> n_passos;

		int destino = teleporta_passos (v_teleporte, n_planetas, origem, n_passos);
		cout << destino << endl;
	}
}
#include <bits/stdc++.h>
using namespace std;
using matrizbool = vector<vector<bool>>;
using matrizint = vector<vector<int>>;

matrizbool	pertence	(500, vector<bool> (500, false));
matrizint	conjuntos	(500);

bool sao_exclusivos (int emp1, int emp2){
	for (auto usuario : conjuntos[emp1])
		//possuem elementos iguais
		if (pertence[emp2][usuario])
			return false;

	return true;
}

int conta_fontes (int n_empresas){
	for (int empresa1 = 0 ; empresa1 < n_empresas ; empresa1++){
		for (int empresa2 = 0 ; empresa2 < n_empresas ; empresa2++){
			if (conjuntos[empresa1].size() <= conjuntos[empresa2].size()){
				bool exclusivos = sao_exclusivos (empresa1, empresa2);
				//VOCE PAROU AQUI AMIGO
			}
		}
	}
}

int main() {
	int quant_empresas, quant_usuarios;
	cin quant_empresas >> quant_usuarios;

	for (int empresa = 0 ; empresa < quant_empresas ; empresa++){
		int n_usuarios;
		cin >> n_usuarios;

		for (int usuario = 0 ; usuario < n_usuarios ; usuario++){
			int usuario_atual;
			cin >> usuario_atual;

			conjuntos[empresa].pushback(usuario_atual);
			pertence[empresa][usuario_atual] = true;
		}
	}

	//aqui, temos o conjuntos que, cada cada possui um vetor com os usuarios da empresa
	//e uma matriz que diz, pra m[i][j], se o usuario j foi vazado pela empresa i

	int n_fontes = conta_fontes (quant_empresas);
}
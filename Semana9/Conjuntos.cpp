#include <bits/stdc++.h>
using namespace std;
using matrizbool = vector<vector<bool>>;
using matrizint = vector<vector<int>>;

matrizbool	pertence	(500, vector<bool> (500, false));
matrizint	conjuntos	(500);

vector<int>		fontes;
vector<bool>	nao_fonte (500, false);

//retorna se a emp1 esta contida em emp2
bool esta_contido (int emp1, int emp2){
	//pelos usuarios da emp1
	for (auto usuario : conjuntos[emp1])
		//verifica se ele está na emp2
		if (! pertence[emp2][usuario])
			return false;

	return true;
}

bool tamanho_igual (int emp1, int emp2){
	if (conjuntos[emp1].size() == conjuntos[emp2].size())
		return true;
	else
		return false;
}

void acha_fontes (int n_empresas){
	for (int empresa1 = 0 ; empresa1 < n_empresas ; empresa1++){
		bool fonte = true;

		if (nao_fonte[empresa1])
			continue;

		for (int empresa2 = 0 ; empresa2 < n_empresas ; empresa2++){
			if (empresa1 == empresa2)
				continue;

			if (esta_contido (empresa2, empresa1)){
				if (tamanho_igual (empresa1, empresa2))
					nao_fonte[empresa2] = true;
				else{
					fonte = false;
					break;
				}
			}
		}

		if (fonte)
			fontes.push_back(empresa1);
	}
}

void imprime_fontes (){
	for (auto fonte : fontes)
		cout << fonte << endl;
}

int main() {
	int quant_empresas, quant_usuarios;
	cin >> quant_empresas >> quant_usuarios;

	for (int empresa = 0 ; empresa < quant_empresas ; empresa++){
		int n_usuarios;
		cin >> n_usuarios;

		for (int usuario = 0 ; usuario < n_usuarios ; usuario++){
			int usuario_atual;
			cin >> usuario_atual;

			conjuntos[empresa].push_back(usuario_atual);
			pertence[empresa][usuario_atual] = true;
		}
	}

	//aqui, temos o conjuntos que, cada cada possui um vetor com os usuarios da empresa
	//e uma matriz que diz, pra m[i][j], se o usuario j foi vazado pela empresa i

	acha_fontes (quant_empresas);
	imprime_fontes ();
}
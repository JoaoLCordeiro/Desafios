#include <bits/stdc++.h>
using namespace std;

vector<string> nomes;

bool testa_amizade (string nome1, string nome2){
	//conseguimos obter nome2 usando nome1?
	int tam1 = nome1.size();
	int tam2 = nome2.size();

	//testa se tem apenas uma alteração de letra
	if (tam1 == tam2){

		int conta_diff = 0;
		for (int indice = 0 ; indice < tam1 ; indice++){
			if (nome1[indice] != nome2[indice])
				conta_diff++;
			if (conta_diff > 1)
				return false;
		}
		return true;

	}
	//teste se apenas uma letra foi adicionada
	else if (tam1+1 == tam2){

		int conta_diff = 0;
		for (int indice = 0 ; indice < tam2 ; indice++){
			if (nome1[indice] != nome2[indice+conta_diff]){
				conta_diff++;
				indice--;
			}
			if (conta_diff > 1)
				return false;
		}
		return true;

	}
	else
		return false;
}

void imprime_nomes (string nome, vector<string> v_nomes){
	cout << nome << ": ";

	if (v_nomes.size() == 0)
		cout << "nenhum melhor amigo";
	else{
		for (auto s : v_nomes)
			cout << s << " ";
	}
	cout << endl;
}

int main() {
	int n_alunos;
	cin >> n_alunos;

	for (int aluno = 1 ; aluno <= n_alunos ; aluno++){
		string nome;
		cin >> nome;
		nomes.push_back(nome);
	}

	sort(nomes.begin(), nomes.end());

	for (int aluno = 0 ; aluno < n_alunos ; aluno++){
		vector<string> amigos;

		for (int j = 0 ; j < aluno ; j++)
			if (testa_amizade(nomes[aluno], nomes[j]))
				amigos.push_back(nomes[j]);

		for (int j = aluno+1 ; j < n_alunos ; j++)
			if (testa_amizade(nomes[aluno], nomes[j]))
				amigos.push_back(nomes[j]);

		sort(amigos.begin(), amigos.end());
		imprime_nomes (nomes[aluno], amigos);
	}
}
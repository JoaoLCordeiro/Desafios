#include <bits/stdc++.h>
using namespace std;

vector<int> livros (13,0);
vector<bool> escolhidos (13, false);
vector<pair<int,int>> restricoes (12*11);
int n_livros, n_restricoes;

bool aceita_restricoes (int escolhido){
	for (int j = 0 ; j < n_restricoes ; j++){
		if (restricoes[j].first == escolhido){
			if (escolhidos[restricoes[j].second] == true){
				return false;
			}
		}
	}

	return true;
}

void permuta (int n_escolhidos){
	if (n_escolhidos == n_livros){
		//imprime
		for (int i = 0 ; i < n_livros ; i++){
			cout << livros[i] << " ";
		}
		cout << "\n";
	}
	else{
		for (int i = 1; i <= n_livros; i++) 
			if (!escolhidos[i]) {
				escolhidos[i] = true;
				if (aceita_restricoes(i)){
					livros[n_escolhidos] = i;
					permuta(n_escolhidos + 1);
				}
				escolhidos[i] = false;
			}
	}
}

int main() {
	cin >> n_livros;

	for (int i = 1 ; i <= n_livros ; i++){
		livros[i] = i;
	}

	cin >> n_restricoes;
	for (int i = 0 ; i < n_restricoes ; i++){
		int aux1;
		int aux2;

		cin >> aux1 >> aux2;
		pair<int,int> aux (aux1, aux2);

		restricoes[i] = aux;
	}

	permuta (0);
}
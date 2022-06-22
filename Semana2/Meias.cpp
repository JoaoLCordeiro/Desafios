#include <bits/stdc++.h>
using namespace std;

int main() {
	int num_meias;
	int num_max;

	cin >> num_meias >> num_max;
	num_meias *= 2;

	set<string> pilha_meias;
	set<string>::iterator indice;

	bool meia_vista = false;
	int i = 0;

	while ((i < num_meias) && !(meia_vista)){
		string nome_meia;
		cin >> nome_meia;

		indice = pilha_meias.find(nome_meia);
		if (indice == pilha_meias.end()){
			pilha_meias.insert(nome_meia);
			if (pilha_meias.size() >= num_max)
				meia_vista = true;
		}
		else
			pilha_meias.erase(indice);

		i++;
	}

	if (meia_vista)
		cout << "7.18808\n";
	else
		cout << "3.14159\n";
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int operacoes;
	cin >> operacoes;

	list<ll> fita;
	list<ll>::iterator cabeca = fita.begin();

	for (int i = 0 ; i < operacoes ; i++){
		char opcode;
		cin >> opcode;
		if (opcode == 'm'){
			int espacos;
			cin >> espacos;

			advance(cabeca, espacos);
		}
		else if (opcode == 'i'){
			int espacos;
			ll elemento;

			cin >> espacos >> elemento;

			for (int j = 0 ; j < espacos ; j++){
				fita.insert(cabeca, elemento);
				cabeca--;
			}
		}
		else if (opcode == 'd'){
			cabeca = fita.erase(cabeca);
		}
		else{// opcode == 'q'
			cout << *cabeca << "\n";
		}
	}
}
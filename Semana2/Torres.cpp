#include <bits/stdc++.h>
using namespace std;

int main() {
	stack<int> pilha;
	bool erro = false;

	int num_torres;
	cin >> num_torres;
	int i = 0;

	while ((i < num_torres) && !(erro)){
		int tam;
		char lado;
		cin >> tam >> lado;

		if (lado == 'L'){
			if (pilha.empty())
				pilha.push(tam);
			else{
				if (pilha.top() <= tam)
					erro = true;
				else
					pilha.push(tam);
			}
		}
		else{
			if (pilha.empty())
				erro = true;
			else{
				if (pilha.top() == tam)
					pilha.pop();
				else
					erro = true;
			}
		}

		i++;
	}

	if (erro)
		cout << "N\n";
	else
		cout << "S\n";
}
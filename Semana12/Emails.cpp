#include <bits/stdc++.h>
using namespace std;

map<string, int> contador;

int main() {
	int n_entradas;
	cin >> n_entradas;

	for (int entrada = 0 ; entrada < n_entradas ; entrada++){
		string email;
		cin >> email;

		if (regex_match (email, regex("[a-z0-9]+@ufpr.br")) || 
			regex_match (email, regex("[a-z0-9]+@[a-z]*.ufpr.br"))){

			contador[email]++;
			cout << contador[email] << endl;
		}

	}
}
#include <bits/stdc++.h>
using namespace std;

vector<int> pre(string s) {
	int n = s.size();
	vector<int> pi (n, 0);
	for (int i = 1, j = 0; i < n; i++) {
		while (j > 0 && s[i] != s[j])
			j = pi[j-1];

		if (s[i] == s[j])
			j++;
			
		pi[i] = j;
	}
	return pi;
}

int main() {
	string palavra;
	vector<int> prefixos;

	cin >> palavra;
	prefixos = pre(palavra);

	int tamanho = palavra.size();
	tamanho--;

	vector<int> resultado;

	while (prefixos[tamanho] != 0){
		resultado.push_back(prefixos[tamanho]);
		tamanho = prefixos[tamanho] - 1;
	}

	for (auto it = resultado.end()-1; it != resultado.begin()-1; it--) {
		cout << *it << " ";
	}
	cout << endl;
}
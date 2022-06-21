#include <bits/stdc++.h>
using namespace std;

int main() {
	int inscritos;
	int vagas;
	cin >> inscritos >> vagas;
	int classificados = 0;
	int i = 2;
	while ((i <= inscritos)&&(classificados < vagas)){
		cout << i << "\n";
		classificados++;
		i += 2;
	}													
	i = 1;
	while ((i <= inscritos)&&(classificados < vagas)){
		cout << i << "\n";
		classificados++;
		i += 2;
	}													
}

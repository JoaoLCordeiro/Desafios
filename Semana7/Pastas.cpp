#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

int main() {
	ll frequencia, d_pasta, d_viagem;
	cin >> frequencia >> d_pasta >> d_viagem;

	ll escovadas = d_viagem / frequencia;
	ll pastas = escovadas / d_pasta + bool(escovadas % d_pasta);

	cout << pastas << endl;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int n;
	cin >> n;

	ll soma = 0;
	for (int i = 0 ; i < n ; i++){
		int aux;
		cin >> aux;
		if (aux > 10)
			soma += (aux - 10);
	}

	cout << soma << "\n";
}
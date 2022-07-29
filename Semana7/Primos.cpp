#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<bool> primos(112345 + 1, true);
vector<int> v_primos;

void imprime_vetor()
{
	for (int i : v_primos)
		cout << i << " ";
	cout << endl;
}

int main()
{
	int t;
	cin >> t;

	primos[0] = false;
	primos[1] = false;

	for (int i = 2; i <= sqrt(112345); i++)
	{
		for (int j = i * i; j <= 112345; j += i)
			primos[j] = false;
	}

	for (int i = 2; i <= 112345; i++)
		if (primos[i] == true)
			v_primos.push_back(i);

	//imprime_vetor();

	while (t--)
	{

		ll n, k;
		cin >> n >> k;
		// tenho um vetor com todos os primos até sqrt(n)

		ll j;
		ll mult = 1;
		for (j = 0 ; j < k ; j++)
			mult *= v_primos[j];

		for (j = k ; j < n ; j++){
			mult /= v_primos[j-k];
			mult *= v_primos[j];
			if (mult > n)
				break;
		}

		cout << (mult/v_primos[j]) * v_primos[j-k] << endl;
	}
}
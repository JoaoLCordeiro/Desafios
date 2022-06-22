#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> v_minutos;

	int num_min;
	cin >> num_min;

	for (int i = 0 ; i < num_min ; i++){
		int min;
		cin >> min;
		v_minutos.push_back(min);
	}

	sort(v_minutos.begin(), v_minutos.end());

	int pessoas_max = num_min / 2;
	int min_max = v_minutos[v_minutos.size() / 2] - v_minutos[(v_minutos.size() / 2) - 1];

	cout << pessoas_max << " " << min_max << "\n";
}
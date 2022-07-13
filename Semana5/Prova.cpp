#include <bits/stdc++.h>
using namespace std;

vector<int> fita (1e5 + 1, 0);

int get_numero (int indice){
	int i = indice;
	int aux = 0;
	while (i > 0){
		aux += fita[i];
		i -= i & (-i);
	}

	return (aux);
}

int get_alg (int indice){
	int i = indice;
	int soma1 = 0;
	while (i > 0){
		soma1 += fita[i];
		i -= i & (-i);
	}

	int soma2 = 0;
	i = indice -1;
	while (i > 0){
		soma2 += fita[i];
		i -= i & (-i);
	}

	return (soma1 - soma2);
}

void set_numero (int indice, int num, int n_algarismos){
	int diff = num - get_alg (indice);
	//cout << diff << "	" << num << "	" << get_numero (indice) << endl;

	int i = indice;
	while (i <= n_algarismos){
		fita[i] += diff;
		i += i & (-i);
	}
}

int faz_numero (int A, int B){
	int comeco	= get_numero(A-1);
	int fim		= get_numero(B); 

	

	int num = fim - comeco;

	//cout << A << ":	" << comeco << "	" << B << ":	" << fim << "	Num:	" << num << "	Mod 9:	" << num % 9 << endl;

	num = num % 9;

	return num;
}

void imprime_vetor (int n_algarismos){
	cout << endl;
	for (int i = 0 ; i <= n_algarismos ; i++){
		cout << fita[i] << "	";
	}
	cout << endl;
}

int main() {
	int n_algarismos;
	cin >> n_algarismos;

	string str_num;
	cin >> str_num;

	for (int i = 1 ; i <= n_algarismos ; i++){
		int aux;
		aux = str_num[i-1] - '0';

		//fazemos entao uma árvore de fenwick
		int indice = i;
		while (indice <= n_algarismos){
			fita[indice] += aux;
			indice += indice & (-indice);
		}
	}

	//imprime_vetor (n_algarismos);

	int n_operacoes;
	cin >> n_operacoes;

	for (int i = 0 ; i < n_operacoes ; i++){
		int opcode;
		cin >> opcode;

		if (opcode < 3){
			int A,B;
			cin >> A >> B;

			int operando1 = faz_numero (A,B);

			cin >> A >> B;

			int operando2 = faz_numero (A,B);

			//cout << operando1 << " " << operando2 << endl;

			if (opcode == 1)
				operando1 = (operando1 + operando2) % 9;
			else
				operando1 = (operando1 * operando2) % 9;

			int verificador;
			cin >> verificador;

			if (operando1 == verificador)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
		else{
			int indice;
			cin >> indice;

			int num;
			cin >> num;

			//cout << "Numero de antes:	" << get_alg(indice);

			set_numero (indice, num, n_algarismos);

			//cout << "	Numero de depois:	" << get_alg(indice);

			//imprime_vetor (n_algarismos);
		}
	}
}
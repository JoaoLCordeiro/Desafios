#include <bits/stdc++.h>
using namespace std;

int main() {
	queue<int>	fila_FIFO;	//uma fila pra cada caso
	stack<int>	fila_LIFO;
	priority_queue<int,vector<int>,less<int>>	fila_PRIO;

	bool bool_FIFO = true;	//um bool pra cada caso
	bool bool_LIFO = true;
	bool bool_PRIO = true;

	int num_int;
	cin >> num_int;

	for (int i = 0 ; i < num_int ; i++){
		int inout;
		int idade;
		cin >> inout >> idade;

		if (inout == 0){
			fila_FIFO.push(idade);
			fila_LIFO.push(idade);
			fila_PRIO.push(idade);
		}
		else{	//inout == 1
			if (bool_FIFO){
				if (fila_FIFO.front() == idade)
					fila_FIFO.pop();
				else
					bool_FIFO = false;
			}

			if (bool_LIFO){
				if (fila_LIFO.top() == idade)
					fila_LIFO.pop();
				else
					bool_LIFO = false;
			}

			if (bool_PRIO){
				if (fila_PRIO.top() == idade)
					fila_PRIO.pop();
				else
					bool_PRIO = false;
			}
		}
	}

	if ((bool_FIFO && bool_LIFO) || ((bool_PRIO) && (bool_LIFO || bool_FIFO)))
		cout << "ambiguous\n";
	else if (bool_FIFO)
		cout << "fifo\n";
	else if (bool_LIFO)
		cout << "lifo\n";
	else if (bool_PRIO)
		cout << "priority\n";
	else
		cout << "unknown\n";
}

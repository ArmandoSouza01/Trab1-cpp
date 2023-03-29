#include <iostream>
#include <locale.h>
#include <iomanip>
using namespace std;


int main(int argc, char** argv)
{
	setlocale(LC_ALL, "");
	string frase, f1;

	cout << "Digite sua frase." << endl;
	cin >> frase;

	
	for (int j = frase.size() - 1; j >= 0; j--) {
		f1 += frase[j];
	}
	
	
	if (frase.compare(f1) == 0) {
		cout << "Sua frase é um palíndromo!";
	}
	else {
		cout << "Sua frase não é um palíndromo.";
	}
	
	return 0;
}
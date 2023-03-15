//Armando Righi de Souza - CB302038X

#include <iostream>
#include <locale.h>
#include <math.h>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

//variáveis

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "");
	
	int **baralho = new int*[2];
	int naipe = 1;
	int ncarta = 1;
	int prefixo = 0;
	int cont = 0;
	int m1 =0, m2 =0, m3 =0, m4 =0;
	unsigned seed = time(NULL);
	srand(seed);
	int *p1 = new int[11];
	int *p2 = new int[11];
	int *p3 = new int[11];
	int *p4 = new int[11];
	int A;
	int B;
	int C;
	int D;
	int E;
	
//embaralhar e atribuir
		
	for (int i = 0; i < 2; i++) {
		baralho[i] = new int[52];
	}
	
	for (int i = 0; i < 2; i++) {
		naipe = 1;
		for (int j = 0; j < 52; j++) {
			cont++;

			baralho[i][j] = (naipe * 1000) + (prefixo * 100) + (ncarta *(10)) + (i);
			
			ncarta++;
			if (ncarta == 10) {
				ncarta = 0;
				prefixo = 1;
			}
			if (prefixo == 1 && ncarta > 3) {
				prefixo = 0;
				ncarta = 1;
			}
			
			if (cont % 13 == 0) {
				naipe++;
			}
		}
	}
	
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 52; j++) {
				
			A = rand() % 52;
			B = rand() % 2;
			C = baralho[B][A];
			D = rand() % 52;
			E = rand() % 2;
			
			baralho[B][A] = baralho[E][D];
			baralho[E][D] = C;
			
		}
	}
	
//distribuição
	
	cout << "Identificação de cartas: " << endl<<endl;
	cout << "-----------------------------------------------------" << endl;
	cout << "Primeiro dígito = Naipe; 1-Copas / 2-Paus / 3-Ouro / 4-Espada" << endl;	
	cout << "Segundo e terceiro dígitos = Carta; 01-Ás... /...07-Sete... / 13-Rei" << endl;
	cout << "Último dígito = Baralho; 1- Vermelho / 2 - Azul" << endl;
	cout << "-----------------------------------------------------" << endl <<endl;
	
	cout << "Jogador 1: " << endl<<endl;
	
	for (int i = 0; i < 44; i++) {
		if (i < 11) {
			p1[m1] = baralho[0][i];
			cout << m1 + 1 << "ª carta do Jogador 1: " << p1[m1] << endl;
			m1++;
		}
		if (i == 11) {
			cout << "-----------------------------------------------------" << endl << endl;
			cout << "Jogador 2: " << endl<<endl;
		}
		
		if (i >= 11 && i < 22) {
			p2[m2] = baralho[0][i];
			cout << m2 + 1 << "ª carta do Jogador 2: " << p2[m2] << endl;
			m2++;
		}
		if (i == 22) {
			cout << "-----------------------------------------------------" << endl << endl;
			cout << "Jogador 3: " << endl<<endl;
		}
		
		if (i >= 22 && i < 33) {
			p3[m3] = baralho[0][i];
			cout << m3 + 1 << "ª carta do Jogador 3: " << p3[m3] << endl;
			m3++;
		}
		if (i == 33) {
			cout << "-----------------------------------------------------" << endl <<endl;
			cout << "Jogador 4: " << endl<<endl;
		}
				
		if (i >= 33) {
			p4[m4] = baralho[0][i];
			cout << m4 + 1 << "ª carta do Jogador 4: " << p4[m4] << endl;
			m4++;
		}
	}
	
	
	
	return 0;
}
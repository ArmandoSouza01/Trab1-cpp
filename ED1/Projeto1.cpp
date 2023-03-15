//Armando Righi de Souza - CB302038X

#include <iostream>
#include <locale.h>
#include <stdlib.h>
using namespace std;

//matriz

int main(int argc, char** argv)
{
	int **matriz = new int*[15];
	
	for (int i = 0; i < 15; ++i) 
	{
		matriz[i] = new int[40];
	}
	
	
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 40; j++) {
			matriz[i][j] = 0;
		}
	}
	
	
//declara��o vari�veis
	
	setlocale(LC_ALL, "");
	int cond = 1;
	int ocupados = 0;
	int poltrona;
	int valorBilheteria = 0;
	int fileira;
	int escolha;
	
//looping
		
	while (cond != 0) {
		cout << "Ol�, escolha uma das op��es abaixo para utilizar o sistema (0 - 3)" << endl;
		cout << endl;
		cout << "----------------------" << endl;
		cout << "0. Finalizar" << endl;
	   	cout << "1. Reservar poltrona" << endl;
	   	cout << "2. Mapa de ocupa��o" << endl;
		cout << "3. Faturamento" << endl;
		cout << "----------------------";
		cout << endl << endl;
		cout << "Digite sua op��o: ";
		cin >> escolha;			
		cout << endl;
		
//escolha de casos
		
		switch (escolha) {
			case 0:
				cond = 0;
				cout << "Obrigado! At� logo!" << endl;
				break;
			
			//-----------------------------------------------------------------------------------------------------------//
			
			case 1:
				system("cls");
				do {
					cout << "Digite o n�mero da fileira desejada (entre 1 e 15): " << endl;
				   	cin >> fileira;
				   	if (fileira < 1 || fileira > 15) {
						   cout << "Valor inv�lido, redigite!" << endl << endl;
					   }
				}
				while (fileira < 1 || fileira > 15);
				
				do {
					cout << "Digite o n�mero da poltrona (entre 1 e 40): " << endl;
					cin >> poltrona;
					if (poltrona < 1 || poltrona > 40) {
						cout << "Valor inv�lido, redigite!" << endl << endl;
					}
				}
				while (poltrona < 1 || poltrona > 40);
				
				
				if (matriz[fileira - 1][poltrona - 1] == 0) {
					
					cout << "Lugar reservado!" << endl;
					ocupados++;
					matriz[fileira - 1][poltrona - 1] = 1;
					
					if (fileira < 6) {
						valorBilheteria += 50;
					}
					else if (fileira > 10) {
						valorBilheteria += 15;
					}
					else {
						valorBilheteria += 30;
					}
					
				}
				else {
					
					cout << "Este lugar j� est� reservado!" << endl << endl;
					
				}
				
				break;
			
			//-------------------------------------------------------------------------------------------------------------//
			
			case 2:
				system("cls");
				for (int i = 0; i < 15; i++) {
					for (int j = 0; j < 40; j++) {
						if (matriz[i][j] == 0) {
							cout << "." << " ";
						}
						else {
							cout << "#" << " ";
						}
					}
					cout << endl;
				}
				cout << endl << "'.' S�o lugares vazios" << endl << "'#' S�o lugares reservados" << endl << endl;
				break;
			
			//---------------------------------------------------------------------------------------------------------------//
			
			case 3:
				system("cls");
				cout << "Quantidade de lugares ocupados: " << ocupados << endl << endl;
				cout << "Valor da Bilheteria: R$" << valorBilheteria << endl;
				break;
			
//op��es inexistentes
			
			default:
				cout << "Voc� digitou uma op��o inv�lida!" << endl << "Digite novamente..." << endl;
				break;
				
		}
		
	}
	
	
	return 0;
}
#include <iostream>
#include <string>
#include <Windows.h>
#include <iomanip>
#include <conio.h>
//#include <ctime>
#include <time.h>

using namespace std;

//setas direcionais
#define	UP 72
#define	DOWN 80
#define	LEFT 75
#define	RIGHT 77

//tecla enter
#define ENTER 13

#define NUM_OPCOES 3
//tecla ESC
#define ESC 27

//tempo LIMITE de 20 s
#define TEMPLIMITE 20

//DIMENÇÕES MATRIZ LABirinto
#define	LIN 10
#define	COL 20

//prototipos
void mostrarMenu();
char selecionarOpcao(int& opcaoSelecionada, string str1, string str2, string str3);
void menuNiveis();
void menuInstruções();
void mostrarInstrucoes1();
void mostrarInstrucoes2();
void mostrarInstrucoes3();
void jogo(string labirinto1[][COL], string labArmadilhas[][COL], int vidas, int tempoResta, int nivel);
void nivelUm(); 
void nivelDois();
void nivelTres();
void desenharLabirinto(string lab[][COL],int vidas, int tempResta,int nivel);  
void recomecar(string lab[][COL], int& l, int& c, string jog);
void direita(string lab[][COL],string labArm[][COL], int& l, int& c, string jog, int& vidas,int nivel);
void esquerda(string lab[][COL], string labArm[][COL], int& l, int& c, string jog, int& vidas, int nivel);
void cima(string lab[][COL], string labArm[][COL], int& l, int& c, string jog, int& vidas,int nivel);
void baixo(string lab[][COL], string labArm[][COL], int& l, int& c, string jog, int& vidas, int nivel);

	//açoes a realizar 
	// inicializar o labirinto (desenhar a matriz 10x20 com os caminhos) 
	//variaveis para as cordenadas, jogador, estado do jogo, 


int main()
{
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);
	mostrarMenu();


}

void mostrarMenu() {
	
	int opcaoSelecionada = 0;
	

	while (true) {
		system("cls");

		cout << "\n_____________________________________________________________________________________";
		cout << "\n\n\t\t\t\tMENU PRINCIPAL - JOGO DO LABIRINTO" << endl;
		cout << "\n_____________________________________________________________________________________\n" << endl; 
		
		char escolha = selecionarOpcao(opcaoSelecionada, "Jogar", "Instruções", "Sair");
		if (escolha == ENTER) {  
			switch (opcaoSelecionada) {
			case 0: menuNiveis(); break; 
			case 1: menuInstruções(); break; 
			case 2: exit(0); break;
			}
		}
	}
}
void menuInstruções() {
	int opcaoSelecionada = 0;
	bool sair = false;


	while (!sair) {
		system("cls");
		cout << "\n_____________________________________________________________________________________";
		cout << "\n\n\t\t\t\tMENU INTRUÇÕES" << endl;
		cout << "\n_____________________________________________________________________________________";
		cout << "\n\n\tESC para sair para o menu principal!\n" << endl;

		char escolha = selecionarOpcao(opcaoSelecionada, "Nivel 1", "Nivel 2", "Nivel 3");
		if (escolha == ENTER) {
			switch (opcaoSelecionada) {
			case 0: mostrarInstrucoes1(); break;
			case 1: mostrarInstrucoes2(); break;
			case 2: mostrarInstrucoes3(); break;
			}
		}

		if (escolha == ESC) {
			sair = true;
		}
	}
}
void mostrarInstrucoes1() {

	bool sair = false;
	while (!sair) {
		system("cls");

		cout << "\n\n\tESC para sair para o menu Instruções!\n" << endl;
		cout << "\n\t1. Use as teclas direcionais para mover o jogador (@) pelo labirinto." << endl;
		cout << "\n\t2. O objetivo é chegar à saída (F) do labirinto." << endl;

		if (_getch() == ESC)
			sair = true;
	}

}
void mostrarInstrucoes2() {

	bool sair = false;
	while (!sair) {
		system("cls");

		cout << "\n\n\tESC para sair para o menu Instruções!\n" << endl;
		cout << "\n\t1. Use as teclas direcionais para mover o jogador (@) pelo labirinto." << endl;
		cout << "\n\t2. O objetivo é chegar à saída (F) do labirinto." << endl;
		cout << "\n\t3. Cuidado com as armadilhas (A)! Elas tiram vidas." << endl;
		cout << "\n\t4. Você tem 3 vidas. Se perder todas, o jogo acaba." << endl;

		if (_getch() == ESC)
			sair = true;
	}

}
void mostrarInstrucoes3() {
	
	bool sair = false;
	while (!sair) { 
		system("cls");
		
		cout << "\n\n\tESC para sair para o menu Instruções!\n" << endl; 
		cout << "\n\t1. Use as teclas direcionais para mover o jogador (@) pelo labirinto." << endl;
		cout << "\n\t2. O objetivo é chegar à saída (F) do labirinto." << endl;
		cout << "\n\t3. Cuidado com as armadilhas (A)! Elas tiram vidas." << endl;
		cout << "\n\t4. O jogo tem um tempo limite de 20 segundos. Se o tempo acabar, você perde." << endl;
		cout << "\n\t5. Você tem 3 vidas. Se perder todas, o jogo acaba." << endl;

		if (_getch() == ESC)
			sair = true;
	}

}
void menuNiveis() { 
	int opcaoSelecionada = 0; 
	bool sair = false;


	while (!sair) { 
		system("cls"); 
		cout << "\n_____________________________________________________________________________________";
		cout << "\n\n\t\t\t\tMENU NIVEIS" << endl;
		cout << "\n_____________________________________________________________________________________";
		cout << "\n\n\tESC para sair para o menu principal!\n" << endl;

		char escolha = selecionarOpcao(opcaoSelecionada, "Nivel 1", "Nivel 2", "Nivel 3");
		if (escolha == ENTER) { 
			switch (opcaoSelecionada) { 
			case 0: nivelUm(); break; 
			case 1: nivelDois(); break; 
			case 2: nivelTres(); break; 
			}
		}
		
		if (escolha == ESC) { 
			sair = true; 
		}
	}

}

char selecionarOpcao(int& opcaoSelecionada, string str1, string str2, string str3) {

	string opcoes[NUM_OPCOES] = {str1,str2,str3} ;
	char escolha;
	for (int i = 0; i < NUM_OPCOES; i++) {
		if (i == opcaoSelecionada) {
			// Destacar a opção selecionada
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
			cout << "\t> " << opcoes[i] << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
		else {
			cout << "\t  " << opcoes[i] << endl;
		}
	}
	// Ler uma tecla sem pressionar Enter
	cout << "\n\n\tUtilize as teclas direcionais para se deslocar no menu!";
	
	escolha = _getch();
	if (escolha == 224) { // Código para teclas especiais (setas)
		escolha = _getch(); // Captura a tecla especial
	}
	
	switch (escolha) {
		case UP:opcaoSelecionada = (opcaoSelecionada - 1 + NUM_OPCOES) % NUM_OPCOES; // tora o menu ciclico e nunca cai fora dos limites do array
				break;
		case DOWN:opcaoSelecionada = (opcaoSelecionada + 1) % NUM_OPCOES;
				break;
	}
	
	return escolha;
}

void jogo(string labirinto1[][COL], string labArmadilhas[][COL], int vidas, int tempoResta, int nivel) {
	//variaveis para as coordenadas
	int l = 8, c = 0;			//coordenadas inicio jogo
	string jog = "@";			//simbulo jogador
	labirinto1[l][c] = jog;		//inicia jogador labirinto

	if(nivel==2 || nivel==3)
		vidas = 3;				//inicia o jogo com 3 vidas

	bool sair = false;
	unsigned char tecla;
	clock_t t_inicio, t_atual;
			
	t_inicio = clock(); 
	tempoResta = TEMPLIMITE;
	while (!sair)
	{
		if (nivel == 3) { 
			
			t_atual = clock(); 
			int duracao = (t_atual - t_inicio) / CLOCKS_PER_SEC;           
			tempoResta = TEMPLIMITE - duracao; //para decrescer
				if (tempoResta <= 0) {
					system("cls");
					desenharLabirinto(labirinto1, vidas, 0,nivel);
					cout << "\n\tGame Over! TEMPO ESGOTADO!!!" << endl;
					Sleep(2000);
					break;
				}	
		
		}
		system("cls");
		desenharLabirinto(labirinto1, vidas, tempoResta,nivel);
		cout << "\n\n\tUtilize as teclas direcionais para se deslocar no labirinto!";
		cout << "\n\n\t\tESC para sair para o menu principal!"; 

		while (_kbhit()) {
			tecla = _getch(); 
			if (tecla == 224)
				tecla = _getch();

			switch (tecla) {
			case UP: cima(labirinto1, labArmadilhas, l, c, jog, vidas, nivel);
				break;
			case DOWN:baixo(labirinto1, labArmadilhas, l, c, jog, vidas, nivel);
				break;
			case RIGHT:direita(labirinto1, labArmadilhas, l, c, jog, vidas, nivel);
				break;
			case LEFT:esquerda(labirinto1, labArmadilhas, l, c, jog, vidas, nivel);
				break;

			}

			if (tecla == ESC) {
			sair = true; 
			}
		}
		
		
		if (l == 2 && c == 19) {
			system("cls");
			desenharLabirinto(labirinto1, vidas, tempoResta,nivel);
			cout << "\n\tParabéns!! Ganhou!!" << endl;
			Sleep(2000);
			break;
		}
		if (nivel == 2 || nivel == 3) {
			if (vidas == 0) {
				system("cls");
				desenharLabirinto(labirinto1, vidas, tempoResta,nivel);
				cout << "\n\tGame Over! Perdeu todas as vidas!" << endl;
				Sleep(2000);
				break;
			}
		}

		Sleep(200);
	}
}
void nivelUm() { 
	string labirinto1[LIN][COL] = {

		//0	 1   2   3   4    5   6   7   8   9  10   11  12  13  14  15  16  17  18  19
		{"#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#",}, //0
		{"#","#"," "," "," "," "," "," "," "," "," ","#","#","#","#","#","#","#","#","#",},	//1
		{"#","#"," ","#","#","#","#","#","#","#"," "," ","#","#","#","#","#","#"," ","F",},	//2
		{"#","#"," "," "," "," "," ","#","#","#","#"," ","#"," ","#","#","#","#"," "," ",},	//3
		{"#"," "," ","#","#","#"," ","#","#","#","#"," ","#","#"," ","#"," "," "," ","#",},	//4
		{"#"," ","#","#","#","#"," ","#","#","#","#"," ","#","#","#","#","#","#"," ","#",},	//5
		{"#"," "," "," ","#","#"," "," ","#","#","#"," ","#","#","#"," ","#","#"," ","#",},	//6
		{"#","#","#"," "," "," "," "," "," ","#","#"," ","#","#","#"," ","#","#"," ","#",},	//7
		{" "," "," "," ","#","#","#","#"," "," "," "," "," "," "," "," "," "," "," ","#",},	//8
		{"#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#",}	//9

	};
	string armadilhas[LIN][COL] = {};
	

	jogo(labirinto1, armadilhas, -1, -1, 1);
	
}


void nivelDois() {
	int vidas = 3;
	string labirinto1[LIN][COL] = {

		//0	 1   2   3   4    5   6   7   8   9  10   11  12  13  14  15  16  17  18  19
		{"#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#",}, //0
		{"#","#"," "," "," "," "," "," "," "," "," ","#","#","#","#","#","#","#","#","#",},	//1
		{"#","#"," ","#","#","#","#","#","#","#"," "," ","#","#","#","#","#","#"," ","F",},	//2
		{"#","#"," "," "," "," "," ","#","#","#","#"," ","#"," ","#","#","#","#"," "," ",},	//3
		{"#"," "," ","#","#","#"," ","#","#","#","#"," ","#","#"," ","#"," "," "," ","#",},	//4
		{"#"," ","#","#","#","#"," ","#","#","#","#"," ","#","#","#","#","#","#"," ","#",},	//5
		{"#"," "," "," ","#","#"," "," ","#","#","#"," ","#","#","#"," ","#","#"," ","#",},	//6
		{"#","#","#"," "," "," "," "," "," ","#","#"," ","#","#","#"," ","#","#"," ","#",},	//7
		{" "," "," "," ","#","#","#","#"," "," "," "," "," "," "," "," "," "," "," ","#",},	//8
		{"#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#",}	//9

	};
	string labArmadilhas[LIN][COL] = {

		//0	 1   2   3   4    5   6   7   8   9  10   11  12  13  14  15  16  17  18  19
		{"#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#",}, //0
		{"#","#"," "," "," "," "," "," "," "," "," ","#","#","#","#","#","#","#","#","#",},	//1
		{"#","#"," ","#","#","#","#","#","#","#"," "," ","#","#","#","#","#","#"," ","F",},	//2
		{"#","#"," "," "," "," "," ","#","#","#","#"," ","#"," ","#","#","#","#"," ","A",},	//3
		{"#"," "," ","#","#","#"," ","#","#","#","#"," ","#","#"," ","#"," "," "," ","#",},	//4
		{"#"," ","#","#","#","#","A","#","#","#","#"," ","#","#","#","#","#","#"," ","#",},	//5
		{"#"," "," "," ","#","#"," "," ","#","#","#"," ","#","#","#"," ","#","#"," ","#",},	//6
		{"#","#","#"," "," "," "," "," "," ","#","#"," ","#","#","#"," ","#","#"," ","#",},	//7
		{" "," "," "," ","#","#","#","#"," ","A"," "," "," "," "," "," "," "," "," ","#",},	//8
		{"#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#",}	//9

	};

	jogo(labirinto1, labArmadilhas, vidas, -1, 2); 
}
void nivelTres() {
	int vidas = 3;
	string labirinto1[LIN][COL] = {

		//0	 1   2   3   4    5   6   7   8   9  10   11  12  13  14  15  16  17  18  19
		{"#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#",}, //0
		{"#","#"," "," "," "," "," "," "," "," "," ","#","#","#","#","#","#","#","#","#",},	//1
		{"#","#"," ","#","#","#","#","#","#","#"," "," ","#","#","#","#","#","#"," ","F",},	//2
		{"#","#"," "," "," "," "," ","#","#","#","#"," "," "," "," ","#","#","#"," "," ",},	//3
		{"#"," "," ","#","#","#"," ","#","#","#","#"," ","#","#"," ","#"," "," "," ","#",},	//4
		{"#"," ","#","#","#","#"," ","#","#","#","#"," ","#","#","#","#","#","#"," ","#",},	//5
		{"#"," "," "," ","#","#"," "," ","#","#","#"," ","#","#","#"," ","#","#"," ","#",},	//6
		{"#","#","#"," "," "," "," "," "," ","#","#"," ","#","#","#"," ","#","#"," ","#",},	//7
		{" "," "," "," ","#","#","#","#"," "," "," "," "," "," "," "," "," "," "," ","#",},	//8
		{"#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#",}	//9

	};
	string labArmadilhas[LIN][COL] = {

		//0	 1   2   3   4    5   6   7   8   9  10   11  12  13  14  15  16  17  18  19
		{"#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#",}, //0
		{"#","#"," "," "," "," "," "," "," "," "," ","#","#","#","#","#","#","#","#","#",},	//1
		{"#","#"," ","#","#","#","#","#","#","#"," "," ","#","#","#","#","#","#"," ","F",},	//2
		{"#","#"," "," "," "," "," ","#","#","#","#"," "," ","A"," ","#","#","#"," ","A",},	//3
		{"#"," "," ","#","#","#"," ","#","#","#","#"," ","#","#"," ","#"," "," "," ","#",},	//4
		{"#"," ","#","#","#","#","A","#","#","#","#"," ","#","#","#","#","#","#"," ","#",},	//5
		{"#"," "," "," ","#","#"," "," ","#","#","#"," ","#","#","#"," ","#","#"," ","#",},	//6
		{"#","#","#"," "," "," "," "," "," ","#","#"," ","#","#","#"," ","#","#"," ","#",},	//7
		{" "," "," "," ","#","#","#","#"," ","A"," "," "," "," "," "," "," "," "," ","#",},	//8
		{"#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#",}	//9

	};
	
	
	jogo(labirinto1, labArmadilhas, vidas, 0, 3); 

}
	void desenharLabirinto(string lab[][COL], int vidas,int tempResta, int nivel) {
		
		cout << endl;

		cout << "\n_____________________________________________________________________________________";
		if (nivel == 1) {
			cout << "\n\n\tNIVEL 1 | VIDAS INFINITAS | SEM TEMPO!" << endl << endl;
		}
		else if (nivel == 2) {
			cout << "\n\n\tNIVEL 2 | Vidas restantes: " << vidas << endl << endl;
		}
		else {
			cout << "\n\n\tNIVEL 3 | Vidas restantes: " << vidas <<
			" | Tempo restante: " << tempResta << " segundos" << endl << endl;
		}
		
		cout << "\n_____________________________________________________________________________________\n" << endl;
		for (int i = 0; i < LIN; i++)
		{
			cout << "\t\t";
			for (int j = 0; j < COL; j++)
			{
				if (lab[i][j] == "@") {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED); 
					cout << lab[i][j]; 
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); 
				}
				else
					cout << lab[i][j];
			}
			cout << endl;
		}
	}

	void recomecar(string lab[][COL], int& l, int& c, string jog) {
		lab[l][c] = " ";			//remove da posição atual
		l = 8, c = 0;				//voltar às coordenadas de inicio jogo
		lab[l][c] = jog;			//atribuir ao jogador
	}

	void direita(string lab[][COL],string labArm [][COL], int& l, int& c, string jog, int& vidas, int nivel) {

		if (nivel == 2 || nivel == 3) {
			if (labArm[l][c + 1] == "A") {
				vidas--;
				lab[l][c] = " ";
				lab[l][c+1] = "A";					//PARA REVELAR A ARMADILHA
				recomecar(lab, l, c, jog);
				cout << "\n\tVocê caiu numa armadilha! Perdeu uma vida!! RECOMEÇAR!!" << endl;
				Sleep(1000);
				return;					// Sai da função para evitar mover o jogador
									//porque incrementa antes
			}
		}
		
		if (lab[l][c + 1] == " "|| lab[l][c + 1] == "F") {
			lab[l][c] = " ";
			lab[l][++c] = jog;
		}
		else {
			cout << "\n\tPAREDE!!!";
			Sleep(200);

		}
	
	}
	void esquerda(string lab[][COL], string labArm[][COL], int& l, int& c, string jog, int& vidas,int nivel) {

		//para ter a certeza que não sai dos limites do array. 
		if (c-1>=0)
		{
			if (nivel == 2 || nivel == 3) {
				if (labArm[l][c - 1] == "A") {
					vidas--;
					lab[l][c] = " ";
					lab[l][c - 1] = "A";	 				//PARA REVELAR A ARMADILHA
					recomecar(lab, l, c, jog);
					cout << "\n\tVocê caiu numa armadilha! Perdeu uma vida!! RECOMEÇAR!!" << endl;
					Sleep(1000);
					return; //--> não vou usar porque o jogador não vai sair dos limites do array
					//então não preciso sair da função para não o mover após cair na 
					//armadilha
				}
			}

			if (lab[l][c - 1] == " ") {
				lab[l][c] = " ";
				lab[l][--c] = jog;
			}
			else {
				cout << "\n\tPAREDE!!!";
				Sleep(200);
			}
		}
		else {
			cout << "\n\tMOVIMENTO INVÁLIDO!!!";
			 Sleep(200);
	 
		}
		
	
	}
	void cima(string lab[][COL], string labArm[][COL], int& l, int& c, string jog, int& vidas, int nivel) {
	
		if (nivel == 2 || nivel == 3) {
			if (labArm[l - 1][c] == "A") {
				vidas--;
				lab[l][c] = " ";
				lab[l-1][c] = "A";
				recomecar(lab, l, c, jog);
				cout << "\n\tVocê caiu numa armadilha! Perdeu uma vida!! RECOMEÇAR!!" << endl;
				Sleep(1000);
				return;
			}
		}
		
		if (lab[l - 1][c] == " " || lab[l-1][c] == "F") {
			lab[l][c] = " ";
			lab[--l][c] = jog;
		}
		else {
			cout << "\n\tPAREDE!!!"; 
			Sleep(200); 

		}
	
	}
	void baixo(string lab[][COL], string labArm[][COL], int& l, int& c, string jog, int& vidas, int nivel) {

		if (nivel == 2 || nivel == 3) {
			if (labArm[l + 1][c] == "A") {
				vidas--;
				lab[l][c] = " ";
				lab[l+1][c] = "A";
				recomecar(lab, l, c, jog);
				cout << "\n\tVocê caiu numa armadilha! Perdeu uma vida!! RECOMEÇAR!!" << endl;
				Sleep(1000);
				return;
			}
		}
		
		if (lab[l + 1][c] == " ") {
			lab[l][c] = " ";
			lab[++l][c] = jog;
		}
		else {
			cout << "\n\tPAREDE!!!";
			Sleep(200);

		}
	
	}
	
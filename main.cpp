#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <math.h>

using namespace std;

#define ESC 27
#define MAX_X 120
#define MAX_Y 30
#define MIN_X 0
#define MIN_Y 0

void srodek(int, int, int, char);
void bok1(int, int, int, char);
void bok2(int, int, int, char);
void bok3(int, int, int, char);
void bok4(int, int, int, char);
void menu();
void zmiana(char, int&, int&, int&);
void gotoxy(int x, int y);

int main(){
	int x, y, rozmiar, Esq;
	char klawisz, znak, wybor;
	
	do{ 
		menu();
		wybor=_getch();
		system("cls");
	
		if (wybor==13){	
			cout << "Podaj wysokosc figury w przedziale od 3 do 24 ";
			do{ cin >> rozmiar; }while (rozmiar<3 || rozmiar>24);
			
			rozmiar = rozmiar/2;
			
			cout << "Podaj znak kodu ASCII do narysowania figury ";
			do{ cin >> znak; }while(znak<0 || znak>126);
		
			x=MAX_X/2; 
			y=MAX_Y/2;
			do{ 
				system("cls");
				srodek(x, y, rozmiar, znak);
				bok1(x, y, rozmiar, znak);
				bok2(x, y, rozmiar, znak);
				bok3(x, y, rozmiar, znak);
				bok4(x, y, rozmiar, znak);
				
				klawisz = _getch();
				zmiana(klawisz, rozmiar, x, y);
			
			}while (klawisz != ESC);
		}
		system("cls");
	}while (wybor != ESC);
	
	return 0;
}

void menu(){ 
	cout << " Witaj w programie rysujacym figure \"X\" o podanym znaku i rozmiarze \n\n ";
	cout << " - Uzyj strzalek do przemieszczania figury po ekranie \n ";
	cout << " - Aby powiekszyc lub zmniejszyc figure uzyj odpowienio + lub - \n\n\n ";
	cout << " Menu: \n\n";
	cout << " - Aby rozpoczac rysowanie wcisnij Enter\n";
	cout << " - Aby zakonczyc program lub powrocic do menu w trakcie rysowania wcisnij Esc\n";
};



void zmiana(char klawisz, int &rozmiar, int &x, int &y){
	if (klawisz=='-' && rozmiar > 1) {
		rozmiar=rozmiar-1;
	}
	if (klawisz=='+' && x+rozmiar < MAX_X && y+rozmiar < MAX_Y && x-rozmiar>MIN_X && y-rozmiar>MIN_Y){
		rozmiar=rozmiar+1;
	}
	if (klawisz==75 && x>rozmiar) {
		x--;
	}
	if (klawisz==77 && x+rozmiar<MAX_X) {
		x++;
	}
	if (klawisz==72 && y>rozmiar) {
		y--;
	}
	if (klawisz==80 && y+rozmiar<MAX_Y) {
		y++;
	}

}

void srodek(int x, int y, int rozmiar, char znak){
		gotoxy(x,y);
		cout << znak << "\n";
}

void bok1(int x, int y, int rozmiar, char znak){
	gotoxy(x,y);
	for (int i = 1; i<=rozmiar; i++){
		gotoxy(x+i,y+i);
		cout << znak;
	}
}
void bok2(int x, int y, int rozmiar, char znak){
	gotoxy(x,y);
	for (int i = 1; i<=rozmiar; i++){
		gotoxy(x+i,y-i);
		cout << znak;
	}
}
void bok3(int x, int y, int rozmiar, char znak){
	gotoxy(x,y);
	for (int i = 1; i<=rozmiar; i++){
		gotoxy(x-i,y-i);
		cout << znak;
	}
}
void bok4(int x, int y, int rozmiar, char znak){
	gotoxy(x,y);
	for (int i = 1; i<=rozmiar; i++){
		gotoxy(x-i,y+i);
		cout << znak;
	}
}
void gotoxy(int x, int y){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	_COORD pos;
	pos.X = x;
	pos.Y = y;

	SetConsoleCursorPosition(hConsole, pos);
}
















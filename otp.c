/*Program sluzy do generowania bloczkow kluczy jednorazowych (OTP). 
Kazdy bloczek zawiera 250 znakow zapisanych w 10 wierszach, 
w kazdym wierszu wystepuje piec piecioznakowych grup.

Program nalezy wywolac z jednym argumentem oznaczajacym liczbe generowanych bloczkow np. otp 20. 
Wynik zostanie wyswietlony na ekranie, zazwyczaj chcemy zapisac bloczki w pliku tekstowym.
W takim przypadku nalezy przekierowac wyjscie programu do pliku: otp 20 > plik_kluczy.txt

Program wykorzystuje funkcje rand wiec nie zapewnia dobrej losowosci. 
Wygenerowanych kluczy nie nalezy uzywac do przesylania waznych, poufnych wiadomosci.*/

#include<stdlib.h>
#include<stdio.h>
#include<time.h>

int main(int argc, char* argv[]) {

/*sprawdzenie, czy program został wywołany z jednym argumentem */
if (argc < 2 || argc > 2) {printf("program musi być wywołany z jednym argumentem\n");
  exit(-1);}

/*deklaracje i inicjalizacja zmiennych*/
	float i;
	int wszystkie_znaki;
	char znak;
	int w_grupie = 0;
	int w_bloczku = 0;
	int grupy = 0;
	int rt = 0;

/*ustalenie liczby generowanych bloczków*/	
	long int wygeneruj = strtol(argv[1],NULL,10);

/*inicjalizacja generatora liczb pseudolosowych*/
srand(time(NULL));

/*if sprawdza, czy argument nie jest ujemny*/
if (wygeneruj > 0) {
for(wszystkie_znaki = 0;wszystkie_znaki <= (wygeneruj * 250);wszystkie_znaki ++){
	i = rand() % 25;
	znak = int(i + 65);
	printf("%c",znak);
	w_grupie ++;
	if (w_grupie == 5) {printf("%c",32); w_grupie = 0; grupy ++;}
	if (grupy == 5) {printf("\n"); grupy = 0; w_bloczku ++;}
	if (w_bloczku == 10) {printf("\n"); w_bloczku = 0;}
} }
else {rt = 1;printf("błędny argument\n"); }
return(rt);
}
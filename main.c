#include <locale.h>
#include <stdio.h>
#include <wchar.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "funkcje.h"
#include <unistd.h>

#define SQUARE_BLACK "█"
#define SQUARE_WHITE " "
#define LEFT_UP "┌"
#define RIGHT_UP "┐"
#define LEFT_DOWN "└"
#define RIGHT_DOWN "┘"
#define UP "─"
#define NEXT "│"

int main(int argc, char** argv) 
{
	

	plansza_t plansza;
	mrowka_t mrowka; 
	
	//Wartości w przypadku braku podania argumentow 
	plansza.nazwa = NULL; 
    plansza.w = 10;       
    plansza.k = 10;       
    plansza.proc = 0;    

    mrowka.a = plansza.w/2+1;        
    mrowka.b = plansza.k/2+1;        
    mrowka.przejscia = 2;
	
	
	int opt;
    while ((opt = getopt(argc, argv, "n:w:k:x:y:p:i:")) != -1) {
        switch (opt) 
		{
            case 'n': // nazwa na podstawie ktorej powstana pliki
			if(optarg != NULL)
			{
				plansza.nazwa = strdup(optarg);
                break;
			}
            case 'w': // ilosc wierszy tablicy
			if(optarg != NULL)
			{
				plansza.w = atoi(optarg);
				if(plansza.w <= 0)
				{
					printf("Podano nieprawidłowe wymiary w\n");
					return 1;
				}
                break;
			}
            case 'k': // ilosc kolumn tablicy
			if(optarg != NULL)
			{
				plansza.k = atoi(optarg);
				if(plansza.k <= 0)
				{
					printf("Podano nieprawidłowe wymiary k\n");
					return 1;
				}
                break;
			}
            case 'x': // wiersz dla mrowki
            if(optarg != NULL)
			{				
				mrowka.a = atoi(optarg);
				if(mrowka.a <= 0 || mrowka.a > plansza.w)
				{
					printf("Podano nieprawidłowe położenie mrówki\n");
					return 1;
				}
                break;
			}
			case 'y': // kolumna dla mrowki 
			if(optarg != NULL)
			{
				mrowka.b = atoi(optarg);
				if(mrowka.b <= 0 || mrowka.b > plansza.k)
				{
					printf("Podano nieprawidłowe wymiary k\n");
					return 1;
				}
                break;
			}
			case 'p': // procent losowych pol
			if(optarg != NULL)
			{
				plansza.proc = atoi(optarg);
				if(plansza.proc > 100 || plansza.proc < 0)
				{
					printf("Podano niewłaściwy procent\n");
				}
                break;
			}
			case 'i': //liczba iteracji
			if(optarg != NULL)
			{
				mrowka.przejscia = atoi(optarg);
				if(mrowka.przejscia < 0)
				{
					printf("Podano niewłaściwą liczbę przejść\n");
				}
                break;
			}
				
        }
    }
	
	
	tworzenie_tablicy(&plansza, &mrowka);
	
	ruch_mrowki(&plansza, &mrowka, argc, argv);
	
	return 0;
	
}
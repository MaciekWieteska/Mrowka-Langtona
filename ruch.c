#include <locale.h>
#include <stdio.h>
#include <wchar.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "funkcje.h"
#define SQUARE_BLACK "█"
#define SQUARE_WHITE " "

void ruch_mrowki(plansza_t *plansza, mrowka_t *mrowka, int argc, char** argv)
{
	
	
    // sprawdzenie na początek, czy mrówka może znajdować się we wskazanej lokalizacji 
    char* nazwa = (char*)malloc(sizeof(argv[1]) + 9);
    for(int i = 0; i < mrowka->przejscia + 1; i++) 
	{
		if(mrowka->b > plansza->k || mrowka->b <= 0 || mrowka->a <= 0 || mrowka->a > plansza->w)
			{
				printf("Mrówka wyszła poza obszar");
				exit(1);
			}
			
			
			
		int pom = 0 ;

		FILE *fptr;
		
		if(plansza->nazwa != NULL) // Jak jest nazwa to robimy na podstawie niej plik stdout
		{
			char liczba[6];
			sprintf(liczba, "%d", i );
			strcat(nazwa, plansza->nazwa); 
			strcat(nazwa, liczba);
			strcat(nazwa, ".txt");
			fptr = freopen(nazwa, "w", stdout);
			for(int a = 0; a < strlen(nazwa); a ++)
			{
				nazwa[a] = 0;
			}
		}
		
		printf("Liczba wykonanych przejść: %d\n", i);
		printf("lokalizacja mrówki to:\n");
		printf("wiersz: %d\n", mrowka->a);
		printf("kolumna: %d\n", mrowka->b);
		
		//wypisywanie calosci
		for (int i = 0; i < plansza->w+3; i++) 
		{
			for (int j = 0; j < plansza->k+3; j++) 
			{
				printf("%s", plansza->tab[i][j]);
			}
			printf("\n");
		}
		if(strcmp(plansza->tab[mrowka->a][mrowka->b], "△") == 0 && pom == 0)
		{
			plansza->tab[mrowka->a][mrowka->b] = SQUARE_BLACK;
			mrowka->b++;
			if(mrowka->b > plansza->k)
			{
				printf("Mrówka wyszła poza obszar");
				exit(1);
			}
	
			if(plansza->tab[mrowka->a][mrowka->b] == SQUARE_BLACK)
			{
				plansza->tab[mrowka->a][mrowka->b] = "▶";
			}
			else
			{
				plansza->tab[mrowka->a][mrowka->b] = "▷";
			}
            pom ++; 			
		}
		
		if(strcmp(plansza->tab[mrowka->a][mrowka->b], "▲") == 0 && pom == 0)
		{
			plansza->tab[mrowka->a][mrowka->b] = SQUARE_WHITE;
			mrowka->b--;
			if(mrowka->b == 0)
			{
				printf("Mrówka wyszła poza obszar");
				exit(1);
			}
	
			if(plansza->tab[mrowka->a][mrowka->b] == SQUARE_BLACK)
			{
				plansza->tab[mrowka->a][mrowka->b] = "◀";
			}
			else
			{
				plansza->tab[mrowka->a][mrowka->b] = "◁";
			}
            pom ++; 			
		}
		
		if(strcmp(plansza->tab[mrowka->a][mrowka->b], "▷") == 0 && pom == 0)
		{
			plansza->tab[mrowka->a][mrowka->b] = SQUARE_BLACK;
			mrowka->a++;
			if(mrowka->a > plansza->w)
			{
				printf("Mrówka wyszła poza obszar");
				exit(1);
			}
	
			if(plansza->tab[mrowka->a][mrowka->b] == SQUARE_BLACK)
			{
				plansza->tab[mrowka->a][mrowka->b] = "▼";
			}
			else
			{
				plansza->tab[mrowka->a][mrowka->b] = "▽";
			}		
            pom ++; 			
		}
		
		if(strcmp(plansza->tab[mrowka->a][mrowka->b], "▶") == 0 && pom == 0)
		{
			plansza->tab[mrowka->a][mrowka->b] = SQUARE_WHITE;
			mrowka->a--;
			if(mrowka->a == 0)
			{
				printf("Mrówka wyszła poza obszar");
				exit(1);
			}
	
			if(plansza->tab[mrowka->a][mrowka->b] == SQUARE_BLACK)
			{
				plansza->tab[mrowka->a][mrowka->b] = "▲";
			}
			else
			{
				plansza->tab[mrowka->a][mrowka->b] = "△";
			}	
            pom ++; 			
		}
		
		if(strcmp(plansza->tab[mrowka->a][mrowka->b], "▽") == 0 && pom == 0)
		{
			plansza->tab[mrowka->a][mrowka->b] = SQUARE_BLACK;
			mrowka->b--;
			if(mrowka->b == 0)
			{
				printf("Mrówka wyszła poza obszar");
				exit(1);
			}
	
			if(plansza->tab[mrowka->a][mrowka->b] == SQUARE_BLACK)
			{
				plansza->tab[mrowka->a][mrowka->b] = "◀";
			}
			else
			{
				plansza->tab[mrowka->a][mrowka->b] = "◁";
			}		
            pom ++; 			
		}
		
		if(strcmp(plansza->tab[mrowka->a][mrowka->b], "▼") == 0 && pom == 0)
		{
			plansza->tab[mrowka->a][mrowka->b] = SQUARE_WHITE;
			mrowka->b++;
			if(mrowka->b > plansza->k)
			{
				printf("Mrówka wyszła poza obszar");
				exit(1);
			}
	
			if(plansza->tab[mrowka->a][mrowka->b] == SQUARE_BLACK)
			{
				plansza->tab[mrowka->a][mrowka->b] = "▶";
			}
			else
			{
				plansza->tab[mrowka->a][mrowka->b] = "▷";
			}	
            pom ++; 			
		}
		
		if(strcmp(plansza->tab[mrowka->a][mrowka->b], "◁") == 0 && pom == 0)
		{
			plansza->tab[mrowka->a][mrowka->b] = SQUARE_BLACK;
			mrowka->a--;
			if(mrowka->a == 0)
			{
				printf("Mrówka wyszła poza obszar");
				exit(1);
			}
	
			if(plansza->tab[mrowka->a][mrowka->b] == SQUARE_BLACK)
			{
				plansza->tab[mrowka->a][mrowka->b] = "▲";
			}
			else
			{
				plansza->tab[mrowka->a][mrowka->b] = "△";
			}	
            pom ++; 			
		}
		
		if(strcmp(plansza->tab[mrowka->a][mrowka->b], "◀") == 0 && pom == 0)
		{
			plansza->tab[mrowka->a][mrowka->b] = SQUARE_WHITE;
			mrowka->a++;
			if(mrowka->a > plansza->w)
			{
				printf("Mrówka wyszła poza obszar");
				exit(1);
			}
	
			if(plansza->tab[mrowka->a][mrowka->b] == SQUARE_BLACK)
			{
				plansza->tab[mrowka->a][mrowka->b] = "▼";
			}
			else
			{
				plansza->tab[mrowka->a][mrowka->b] = "▽";
			}	
            pom ++; 			
		}
		

		
		if(plansza->nazwa != NULL) // Zamykamy plik po iteracji
		{
			fclose(fptr);
		}
	}
}
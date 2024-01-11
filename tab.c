#include <locale.h>
#include <stdio.h>
#include <wchar.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "funkcje.h"

#define SQUARE_BLACK "█"
#define SQUARE_WHITE " "
#define LEFT_UP "┌"
#define RIGHT_UP "┐"
#define LEFT_DOWN "└"
#define RIGHT_DOWN "┘"
#define UP "─"
#define NEXT "│"

void tworzenie_tablicy(plansza_t *plansza, mrowka_t *mrowka)
{
	 //(Rezerwowanie miejsca w pamięci na ramkę)
    plansza->tab = malloc((plansza->w+3) * sizeof(char**));
    for (int i = 0; i < (plansza->w+3); i++) 
	{
		plansza->tab[i] = malloc((plansza->k+3)* sizeof(char*));
		for(int j = 0; j < (plansza->k+3); j++)
		{
			plansza->tab[i][j] = malloc(6);
		}
	}
	
	
	
	
	
	plansza->tab[0][0]= LEFT_UP;
   plansza->tab[0][plansza->k+2]= RIGHT_UP;
   plansza->tab[plansza->w+1][0]= LEFT_DOWN;
   plansza->tab[plansza->w+1][plansza->k+1]= RIGHT_DOWN;
   
   for(int i=1;i<plansza->k+1;i++)
   {
	   plansza->tab[0][i] = UP;
	   }
	   for(int i=1;i<plansza->k+1;i++)
	   {
          plansza->tab[plansza->w+1][i] = UP;
		  }
		  for(int i=1; i<plansza->w+1; i++)
		  {
			  plansza->tab[i][0]= NEXT;
		   }
   for(int i=1; i<plansza->w+1; i++)
   {
           plansza->tab[i][plansza->k+1]= NEXT;
		   }
   
   //wpisywanie kwadratow bialych
   
   for (int i = 1; i < plansza->w+1; i++) {
        for (int j = 1; j < plansza->k+1; j++) {
            plansza->tab[i][j] = SQUARE_WHITE;
        }
     }
	 
   //wypisywanie kwadratow czarnych razem z losowaniem
   if(plansza->proc == 100){
	for (int i = 1; i < plansza->w+1; i++) 
	{
        for (int j = 1; j < plansza->k+1; j++) 
	{
            plansza->tab[i][j] = SQUARE_BLACK;
        }
     }}
   float ile = (plansza->w * plansza->k * plansza->proc) / 100;
   if(ile>0){
	   for (int i =0 ; i<ile; i++){
		int x = rand() % (plansza->k - 1 + 1) + 1;
		int y = rand() % (plansza->w - 1 + 1) + 1;
		plansza->tab[y][x]= SQUARE_BLACK;
          } 
}



// Pozycjonowanie mrówki na mapie
    if(plansza->tab[mrowka->a][mrowka->b] == SQUARE_BLACK)
	{
		plansza->tab[mrowka->a][mrowka->b] = "▲";
	}
	else
	{
		plansza->tab[mrowka->a][mrowka->b] = "△";
	}
}

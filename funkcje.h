typedef struct{
	char *** tab; 
	int w; 
	int k;
	int proc;
	char* nazwa;
} plansza_t;

typedef struct{
	int a; 
	int b;
	int przejscia;
} mrowka_t;

void tworzenie_tablicy(plansza_t *plansza, mrowka_t *mrowka); 

void ruch_mrowki(plansza_t *plansza, mrowka_t *mrowka, int argc, char** argv);

Aby uruchomić program należy najpierw skompilować jego elementy przy użyciu komendy make. 
Uruchomienie następuje przez uruchomienie pliku wynikowego(maszynowego) wpisując ./a.out. 
Bez wpisania dodatkowych argumentów program wykorzystane zdefiniowane przez autora przykładowe wartości.
Podstawowe zmienne i flagi, które można wykorzystać są następujące: 

Wiersze tabeli (-w) liczba wierszy planszy 
Kolumny tabeli (-k) liczba kolumn planszy
Wiersze dla mrówki(-x) położenie wierszowe mrówki na planszy
Kolumny dla mrówki(-y) położenie kolumnowe mrówki na planszy
Procent losowo zamalowanych na czarno pól(-p) 
Ilość iteracji mróki (-i) ile ruchów wykona mrówka
Przedrostek nazwy plików wynikowych(-n) 

Przykładowe wywołanie ze wszystkimi flagami wygląda następująco:
./a.out -w 10 -k 10 -x 5 -y 5 -p 0 -i 4 -n mrowka
Wynikiem będzie powstanie 5 plików wynikowych o wzorze mrowka(liczba od 0 do 4).txt

Można też wpisać tylko wybrane flagi w dowolnej kolejności
Wyrażenie: 
./a.out -k 10 -w 7 -y 4 -p 20 

Brak nazwy skutuje wypisaniem wyniku programu do stdout, zaś brakujące wartości liczbowe zostaną zastąpione predefiniowanymi.  

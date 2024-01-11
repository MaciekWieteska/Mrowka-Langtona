a.out: main.o tab.o ruch.o 
	$(CC) $^

main.o: funkcje.h
tab.o: funkcje.h
ruch.o: funkcje.h

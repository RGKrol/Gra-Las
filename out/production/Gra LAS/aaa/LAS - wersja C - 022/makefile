# fonto - źródło
FONTOJ = las.c las-funk-proste.c las-funkcje.c
FONTOBJEKTOJ = $(patsubst %.c, %.o, $(FONTOJ))

#tradukilo - kompilator
CC = gcc
#flago - flaga
FLAGOJ = -Wall


all: las

clean: 
	rm $(FONTOBJEKTOJ)
	
.PHONY: all clean


las : las.o las-funk-proste.o las-funkcje.o
	$(CC) $(FLAGOJ) -o $@ $^
	
%.o: %.c
	$(CC) $(FLAGOJ) -c -o $@ $^

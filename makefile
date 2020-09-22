OBJPATH := ./out/
INCPATH := ./inc/
SRCPATH := ./src/
CFLAGS := -std=c99 -Wall -Wextra -Wpedantic -Werror -g3
.PHONY: clean

app.exe: $(OBJPATH)io.o $(OBJPATH)main.o
	gcc $(OBJPATH)io.o $(OBJPATH)main.o -o app.exe

$(OBJPATH)main.o: $(SRCPATH)main.c
	gcc $(CFLAGS) -c $(SRCPATH)main.c -o $(OBJPATH)main.o

$(OBJPATH)io.o: $(SRCPATH)io.c $(INCPATH)io.h
	gcc $(CFLAGS) -c $(SRCPATH)io.c -o $(OBJPATH)io.o

clean:
	rm -rf *.exe out
	mkdir out
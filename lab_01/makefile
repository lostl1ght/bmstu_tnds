CC := gcc
OBJPATH := ./out/
INCPATH := ./inc/
SRCPATH := ./src/
CFLAGS := -std=c99 -Wall -Wextra -Wpedantic -Werror

.NOTPARALLEL: release debug
.PHONY: release debug
release: CFLAGS += -g0 -O0
release: $(OBJPATH)release.lastbuildstate app.exe

debug: CFLAGS += -g3 -O0
debug: $(OBJPATH)debug.lastbuildstate app.exe

$(OBJPATH)release.lastbuildstate:
	rm -rf *.exe $(OBJPATH)
	mkdir $(OBJPATH)
	touch $(OBJPATH)release.lastbuildstate

$(OBJPATH)debug.lastbuildstate:
	rm -rf *.exe $(OBJPATH)
	mkdir $(OBJPATH)
	touch $(OBJPATH)debug.lastbuildstate


app.exe: $(OBJPATH)io.o $(OBJPATH)parse.o $(OBJPATH)check.o $(OBJPATH)main.o
	$(CC) $(OBJPATH)io.o $(OBJPATH)parse.o $(OBJPATH)check.o $(OBJPATH)main.o -o app.exe

$(OBJPATH)main.o: $(SRCPATH)main.c
	$(CC) $(CFLAGS) -c $(SRCPATH)main.c -o $(OBJPATH)main.o

$(OBJPATH)io.o: $(SRCPATH)io.c $(INCPATH)io.h
	$(CC) $(CFLAGS) -c $(SRCPATH)io.c -o $(OBJPATH)io.o

$(OBJPATH)parse.o: $(SRCPATH)parse.c $(INCPATH)parse.h
	$(CC) $(CFLAGS) -c $(SRCPATH)parse.c -o $(OBJPATH)parse.o

$(OBJPATH)check.o: $(SRCPATH)check.c $(INCPATH)check.h
	$(CC) $(CFLAGS) -c $(SRCPATH)check.c -o $(OBJPATH)check.o

.PHONY: clean
clean:
	rm -rf *.exe $(OBJPATH)
	mkdir $(OBJPATH)
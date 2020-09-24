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


app.exe: $(OBJPATH)io.o $(OBJPATH)parse.o $(OBJPATH)main.o
	gcc $(OBJPATH)io.o $(OBJPATH)parse.o $(OBJPATH)main.o -o app.exe

$(OBJPATH)main.o: $(SRCPATH)main.c
	gcc $(CFLAGS) -c $(SRCPATH)main.c -o $(OBJPATH)main.o

$(OBJPATH)io.o: $(SRCPATH)io.c $(INCPATH)io.h
	gcc $(CFLAGS) -c $(SRCPATH)io.c -o $(OBJPATH)io.o

$(OBJPATH)parse.o: $(SRCPATH)parse.c $(INCPATH)parse.h
	gcc $(CFLAGS) -c $(SRCPATH)parse.c -o $(OBJPATH)parse.o

.PHONY: clean
clean:
	rm -rf *.exe $(OBJPATH)
	mkdir $(OBJPATH)
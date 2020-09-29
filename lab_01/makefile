CC := gcc
OBJPATH := ./out/
INCPATH := ./inc/
SRCPATH := ./src/
CFLAGS := -std=c99 -Wall -Wextra -Wpedantic -Werror
.NOTPARALLEL: release debug
.PHONY: release debug clean

release: CFLAGS += -g0 -O0
release: $(OBJPATH) $(OBJPATH)release.lastbuildstate app.exe 

debug: CFLAGS += -g3 -O0
debug: $(OBJPATH) $(OBJPATH)debug.lastbuildstate app.exe

$(OBJPATH)release.lastbuildstate:
	rm -rf *.exe $(OBJPATH)
	mkdir $(OBJPATH)
	touch $(OBJPATH)release.lastbuildstate

$(OBJPATH)debug.lastbuildstate:
	rm -rf *.exe $(OBJPATH)
	mkdir $(OBJPATH)
	touch $(OBJPATH)debug.lastbuildstate

$(OBJPATH):
	mkdir $(OBJPATH)

app.exe: $(OBJPATH)main.o $(OBJPATH)io.o $(OBJPATH)parse.o $(OBJPATH)check.o $(OBJPATH)multiply.o
	$(CC) $^ -o app.exe

$(OBJPATH)main.o: $(SRCPATH)main.c $(INCPATH)number.h $(INCPATH)io.h $(INCPATH)parse.h $(INCPATH)check.h $(INCPATH)multiply.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJPATH)io.o: $(SRCPATH)io.c $(INCPATH)io.h $(INCPATH)number.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJPATH)parse.o: $(SRCPATH)parse.c $(INCPATH)parse.h $(INCPATH)number.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJPATH)check.o: $(SRCPATH)check.c $(INCPATH)check.h $(INCPATH)number.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJPATH)multiply.o: $(SRCPATH)multiply.c $(INCPATH)multiply.h $(INCPATH)number.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf *.exe $(OBJPATH)
	mkdir $(OBJPATH)
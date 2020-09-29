CC := gcc
OBJPATH := ./out/
INCPATH := ./inc/
SRCPATH := ./src/
CFLAGS := -std=c99 -Wall -Wextra -Wpedantic -Werror
OBJS := $(OBJPATH)main.o $(OBJPATH)inpt_oupt.o $(OBJPATH)parse.o $(OBJPATH)checking.o $(OBJPATH)multiply.o
# SRCS := $(SRCPATH)main.c $(SRCPATH)inpt_oupt.c $(SRCPATH)parse.c $(SRCPATH)checking.c $(SRCPATH)multiply.c
# DS := $(OBJPATH)main.d $(OBJPATH)inpt_oupt.d $(OBJPATH)parse.d $(OBJPATH)checking.d $(OBJPATH)multiply.d
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

app.exe: $(OBJS)
	$(CC) -I$(INCPATH) $^ -o app.exe

# %.o : %.c
# 	$(CC) $(CFLAGS) -c $<

# %.d : %.c
# 	$(CC) -MM $< > $@

# include $(DS)

$(OBJPATH)main.o: $(SRCPATH)main.c $(INCPATH)number.h $(INCPATH)inpt_oupt.h $(INCPATH)parse.h $(INCPATH)checking.h $(INCPATH)multiply.h
	$(CC) -I$(INCPATH) $(CFLAGS) -c $< -o $@

$(OBJPATH)inpt_oupt.o: $(SRCPATH)inpt_oupt.c $(INCPATH)inpt_oupt.h $(INCPATH)number.h
	$(CC) -I$(INCPATH) $(CFLAGS) -c $< -o $@

$(OBJPATH)parse.o: $(SRCPATH)parse.c $(INCPATH)parse.h $(INCPATH)number.h
	$(CC) -I$(INCPATH) $(CFLAGS) -c $< -o $@

$(OBJPATH)checking.o: $(SRCPATH)checking.c $(INCPATH)checking.h $(INCPATH)number.h
	$(CC) -I$(INCPATH) $(CFLAGS) -c $< -o $@

$(OBJPATH)multiply.o: $(SRCPATH)multiply.c $(INCPATH)multiply.h $(INCPATH)number.h
	$(CC) -I$(INCPATH) $(CFLAGS) -c $< -o $@

clean:
	rm -rf *.exe $(OBJPATH)
	mkdir $(OBJPATH)
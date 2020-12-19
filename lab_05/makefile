CC = gcc
OUTPATH = ./out/
INCPATH = ./inc/
SRCPATH = ./src/
CFLAGS = -std=c99 -Wall -Wextra -Wpedantic -Werror -Wfloat-conversion -O0
LIBS = -lm

SRCS = $(wildcard $(SRCPATH)*.c)

.NOTPARALLEL: release debug
.PHONY: release debug clean dir deps

release: CFLAGS += -g0
release: $(OUTPATH)release.lastbuildstate app.exe

debug: CFLAGS += -g3
debug: $(OUTPATH)debug.lastbuildstate app.exe

unit: $(OUTPATH)unit.lastbuildstate unit_tests.exe
	 $(MEMCHECK) $(MEMFLAGS) ./unit_tests.exe

app.exe: $(SRCS:$(SRCPATH)%.c=$(OUTPATH)%.o)
	$(CC) $(CFLAGS) $^ -o app.exe $(LIBS)

$(OUTPATH)%.o: $(SRCPATH)%.c | dir
	$(CC) -I$(INCPATH) $(CFLAGS) -c $< -o $@

$(OUTPATH)%.d: $(SRCPATH)%.c | dir
	$(CC) -I$(INCPATH) -MM -MT $(patsubst %.d,%.o,$@) $< > $@

ifeq ($(MAKECMDGOALS),)
include $(SRCS:$(SRCPATH)%.c=$(OUTPATH)%.d)
else
ifeq ($(MAKECMDGOALS), $(filter $(MAKECMDGOALS), release debug app.exe func))
include $(SRCS:$(SRCPATH)%.c=$(OUTPATH)%.d)
endif
endif

$(OUTPATH)%.lastbuildstate: | dir
	rm -rf *.exe $(OUTPATH)*.o $(OUTPATH)*.gcov $(OUTPATH)*.gcda $(OUTPATH)*.gcno $(OUTPATH)*.lastbuildstate
	touch $@

dir:
	mkdir -p $(OUTPATH)

clean:
	rm -rf *.exe $(OUTPATH)*.o $(OUTPATH)*.gcov $(OUTPATH)*.gcda $(OUTPATH)*.gcno $(OUTPATH)*.lastbuildstate $(OUTPATH)*.d

deps:
	rm -f $(OUTPATH)*.d
	make $(SRCS:$(SRCPATH)%.c=$(OUTPATH)%.d)	

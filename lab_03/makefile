CC = gcc
OUTPATH = ./out/
INCPATH = ./inc/
SRCPATH = ./src/
CFLAGS = -std=c99 -Wall -Wextra -Wpedantic -Werror -Wfloat-conversion -O0

SRCS = $(wildcard $(SRCPATH)*.c)

.NOTPARALLEL: release debug func deps
.PHONY: release debug clean dir deps func unit

release: CFLAGS += -g0
release: $(OUTPATH)release.lastbuildstate app.exe

debug: CFLAGS += -g3
debug: $(OUTPATH)debug.lastbuildstate app.exe

app.exe: $(SRCS:$(SRCPATH)%.c=$(OUTPATH)%.o)
	$(CC) $(CFLAGS) $^ -o app.exe

$(OUTPATH)%.o: $(SRCPATH)%.c | dir
	$(CC) -I$(INCPATH) $(CFLAGS) -c $< -o $@

$(OUTPATH)%.d: $(SRCPATH)%.c | dir
	$(CC) -I$(INCPATH) -MM -MT $(patsubst %.d,%.o,$@) $< > $@

ifeq ($(MAKECMDGOALS),)
include $(SRCS:$(SRCPATH)%.c=$(OUTPATH)%.d)
else
ifeq ($(MAKECMDGOALS), $(filter $(MAKECMDGOALS), release debug app.exe func))
include $(SRCS:$(SRCPATH)%.c=$(OUTPATH)%.d)
else
endif
endif

$(OUTPATH)%.lastbuildstate: | dir
	rm -rf *.exe $(OUTPATH)*.o $(OUTPATH)*.gcov $(OUTPATH)*.gcda $(OUTPATH)*.gcno $(OUTPATH)*.lastbuildstate
	touch $@

dir:
	mkdir -p $(OUTPATH)

clean:
	rm -rf *.exe $(OUTPATH)
	mkdir $(OUTPATH)

deps:
	rm -f $(OUTPATH)*.d
	make $(SRCS:$(SRCPATH)%.c=$(OUTPATH)%.d)	

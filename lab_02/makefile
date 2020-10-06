CC := gcc
OUTPATH := ./out/
INCPATH := ./inc/
SRCPATH := ./src/
UNIPATH := ./unit_tests/
CFLAGS := -std=c99 -Wall -Wextra -Wpedantic -Werror

SRCS := $(wildcard $(SRCPATH)*.c)

.NOTPARALLEL: release debug
.PHONY: release debug clean dir d

release: CFLAGS += -g0 -O0
release: $(OUTPATH)release.lastbuildstate app.exe

debug: CFLAGS += -g3 -O0
debug: $(OUTPATH)debug.lastbuildstate app.exe

app.exe: $(SRCS:$(SRCPATH)%.c=$(OUTPATH)%.o)
	$(CC) $^ -o app.exe

unit_tests.exe: check_main.o
	$(CC) $^ -o $@

$(OUTPATH)%.o: $(SRCPATH)%.c | dir
	$(CC) -I$(INCPATH) $(CFLAGS) -c $< -o $@

$(OUTPATH)%.o: $(UNIPATH)%.c | dir
	$(CC) -I$(UNIPATH) $(CFLAGS) -c $< -o $@

$(OUTPATH)%.d: $(SRCPATH)%.c | dir
	$(CC) -I$(INCPATH) -MM -MT $(patsubst %.d,%.o,$@) $< > $@

$(OUTPATH)%.d: $(UNIPATH)%.c | dir
	$(CC) -I$(UNIPATH) -MM -MT $(patsubst %.d,%.o,$@) $< > $@

ifeq ($(MAKECMDGOALS),)
include $(SRCS:$(SRCPATH)%.c=$(OUTPATH)%.d)
else
ifeq ($(MAKECMDGOALS), release)
include $(SRCS:$(SRCPATH)%.c=$(OUTPATH)%.d)
else
ifeq ($(MAKECMDGOALS), debug)
include $(SRCS:$(SRCPATH)%.c=$(OUTPATH)%.d)
else
ifeq ($(MAKECMDGOALS), app.exe)
include $(SRCS:$(SRCPATH)%.c=$(OUTPATH)%.d)
endif
endif
endif
endif

$(OUTPATH)release.lastbuildstate: | dir
	rm -rf *.exe $(OUTPATH)*.o $(OUTPATH)debug.lastbuildstate
	touch $(OUTPATH)release.lastbuildstate

$(OUTPATH)debug.lastbuildstate: | dir
	rm -rf *.exe $(OUTPATH)*.o $(OUTPATH)release.lastbuildstate
	touch $(OUTPATH)debug.lastbuildstate

dir:
	mkdir -p $(OUTPATH)

clean:
	rm -rf *.exe $(OUTPATH)
	mkdir $(OUTPATH)

deps:
	rm -f $(OUTPATH)*.d
	make $(SRCS:$(SRCPATH)%.c=$(OUTPATH)%.d)	

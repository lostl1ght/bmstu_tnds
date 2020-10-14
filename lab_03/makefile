CC = gcc
OUTPATH = ./out/
INCPATH = ./inc/
SRCPATH = ./src/
UNIPATH = ./unit_tests/
CFLAGS = -std=c99 -Wall -Wextra -Wpedantic -Werror -O0

SRCS = $(wildcard $(SRCPATH)*.c)

# В этой строке указываются юниты для тестирования. Все остальное работает автоматически.
USRCSF = # $(SRCPATH)sorting.c $(SRCPATH)filtering.c
USRCSC = $(wildcard $(UNIPATH)*.c)

.NOTPARALLEL: release debug func
.PHONY: release debug clean dir deps func unit

release: CFLAGS += -g0
release: $(OUTPATH)release.lastbuildstate app.exe

debug: CFLAGS += -g3
debug: $(OUTPATH)debug.lastbuildstate app.exe

func: CFLAGS += -g0 --coverage
func: $(OUTPATH)func.lastbuildstate app.exe
	cd func_tests && ./all_tests.cmd
	gcov $(SRCS:$(SRCPATH)%.c=$(OUTPATH)%.o)
	mv *.gcov $(OUTPATH)

unit: unit_tests.exe
	drmemory -batch -lib_blacklist "*" -- unit_tests.exe

app.exe: $(SRCS:$(SRCPATH)%.c=$(OUTPATH)%.o)
	$(CC) $(CFLAGS) $^ -o app.exe

unit_tests.exe: $(USRCSF:$(SRCPATH)%.c=$(OUTPATH)%.o) $(USRCSC:$(UNIPATH)%.c=$(OUTPATH)%.o)
	$(CC) $(CFLAGS) $^ -o $@ -lcheck

$(OUTPATH)%.o: $(SRCPATH)%.c | dir
	$(CC) -I$(INCPATH) $(CFLAGS) -c $< -o $@

$(OUTPATH)%.o: $(UNIPATH)%.c | dir
	$(CC) -I$(UNIPATH) -I$(INCPATH) $(CFLAGS) -c $< -o $@

$(OUTPATH)%.d: $(SRCPATH)%.c | dir
	$(CC) -I$(INCPATH) -MM -MT $(patsubst %.d,%.o,$@) $< > $@

$(OUTPATH)%.d: $(UNIPATH)%.c | dir
	$(CC) -I$(UNIPATH) -I$(INCPATH) -MM -MT $(patsubst %.d,%.o,$@) $< > $@

ifeq ($(MAKECMDGOALS),)
include $(SRCS:$(SRCPATH)%.c=$(OUTPATH)%.d)
else
ifeq ($(MAKECMDGOALS), $(filter $(MAKECMDGOALS), release debug app.exe func))
include $(SRCS:$(SRCPATH)%.c=$(OUTPATH)%.d)
else
ifeq ($(MAKECMDGOALS), $(filter $(MAKECMDGOALS), unit unit_tests.exe))
include $(USRCSF:$(SRCPATH)%.c=$(OUTPATH)%.d)
include $(USRCSC:$(UNIPATH)%.c=$(OUTPATH)%.d)
endif
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

CFLAGS= -mno-mips16 -mgp32 -mfp32 -gpubnames  -mlong32 -mips1 -mabicalls -mlong-calls -mframe-header-opt -march=r2k

OBJS= tp2

all: tp2 tp2_pf

prof: tp2_pf

tp2: main.c command.c cache.c set.c way.c fileReader.c commandParser.c commandExecutor.c addressHelper.c mainMemory.c strutil.c
	gcc -g $^ -o $@

tp2_pf: main.c command.c cache.c set.c way.c fileReader.c commandParser.c commandExecutor.c addressHelper.c mainMemory.c strutil.c
	gcc -no-pie -pg -g $^ -o $@

clean:
	rm tp2*
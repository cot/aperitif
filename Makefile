CC = gcc
EXTLIB=./extlib/lib/libwlm.so
LDFLAGS= -lslurm -ljansson
INCLUDE=./include/
SRC=./src

all:
	${CC} ${SRC}/*.c ${EXTLIB} -o wlm_skore ${LDFLAGS} -I${INCLUDE}

clean:
	rm -f wlm_skore


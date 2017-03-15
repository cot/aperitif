CC = gcc
LDFLAGS=-ljansson -lslurm
INCLUDE=./include/
LIB=./lib/
SRC=./src/
SHARED=-fPIC -shared

all:
	${CC} ${SRC}/* -I${INCLUDE} ${LDFLAGS} ${SHARED} -o ${LIB}/libwlm.so

clean:
	rm -f ${LIB}/libwlm.so


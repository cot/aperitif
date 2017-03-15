#!/bin/bash

gcc src/slurm_to_json.c src/slurm_get_all.c -I./include/ -ljansson -lslurm -fPIC -shared -o ./lib/libwlm.so
#gcc src/*.c -I./include -I${INCLUDEPATH} -fPIC -shared -o ../lib/libwlm.so 


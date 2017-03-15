#!/bin/bash
gcc wlm_skore.c ../extlib/lib/libwlm.so -o wlm_skore -lslurm -ljansson -I../include/


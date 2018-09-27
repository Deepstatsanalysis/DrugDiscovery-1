#!/bin/bash
make
./program1.out $1
./minisat "$1.satinput" "$1.satoutput"
./program2.out $1
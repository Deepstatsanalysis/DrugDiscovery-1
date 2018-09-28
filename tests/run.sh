#!/bin/bash
echo "Making"
time make
echo "Running Program 1"
time ./program1.out $1
echo "Running Minisat"
time ./minisat "$1.satinput" "$1.satoutput"
echo "Running Program 2"
time ./program2.out $1
echo "Checking"
time python checker.py "$1.graph" "$1.subgraphs"
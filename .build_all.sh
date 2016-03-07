#!/bin/bash
ERR=0
for l in cpp f90 ; do
  cd $l
  make clean cg.x
  ERR1=$?
  ERR=$((ERR||ERR1))
  for d in $(find . -type d) ; do
    cd $d
    make clean cg.x
    ERR1=$?
    ERR=$((ERR||ERR1))
    cd -
  done
done
exit $ERR

#!/bin/sh


i=0

while [ ${i} -lt 400 ]
  do
    rm ${i}
    i=`expr ${i} + 1`
  done

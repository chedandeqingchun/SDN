#!/bin/bash

nums=$1

generate() {
  i=0
  while [ ${i} -lt ${nums} ];
    do
      echo -ne $((RANDOM % 1000))\\t 
      i=`expr $i + 1`
    done
}

generate

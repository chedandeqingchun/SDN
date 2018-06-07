#!/bin/bash


WORK_DIR=./liuoffer/


create(){
  i=1
  cd ${WORK_DIR}

  while [ $i -lt 11 ]
  do
    touch `cat /dev/urandom | tr -dc "a-z" | head -c 10`_offer.html
    i=`expr $i + 1`
  done
}

check(){

  if [ -d ${WORK_DIR} ];
  then
    create
  else
    mkdir ${WORK_DIR}
    create
  fi
}

check

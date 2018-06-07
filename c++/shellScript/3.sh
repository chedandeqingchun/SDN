#!/bin/bash


WORK_DIR=./liuoffer
FILE=`ls ${WORK_DIR}`


changeName() {

  for i in ${FILE}
  do
    name=`echo ${i} | cut -c 1-10`
    mv ${WORK_DIR}/${name}*  ${WORK_DIR}/${name}liu.html
  done
}

changeName

#!/bin/bash

WORK_DIR=./liuoffer
FILE=`ls ${WORK_DIR}`


changeName() {

  for i in ${FILE}
  do
    name=`echo ${i} | awk -F '.' '{print $1}'`
    echo ${name}
    mv ${WORK_DIR}/${name}*  ${WORK_DIR}/${name}liu.html
  done
}

changeName

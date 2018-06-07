#!/bin/bash

user=liudj

addUser(){
  i=1

  while [ ${i} -lt 11 ]
  do
    password=`cat /dev/urandom | tr -dc "0-9a-zA-Z"|head -c 8`
    username=${user}${i}
    useradd ${user}${i} 
    echo ${passwd} | passwd -stdin
    echo ${user}$i-----${password} >> users

    i=`expr $i + 1`
  done
}

delUser() {
  i=1
  while [ ${i} -lt 11 ]
  do
    userdel ${user}${i}
    rm -rfv /home/${user}${i}
    echo del ${user}${i} 
    i=`expr $i + 1`
  done
}


case $1 in
  add)
    addUser
  ;;

  del)
    delUser
  ;;
  *)
  echo "Usage: 1 or 0"
  ;;
esac

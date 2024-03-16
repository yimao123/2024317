#! /bin/bash

foo(){
	echo "这是一个函数"
	echo '$*' is $*
	echo $1 $2 $3
	return 123
}


foo 11 22 33

echo $?



echo '$0' is $0
echo '$@' is $@
echo '$#' is $#

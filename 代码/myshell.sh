#!/bin/sh


VARNAME=123

#常见写法
if [ $VARNAME -lt 123 ] ; then
	echo 'heima greate'
else 
	echo 'itcast greate'
fi


if test $VARNAME -eq 456 
then
	echo 'heima greate'
elif [ $VARNAME < 456 ];then
	echo 'itcast greate'
else
	echo 'very good'
fi


VAR="itcast"

if [ $VAR = "heima" ] ; then 
	echo 111
else
	echo 222
fi

if [ -d ~/.barc ] ; then
	. ~/.bashrc 
else
	echo 文件类型不匹配
fi

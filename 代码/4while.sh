#!/bin/bash

echo "请输入用户名:"

read NAME

while [ $NAME = "itcast" ] ; do 
	echo "请输入密码:"
	read PassWD
	if [ $PassWD = "heima" ] ; then
	       echo "登录成功"
	       break
	else
 		echo "密码错误,请重新输入"
	fi
done	


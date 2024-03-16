#!/bin/sh

echo "请输入今天天气(晴/阴):"

read TIANQI

case "$TIANQI" in
	"晴")
		echo "当前天气晴";;
	"阴")
		echo "当前天气阴天";;
	*)
		echo "用户输入不匹配";;
esac

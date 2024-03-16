#! /bin/bash

echo "是否确认下载这些内容(y/n)"

read YES_NO

case "$YES_NO" in
	y|Y|yes|Yes)
		echo "下载中...";;
	n|N|No|no)
		echo "终止下载";;
	*)
		echo "用户输入错误";;
esac

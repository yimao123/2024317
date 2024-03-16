#!/bin/bash


for Fruit in `ls ~`; do
       if [ -f ~/$Fruit ] ; then
	       echo $Fruit is file
       elif [ -d ~/$Fruit ] ; then
	       echo $Fruit is DIR
       else
	       echo $Fruit is specia file
       fi
done       

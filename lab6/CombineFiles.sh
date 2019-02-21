#!/bin/bash
file1=$(<$2)
file2=$(<$3)
echo $file1 > $1
echo $file2 >> $1

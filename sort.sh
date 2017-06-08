#!/bin/bash

#Sort dictionary file and save it in a temporary file
sort /home/isshu/QtProjects/Dictionary/eng_Dict.csv > /home/isshu/QtProjects/Dictionary/tmp.csv

#Copy sorted file to its original file
cp /home/isshu/QtProjects/Dictionary/tmp.csv /home/isshu/QtProjects/Dictionary/eng_Dict.csv

#Print
echo "Done sorting eng_Dict"

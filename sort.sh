#!/bin/bash

#Sort dictionary file and save it in a temporary file
sort /home/isshu/Qt_projects/Dictionary_Project/eng_Dict.csv > /home/isshu/Qt_projects/Dictionary_Project/tmp.csv

#Copy sorted file to its original file
cp /home/isshu/Qt_projects/Dictionary_Project/tmp.csv /home/isshu/Qt_projects/Dictionary_Project/eng_Dict.csv

#Print
echo "Done sorting eng_Dict"

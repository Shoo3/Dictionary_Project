#include "mainwindow.h"
#include "table.h"
#include <QApplication>
#include <stdio.h>
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Table new_table("/home/isshu/Qt_projects/Dictionary_Project", "eng_Dict.csv");
    new_table.add_entry("add","hinzufügen");
    new_table.add_entry("copy","kopieren");
    new_table.add_entry("shit","Die Scheiße");
    cout << "Error Code: " << new_table.remove_entry("fish") << endl;

    return a.exec();
}


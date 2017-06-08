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

    Table new_table("eng_Dict.csv");
    new_table.add_entry("fish","Der Fisch");
    new_table.remove_entry("fish");

    return a.exec();
}


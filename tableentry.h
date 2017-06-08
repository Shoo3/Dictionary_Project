#ifndef TABLEENTRY_H
#define TABLEENTRY_H

#include <iostream>
using namespace std;

class TableEntry
{
public:
    TableEntry();
    TableEntry(string new_word, string new_meaning);
    string get_word();
    string get_meaning();
    int get_difficulty();

private:
    string word;
    string meaning;
    int difficulty;
};

#endif // TABLEENTRY_H

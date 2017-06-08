#include "tableentry.h"
#include <string>

TableEntry::TableEntry()
{
    word = "";
    meaning = "";
    difficulty = 0;
}

TableEntry::TableEntry(string new_word, string new_meaning)
{
    word = new_word;
    meaning = new_meaning;
    difficulty = 0;
}

string TableEntry::get_word(){
    return word;
}

string TableEntry::get_meaning(){
    return meaning;
}

int TableEntry::get_difficulty(){
    return difficulty;
}


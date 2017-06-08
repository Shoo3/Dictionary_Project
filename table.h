#ifndef TABLE_H
#define TABLE_H

#include <iostream>
#include <fstream>

using namespace std;

class Table
{
public:
    Table(string my_path, string file_name);
    ~Table();
    void set_path(string my_path);
    void add_entry(string word, string meaning);
    int search(string word);
    int remove_entry(string word);
    void sort_table();
    void create_backup();

private:
    string path;
    string file_path;
    ofstream myfile;
};

#endif // TABLE_H

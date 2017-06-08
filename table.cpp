#include "table.h"
#include "tableentry.h"
#include <string>

Table::Table(string file_name){
    path = "/home/isshu/QtProjects/Dictionary";
    path.append("/");
    path.append(file_name);
    myfile.open(path, ios_base::app);

    if(myfile.fail()){
        cout << "Failed to open file" << endl;
    }
}

Table::Table(string my_path, string file_name){
    path = my_path;
    path.append("/");
    path.append(file_name);
    myfile.open(path, ios_base::app);
}

Table::~Table(){
    sort_table();
}

void Table::set_path(string my_path){
    path = my_path;
}

void Table::add_entry(string word, string meaning){
    TableEntry entry(word, meaning);
    myfile << entry.get_word() << ";" << entry.get_meaning() << ";\n";
}

int Table::search(string word){
    string line;
    ifstream input_file(path);
    int error = 1;
    
    input_file >> line;

    /*In order to check eof, input has to be read once*/
    size_t found = line.find(word);
    if(found!=string::npos){
        cout << line << endl;
        error = 0;
    }

    /*Loop till end of file is reached*/
    while(!input_file.eof()){
        input_file >> line;
        found = line.find(word);
        if(found!=string::npos){
            cout << line << endl;
            error = 0;
        }
    }

    return error;
}

int Table::remove_entry(string word){
    int error = 1;
    string line;
    ifstream input_file("/home/isshu/QtProjects/Dictionary/eng_Dict.csv");
    ofstream output_file("/home/isshu/QtProjects/Dictionary/tmp.csv");

    /*In order to check eof, input has to be read once*/
    input_file >> line;
    if(line.compare(0, word.size(), word)!=0){
        output_file << line << endl;
    }

    /*Loop till end of file is reached*/
    while(!input_file.eof()){
        input_file >> line;
        if(line.compare(0, word.size(), word)==0){
            continue;
        }
        output_file << line << endl;
    }

    system("cp /home/isshu/QtProjects/Dictionary/tmp.csv /home/isshu/QtProjects/Dictionary/eng_Dict.csv");
}

void Table::sort_table(){
    system("/home/isshu/QtProjects/Dictionary/sort.sh");
}

void Table::create_backup(){
    system("cp /home/isshu/QtProjects/Dictionary/eng_Dict.csv /home/isshu/QtProjects/Dictionary/backup.csv");
}

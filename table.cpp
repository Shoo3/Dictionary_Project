#include "table.h"
#include "tableentry.h"
#include <string>

Table::Table(string my_path, string file_name){
    path = my_path;
    file_path = path;
    file_path.append("/");
    file_path.append(file_name);
}

Table::~Table(){
    sort_table();
}

void Table::set_path(string my_path){
    path = my_path;
}

void Table::add_entry(string word, string meaning){
    myfile.open(file_path, ios_base::app);
    TableEntry entry(word, meaning);
    myfile << entry.get_word() << ";" << entry.get_meaning() << ";\n";
    myfile.close();
}

int Table::search(string word){
    string line;
    ifstream input_file(file_path);
    int error = 1;

    while(getline(input_file, line)){
        if(line.find(word)!=string::npos){
            cout << line << endl;
            error = 0;
        }
    }

    input_file.close();

    return error;
}

int Table::remove_entry(string word){
    int error = 1;
    string line;
    string tmp_file_path;

    tmp_file_path = path;
    tmp_file_path.append("/tmp.csv");

    ifstream input_file(file_path);
    ofstream output_file(tmp_file_path);

    while(getline(input_file, line)){
        if(line.compare(0, word.size(), word)==0){
            error = 0;
        }
        else{
            output_file << line << endl;
        }
    }

    if(error==0){
        system(("cp "+tmp_file_path+" "+file_path).c_str());
    }

    input_file.close();
    output_file.close();

    return error;
}

void Table::sort_table(){
    system((path+"/sort.sh").c_str());
}

void Table::create_backup(){
    system(("cp "+file_path+" "+path+"/backup.csv").c_str());
}

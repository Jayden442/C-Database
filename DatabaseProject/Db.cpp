#include "Db.h"

Db::Db(){
    table = std::map<std::string, Database*>();
}
bool Db::createTable(std::string name, int columns, std::vector<std::string> col_name){
    Database * db = new Database(name, columns, col_name);
    if (table.find(name) != table.end()){
        std::pair<std::string, Database*> dbName;
        dbName.first = name;
        dbName.second = db;
        table.insert(dbName);
        cout << "Table created with name" << dbName.first << endl;
        return true;
    }
    else {
        cout << "Duplicate name, cannot add" << endl;
        return false;
    }
}

void Db::loadDb(){
    std::ifstream ifStream("db.txt");
    std::string currLine;
    std::string cols;
    int tableCounter = 0;
    while (1){
        getline(ifStream, currLine);
        if (currLine == "table end"){
            tableCounter++;
            getline(ifStream, currLine);
            getline(ifStream, cols);
            int numCols = numColumns(cols);
            std::vector<std::string> headers = parseData(cols);
            Database * newTable = new Database(currLine, numCols, headers);
            table.insert({currLine, newTable});
        }
        else{

        }
    }
    
}
std::vector<std::string> Db::parseData(std::string s){
    std::vector<std::string> entry;
    std::string currStr = "";
    for (int i = 0; i < s.size(); ++i){
        if (s[i] == ' '){
            entry.push_back(currStr);
            currStr = "";
        }
        currStr.push_back(s[i]);
    }
    return entry;
}

int Db::numColumns(std::string s){
    int cols = 1;
    
    for (int i = 0; i < s.size(); ++i){
        if (s[i] == ' '){
            cols++;
        }
    }
    return cols;
}



void Db::saveDb(){
    std::fstream fio;
    fio.open("db.txt", ios::trunc | ios::out | ios::in);

    for (auto it = table.begin(); it != table.end(); ++it){
        for (auto it2 = it->second->getAllData().begin(); it2 != it->second->getAllData().begin(); ++it2){
            fio << *it2;
        }
        fio << "Table end\0" << std::endl;
    }
    fio.close();
}

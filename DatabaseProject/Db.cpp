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
    ofstream of;
    of.open("db.txt");
    
}

void Db::saveDb(){
    fstream fio;
    fio.open("db.txt", ios::trunc | ios::out | ios::in);

    for (auto it = table.begin(); it != table.end(); ++it){
        for (auto it2 = it->second->getAllData().begin(); it2 != it->second->getAllData().begin(); ++it2){
            fio << *it2;
        }
        fio << "Table end\0" << std::endl;
    }
    fio.close();
}

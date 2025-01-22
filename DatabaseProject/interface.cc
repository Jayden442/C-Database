#include <iostream>
#include <iomanip>
#include "Database.h"
#include "Db.h"

int main(){
    Db db;
    std::cout << "Creating file..." << endl;
    db.loadDb();
    std::cout<<"Options \n" << "1. Create Table" << endl;
}
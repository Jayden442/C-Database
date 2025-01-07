#ifndef DATABASE_H
#define DATABASE_H
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <utility>
#include <set>
#include "Entry.h"
#include "Btree.h"
class Database{
    private:
        std::string name;
    
        int numEntries;
        int columns;
        std::vector<std::string> col_name;
        std::vector<BTree<std::string, 4>> bTreeVect;
        std::vector<Entry*> entryVect;
        // Each entry in the outer vector is a column, the map tells you the data in that column to Entry correspondence
        std::vector<std::map<std::string, std::set<Entry*>>> mapA;
        

    public:
        Database(std::string name, int columns, std::vector<std::string> col_name);
        ~Database();
        void queryAdd(Entry* e);
        std::set<Entry*> querySearch(int col, std::string);
        std::set<Entry*> queryDelete(int col, std::string value);
        bool queryUpdate(int col, std::string, std::map<int, std::string>);
        
        

};
#endif
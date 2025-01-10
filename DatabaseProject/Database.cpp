#include "Database.h"

// TBD: Add btree functionality
Database::Database(std::string name, int cols, std::vector<std::string> col_name): name(name),numEntries(0), columns(cols){
    for (int i = 0; i < col_name.size(); ++i){
        Database::col_name.at(i) = col_name.at(i);
    }
    bTreeVect = std::vector<BTree<std::string, 4>>();
    entries = std::set<Entry*>();
    
    
}

Database::~Database(){
    
}

 
void Database::queryAdd(Entry* e){
    
    
    for(int i = 0; i < columns; ++i){
        bTreeVect.at(i).insert(e->getData(i));

    }
    
    for (int i = 0; i < columns; ++i){
        // if no key matches
        if(mapA.at(i).find(e->getData(i)) == mapA.at(i).end()){
            std::set<Entry*> entrySet;
            entrySet.insert(e);
            mapA.at(i).insert(std::make_pair(e->getData(i), entrySet));
            break;
        }
        // each pair stores the name of the data and a vector of entries that correspond to that value
        else{
            auto it = mapA.at(i).find(e->getData(i));
            it->second.insert(e);
        }
        /*
        for (std::map<std::string,std::vector<Entry*>>::iterator it = mapA.at(i).begin(); it != mapA.at(i).end(); ++it){
        mapA.at(i).find()
        }
        */
    
}
}

std::set<Entry*> Database::querySearch(int col, const std::string &name) const{
    // return all data in which the specified column has a specific name
    auto it = mapA.at(col).find(name);
    if(it != mapA.at(col).end()){
        return it->second;
    }
    else {
        std::cout << "No entries with that name" << std::endl;
        std::set<Entry *> emptySet;
        return emptySet;
    }
    
}

std::set<Entry*> Database::queryDelete(int col, const std::string &name){
    std::set<Entry *> toBeDeleted = querySearch(col,name);
    for (Entry * e: toBeDeleted){
        for (int i = 0; i < mapA.size(); ++i){
            std::string deleteString = e->getData(i);
            auto it = mapA.at(i).find(deleteString);
            if(it != mapA.at(i).end()){
                it->second.erase(e);
            }
        }
    }
    for (int i = 0; i < toBeDeleted.size(); ++i){
        auto it = next(toBeDeleted.begin(), i);
        entries.erase(find(entries.begin(), entries.end(), *it));
    }
    
} 

bool Database::queryUpdate(int col, const std::string &before, std::map<int, std::string> after){
    std::set<Entry*> toBeUpdated = querySearch(col,before);
    for (Entry * e: toBeUpdated){
        auto it = after.begin();
        while (it != after.end()){
            e->setData(it->first, it->second);
        }
    }

}

std::set<Entry*> Database::getAllData() const{
    return entries;
}

int Database::getSize() const{
    return entries.size();
}


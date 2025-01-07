#include "Entry.h"


Entry::Entry(int id):id(id){
    data = std::vector<std::string>();
}

std::string Entry::getData(int col){
    return data.at(col);
}

void Entry::setData(int col, std::string data){
    Entry::data.at(col) = data;
}
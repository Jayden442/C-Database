#include "Entry.h"

std::ostream& operator<<(std::ostream& ost, const Entry& e){
    for (int i = 0; i < e.data.size(); ++i){
        ost << e.data.at(i) << " ";
    }
    ost << std::endl;
}

Entry::Entry(int id):id(id){
    data = std::vector<std::string>();
}

std::string Entry::getData(int col) const{
    return data.at(col);
}

void Entry::setData(int col, std::string data){
    Entry::data.at(col) = data;
}
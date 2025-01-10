#ifndef ENTRY_H
#define ENTRY_H
#include <iostream>
#include <string>
#include <vector>
#include <map>
class Entry{
    friend std::ostream& operator<<(std::ostream &, const Entry&);
    public:
        Entry(int id);
        ~Entry();
        std::string getData(int col) const;
        void setData(int col, std::string data);
        int id;
        
    
    private:
        // vector that stores string data
        std::vector<std::string> data;

};
#endif
#include <iostream>
#include <string>
#include <vector>
#include <map>
class Entry{
    public:
        Entry(int id);
        ~Entry();
        std::string getData(int col);
        void setData(int col, std::string data);
        int id;
    
    private:
        // vector that stores string data
        std::vector<std::string> data;
};
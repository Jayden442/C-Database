#ifndef DB_H
#include "Database.h"
#include <fstream>

class Db{
    public:
        Db();
        bool createTable(std::string name, int columns, std::vector<std::string> col_name);
        void loadDb();
        void saveDb();

    private:
        std::map<std::string, Database*> table;
};

#endif
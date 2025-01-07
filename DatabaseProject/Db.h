#ifndef DB_H
#include "Database.h"

class Db{
    public:
        Db();
        bool createTable(std::string name, int columns, std::vector<std::string> col_name);

    private:
        std::map<std::string, Database*> table;
};

#endif
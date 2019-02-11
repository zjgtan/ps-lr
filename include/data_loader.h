#ifndef DATA_LOADER_H_
#define DATA_LOADER_H_


#include <fstream>
#include <vector>
#include <string>
#include <sys/io.h>

#include "instance.h"

class DataLoader{
    private:
        std::ifstream* _fin;
        std::vector<std::string> _files;
        int _idx; 
        

    public:
        DataLoader(std::string dir);
        ~DataLoader() {
            if (_fin) {
                delete _fin;
            }
        }

        bool next(Instance &ins);
        void reset();

    private:
        std::vector<std::string> scan_dir(std::string& dir);
        Instance parseLine(const std::string& s);

};

#endif

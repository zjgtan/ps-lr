#ifndef PARAMETERS_H_
#define PARAMETERS_H_ 

#include <unordered_map>
#include "ps/ps.h"

class Parameters{
    private:
        std::unordered_map<ps::Key, float> _parameters;

    public:
        float get_weight(ps::Key key) {
            std::unordered_map<ps::Key, float>::iterator iter = _parameters.find(key);
            if (iter == _parameters.end()) {
                _parameters[key] = 0;
            }

            return _parameters[key];
        }
};

#endif

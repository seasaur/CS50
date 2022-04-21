#ifndef FILTERGENERIC_H
#define FILTERGENERIC_H
#include <vector>

class FilterGeneric {
    private:
        virtual bool g(int x) = 0;

    public:
        vector<int> filter(vector<int> x);
};

#endif
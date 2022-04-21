#ifndef FILTERGENERIC_H
#define FILTERGENERIC_H

class FilterGeneric {
    private:
        virtual bool g(int x) = 0;
        vector<int> store;

    public:
        vector<int> filter(vector<int>);


};
#endif
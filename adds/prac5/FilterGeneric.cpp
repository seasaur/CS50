#include "FilterGeneric.h"
#include <vector>
int index = 0;
vector<int> FilterGeneric::filter(vector<int> x) {
    if((x.size()-1)<index) {
        return x;
    }
    if (g(x[index])==0) {
        x.erase(index);
    }
    index++;
    return filter(x);
}
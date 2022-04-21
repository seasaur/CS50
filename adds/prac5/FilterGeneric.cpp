#include "FilterGeneric.h"
#include <vector>
int i = 0;
std::vector<int> FilterGeneric::filter(std::vector<int> x) {
    if((x.size()-1)<i) {
        return x;
    }
    if (g(x[i])==0) {
        x.erase(i);
    }
    index++;
    return filter(x);
}
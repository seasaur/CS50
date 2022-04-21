#include "FilterGeneric.h"
#include <vector>
int index = 0;
vector<int> FilterGeneric::filter(vector<int> x) {
    if((x.size()-1)<index) {
        return store;
    }

    
    return filter(x);
}
#include "FilterGeneric.h"
#include "FilterOdd.h"
#include <vector>
#include <iostream>

int main() {
    FilterGeneric *odd = new FilterOdd();
    std::vector<int> screaming = {1,2,3,4,5,6,7};
    std::vector<int> crying;
    crying=odd->map(screaming);
    for(int i=0;i<crying.size();i++) {
        std::cout << crying.at(i) << std::endl;
    }
}
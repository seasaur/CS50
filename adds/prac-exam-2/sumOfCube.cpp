#include <math.h>
//function that cubes index+1

int sumOfCube(int n) {
    if(n<1) {
        return n;
    }
    return pow(n,3)+sumOfCube(n-1);
}
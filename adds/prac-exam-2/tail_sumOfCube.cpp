#include <math.h>
//function that cubes index+1

int sumOfCube(int n) {
    if(n<1) {
        return n;
    }
    return sumOfCube(pow(n,3));
}
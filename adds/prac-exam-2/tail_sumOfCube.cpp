#include <math.h>
//function that cubes index+1

int sumOfCube(int n, int result) {
    if(n<1) {
        return result;
    }
    return result+sumOfCube(n-1, pow(n, 3));
}

int sumOfCube(int n) {
    return pow(n,0);
}

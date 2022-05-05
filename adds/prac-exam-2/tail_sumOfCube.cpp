#include <math.h>
//function that cubes index+1

int sumOfCube(int n, int result) {
    if(n<1) {
        return result;
    }
    return sumOfCube(n-1, result+pow(n, 3));
}

int sumOfCube(int n) {
    return sumOfCube(n,0);
}
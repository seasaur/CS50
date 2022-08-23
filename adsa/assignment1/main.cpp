#include <string>
#include <iostream>
#include <math.h>
using namespace std;


// Function to find the sum of
// two integers of base B
string sumBaseB(int x, int y, int base) {
    string a = to_string(x);
    string b = to_string(y);

    int aSize, bSize;

    aSize = a.size();
    bSize = b.size();

    string sum = "";
    string s = "";

    int diff;
    diff = std::abs(aSize - bSize);

    // Padding 0 (make numbers equal)
    for (int i = 1; i <= diff; i++) {
        s += "0";
    }

    // check string lengths
    if (aSize < bSize) {
        a = s + a;
    }
    else {
        b = s + b;
    }

    int current = 0;
    int carry = 0;

    int start = max(aSize, bSize) -1;

    // Loop to find the find the sum of two integers of base B
    for (int i=start; i>-1; i--) {

        // current value
        current = carry + (a[i] - '0') + (b[i] - '0');

        // carry
        carry = current / base;

        // current digit
        current = current % base;

        // Update sum result
        sum = (char)(current + '0') + sum;
    }
    if (carry > 0)
        sum = (char)(carry + '0') + sum;
    return sum;
}

int getSize(long num)
{
    int count = 0;
    while (num > 0)
    {
        count++;
        num /= 10;
    }
    return count;
}

long karatsuba(long x, long y)
{
    // Base Case
    if (x < 10 && y < 10)
        return x * y;

    // determine the size of x and y
    int size = fmax(getSize(x), getSize(y));

    // Split x and y
    int n = ceil(size / 2);
    long p = pow(10, n);
    long a = floor(x / p);
    long b = x % p;
    long c = floor(y / p);
    long d = y % p;

    // Recur until base case
    long ac = karatsuba(a, c);
    long bd = karatsuba(b, d);
    long e = karatsuba(a + b, c + d) - ac - bd;

    // return the equation
    return (pow(10, 2 * n) * ac + pow(10, n) * e + bd);
}

int main() {
    // string a = "";
    // string b = "";
    string sum = "";
    // string product = "";
    int base;


    int a;
    int b;
    int product;

    cin >> a >> b >> base;

    // Function Call
    sum = sumBaseB(a, b, base);
    product = karatsuba(a,b);
    cout << sum << " " << product << endl;
    return 0;
}
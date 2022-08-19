#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

// Function to find the sum of
// two integers of base B
string sumBaseB(string a, string b, int base)
{
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
        current = carry + (a[i] - '0') +
                       (b[i] - '0');

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





int main(){
    string a = "";
    string b = "";
    string sum = "";
    string product = "";
    int base;
    cin >> a >> b >> base;

    // Function Call
    sum = sumBaseB(a, b, base);
    product = multiply(a,b);
    cout << sum << " " << product << endl;
    return 0;
}
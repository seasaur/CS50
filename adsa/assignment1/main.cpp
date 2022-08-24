#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <sstream>
#include <vector>
using namespace std;

string add(string left, string right, int base) {
    int length = max(left.length(), right.length());
    int carry = 0;
    int colSum = 0;  // sum of two digits in the same column
    string result = "";

    // padding the shorter string with zeros
    while (left.length() < length) {
      left = "0" + left;
    }

    while (right.length() < length) {
      right = "0" + right;
    }

    // build result string from right to left
    for (int i = length-1; i > -1; i--) {
      colSum = (left[i]-'0') + (right[i]-'0') + carry; //converting to int for calculations
      carry = colSum/base;
    //   result.insert(0,to_string(colSum % base));
    result = to_string(colSum % base) + result;
    }

    if (carry > 0) {
        result = to_string(carry) + result;
    }
    //   result.insert(0,to_string(carry));

    // remove leading zeros
    return result.erase(0, min(result.find_first_not_of('0'), result.length()-1));
}

string subtract(string left, string right, int base) {
    int length = max(left.length(), right.length());
    int diff = 0;
    string result = "";

    while (left.length() < length) {
      left = "0" + left;
    }

    while (right.length() < length) {
      right = "0" + right;
    }

    for (int i = length-1; i > -1; i--) {
        diff = (left[i]-'0') - (right[i]-'0');
        if (diff >= 0) {
            result = to_string(diff) + result;

        }
            // result.insert(0, to_string(diff));
        else {

            // borrowing
            int j = i - 1;
            while (j > -1) {
                left[j] = ((left[j]-'0') - 1) % base + '0';
                if (left[j] != base-1 + '0') {
                    break;
                }
                else {
                    j--;
                }
            }
            // result.insert(0, to_string(diff+base));
            result = to_string(diff+base) + result;
        }

    }

    return result.erase(0, min(result.find_first_not_of('0'), result.size()-1));
}

string multiply(string left, string right, int base) {
    int length = max(left.length(), right.length());

    while (left.length() < length) {
      left = "0" + left;
    }

    while (right.length() < length) {
      right = "0" + right;
    }

    if (length == 1) {
        return to_string((left[0]-'0')*(right[0]-'0'));
    }
    string left0 = left.substr(0,length/2);
    string left1 = left.substr(length/2,length-length/2);
    string right0 = right.substr(0,length/2);
    string right1 = right.substr(length/2,length-length/2);

    string calc0 = multiply(left0,right0, base);
    string calc1 = multiply(left1,right1, base);
    string calc2 = multiply(add(left0,left1, base),add(right0,right1, base), base);
    string calc3 = subtract(calc2,add(calc0,calc1, base), base);

    for (int i = 0; i < 2*(length-length/2); i++) {
        // p0.append("0");
        calc0+="0";
    }
    for (int i = 0; i < length-length/2; i++) {
        // p3.append("0");
        calc3+="0";
    }

    string result = add(add(calc0,calc1, base),calc3, base);

    return result.erase(0, min(result.find_first_not_of('0'), result.length()-1));
}

// string schoolMultiply(string x, int base) {


// }

int main() {
    string a = "";
    string b = "";
    string sum = "";
    // string product = "";
    int base;
    string product="";

    cin >> a >> b >> base;

    // Function Call
    sum = add(a, b, base);
    product = multiply(a,b, base);
    // cout << "main ab" << a << " " << b << endl;
    cout << sum << " " << product << endl;
    return 0;
}
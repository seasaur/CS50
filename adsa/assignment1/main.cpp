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

    result = to_string(colSum % base) + result;
    }

    if (carry > 0) {
        result = to_string(carry) + result;
    }

    // remove leading zeros
    while(result[0] == '0' && result.length() > 1) {
        result = result.substr(1,result.length()-1);
    }

    return result;
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
        if (diff >= 0) { //if no need to borrow
            result = to_string(diff) + result;

        }
        else {

            // borrowing
            int j = i - 1;
            while (j > -1) {
                left[j] = ((left[j]-'0') - 1) % base + '0';
                if (left[j] != (base - '0')-1) {
                    break;
                }
                else {
                    j--;
                }
            }
            result = to_string(diff+base) + result;
        }

    }
    while(result[0] == '0' && result.length() > 1) {
        result = result.substr(1,result.length()-1);
    }

    return result;
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

        int mult = (left[0]-'0')*(right[0]-'0');

        int digit = mult%base;
        int carry = (mult - mult % base)/base;

        return to_string(carry) + to_string(digit);

        // string r = schoolMultiply(left[0], right[0], base);
        // return r;
        // return to_string((left[0]-'0')*(right[0]-'0')); //do school method
    }
    string left0 = left.substr(0,length/2);
    string left1 = left.substr(length/2,length-length/2);
    string right0 = right.substr(0,length/2);
    string right1 = right.substr(length/2,length-length/2);

    string p0 = multiply(left0,right0, base);
    string p1 = multiply(left1,right1, base);
    string p2 = multiply(add(left0,left1, base),add(right0,right1, base), base);
    string p3 = subtract(p2,add(p0,p1, base), base);

    for (int i = 0; i < 2*(length-length/2); i++) {
        // p0.append("0");
        p0+="0";
    }
    for (int i = 0; i < length-length/2; i++) {
        // p3.append("0");
        p3+="0";
    }

    string result = add(add(p0,p1, base),p3, base);

    while(result[0] == '0' && result.length() > 1) {
        result = result.substr(1,result.length()-1);
    }

    return result;
}



int main() {
    string a = "";
    string b = "";
    string sum = "";
    // string product = "";
    int base;
    string product="";
    string difference = "";
    cin >> a >> b >> base;

    // Function Call
    sum = add(a, b, base);
    difference = subtract(a,b,base);
    product = multiply(a,b, base);
    // cout << "main ab" << a << " " << b << endl;
    cout << sum << " " << product << endl;
    return 0;
}
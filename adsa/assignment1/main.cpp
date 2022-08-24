#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <sstream>
#include <vector>
using namespace std;

string add(string lhs, string rhs, int base) {
    int length = max(lhs.length(), rhs.length());
    int carry = 0;
    int colSum = 0;  // sum of two digits in the same column
    string result = "";

    // padding the shorter string with zeros
    while (lhs.length() < length) {
      lhs = "0" + lhs;
    }

    while (rhs.length() < length) {
      rhs = "0" + rhs;
    }

    // build result string from right to left
    for (int i = length-1; i > -1; i--) {
      colSum = (lhs[i]-'0') + (rhs[i]-'0') + carry; //converting to int for calculations
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

string subtract(string lhs, string rhs, int base) {
    int length = max(lhs.length(), rhs.length());
    int diff = 0;
    string result = "";

    while (lhs.length() < length) {
      lhs = "0" + lhs;
    }

    while (rhs.length() < length) {
      rhs = "0" + rhs;
    }

    for (int i = length-1; i > -1; i--) {
        diff = (lhs[i]-'0') - (rhs[i]-'0');
        if (diff >= 0) {
            result = to_string(diff) + result;

        }
            // result.insert(0, to_string(diff));
        else {

            // borrowing
            int j = i - 1;
            while (j > -1) {
                lhs[j] = ((lhs[j]-'0') - 1) % base + '0';
                if (lhs[j] != '9') {
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

string multiply(string lhs, string rhs, int base) {
    int length = max(lhs.length(), rhs.length());

    while (lhs.length() < length) {
      lhs = "0" + lhs;
    }

    while (rhs.length() < length) {
      rhs = "0" + rhs;
    }

    if (length == 1) {
        return to_string((lhs[0]-'0')*(rhs[0]-'0'));
    }
    string lhs0 = lhs.substr(0,length/2);
    string lhs1 = lhs.substr(length/2,length-length/2);
    string rhs0 = rhs.substr(0,length/2);
    string rhs1 = rhs.substr(length/2,length-length/2);

    string p0 = multiply(lhs0,rhs0, base);
    string p1 = multiply(lhs1,rhs1, base);
    string p2 = multiply(add(lhs0,lhs1, base),add(rhs0,rhs1, base), base);
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

    return result.erase(0, min(result.find_first_not_of('0'), result.length()-1));
}

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
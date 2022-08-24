#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <sstream>
#include <vector>
using namespace std;

string add(string lhs, string rhs, int base) {
    int length = max(lhs.size(), rhs.size());
    int carry = 0;
    int sum_col;  // sum of two digits in the same column
    string result;

    // pad the shorter string with zeros
    while (lhs.size() < length)
      lhs.insert(0,"0");

    while (rhs.size() < length)
      rhs.insert(0,"0");

    // build result string from right to left
    for (int i = length-1; i >= 0; i--) {
      sum_col = (lhs[i]-'0') + (rhs[i]-'0') + carry;
      carry = sum_col/base;
      result.insert(0,to_string(sum_col % base));
    }

    if (carry)
      result.insert(0,to_string(carry));

    // remove leading zeros
    return result.erase(0, min(result.find_first_not_of('0'), result.size()-1));
}

string subtract(string lhs, string rhs, int base) {
    int length = max(lhs.size(), rhs.size());
    int diff;
    string result;

    while (lhs.size() < length)
      lhs.insert(0,"0");

    while (rhs.size() < length)
      rhs.insert(0,"0");

    for (int i = length-1; i >= 0; i--) {
        diff = (lhs[i]-'0') - (rhs[i]-'0');
        if (diff >= 0)
            result.insert(0, to_string(diff));
        else {

            // borrow from the previous column
            int j = i - 1;
            while (j >= 0) {
                lhs[j] = ((lhs[j]-'0') - 1) % base + '0';
                if (lhs[j] != '9')
                    break;
                else
                    j--;
            }
            result.insert(0, to_string(diff+base));
        }

    }

    return result.erase(0, min(result.find_first_not_of('0'), result.size()-1));
}

string multiply(string lhs, string rhs, int base) {
    int length = max(lhs.size(), rhs.size());

    while (lhs.size() < length)
      lhs.insert(0,"0");

    while (rhs.size() < length)
      rhs.insert(0,"0");

    if (length == 1)
        return to_string((lhs[0]-'0')*(rhs[0]-'0'));

    string lhs0 = lhs.substr(0,length/2);
    string lhs1 = lhs.substr(length/2,length-length/2);
    string rhs0 = rhs.substr(0,length/2);
    string rhs1 = rhs.substr(length/2,length-length/2);

    string p0 = multiply(lhs0,rhs0, base);
    string p1 = multiply(lhs1,rhs1, base);
    string p2 = multiply(add(lhs0,lhs1, base),add(rhs0,rhs1, base), base);
    string p3 = subtract(p2,add(p0,p1, base), base);

    for (int i = 0; i < 2*(length-length/2); i++)
        p0.append("0");
    for (int i = 0; i < length-length/2; i++)
        p3.append("0");

    string result = add(add(p0,p1, base),p3, base);

    return result.erase(0, min(result.find_first_not_of('0'), result.size()-1));
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
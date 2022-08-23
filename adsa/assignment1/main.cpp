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

string add(string lhs, string rhs) {
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
      carry = sum_col/10;
      result.insert(0,to_string(sum_col % 10));
    }

    if (carry)
      result.insert(0,to_string(carry));

    // remove leading zeros
    return result.erase(0, min(result.find_first_not_of('0'), result.size()-1));
}

string subtract(string lhs, string rhs) {
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
                lhs[j] = ((lhs[j]-'0') - 1) % 10 + '0';
                if (lhs[j] != '9')
                    break;
                else
                    j--;
            }
            result.insert(0, to_string(diff+10));
        }

    }

    return result.erase(0, min(result.find_first_not_of('0'), result.size()-1));
}

string multiply(string lhs, string rhs) {
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

    string p0 = multiply(lhs0,rhs0);
    string p1 = multiply(lhs1,rhs1);
    string p2 = multiply(add(lhs0,lhs1),add(rhs0,rhs1));
    string p3 = subtract(p2,add(p0,p1));

    for (int i = 0; i < 2*(length-length/2); i++)
        p0.append("0");
    for (int i = 0; i < length-length/2; i++)
        p3.append("0");

    string result = add(add(p0,p1),p3);

    return result.erase(0, min(result.find_first_not_of('0'), result.size()-1));
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
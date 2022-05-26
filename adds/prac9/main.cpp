#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <sstream>
using namespace std;

//https://www.tutorialspoint.com/evaluate-reverse-polish-notation-in-cplusplus-program

std::string isOp(std::string input) {
    std::vector<int> numbers = {};
    for(std::string::size_type i = 0; i < input.size(); i++) {
        if(isdigit(input[i])) {
            numbers.push_back(input[i]);
        }
        else if(input[i]=='+')
    }
}

float calc(string postfix){
   int a, b;
   stack<float> stk;
   string::iterator it;
   for(it=postfix.begin(); it!=postfix.end(); it++){
      //read elements and perform postfix evaluation
      if(isOp(*it) != -1){
         a = stk.top();
         stk.pop();
         b = stk.top();
         stk.pop();
         stk.push(operation(a, b, *it));
      }
      else if(isOp(*it) > 0){
         stk.push(scanNum(*it));
      }
   }
}

int main() {
    std::string test = "*+345";
    op(test);

    // std::vector<std::string> operators = {};
    // std::string line;
    // std::getline(std::cin, line);
    // std::istringstream os(line);

    // int i;
    // while(os >> i) {
    //     operators.push_back(i);
    // }


//     string z,s;
//  while (true)
//     {
//       cin>>z;
//       s+=z;
//       if(cin.peek()=='\n')
//       break;
//     }
// ................................
// 	        OR\/
// .................................
// string s;
// getline(cin,s);

}
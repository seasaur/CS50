#include <iostream>
#include <vector>
#include <string>
using namespace std;

class node {
    public:
    string s="never used";
    string k;
};

class h {
   public:
    node * table = new node[26];

    int hash (string k) { //hash value
        return k.back() - 'a';
    }

      void insert(string k);
      void remove(string k);
      string find(string k);
      void display();
};



void h::insert(string k) {
    int i = hash(k);
    string search = find(k);

    if(search=="found") {
        return;
    }
//  cout << i << endl;
    while(table[i].s == "occupied") {
        i++;
        // cout << i << endl;
        if(i>=26) { //wrap around table
            i=0;
        }
    }

    table[i].k = k;
    table[i].s = "occupied";

}

string h::find(string k) {
    int i = hash(k);

    while(table[i].k != k) {
        if(table[i].s == "never used") {
            return "not found";
        }
        i++;

        if(i>=26) { //wrap around table
            i=0;
        }
    }

    return "found";
}

void h::remove(string k) {
    int i = hash(k);

    string search = find(k);

    if(search == "not found") {
        return;
    }

    while(table[i].k != k) {
        i++;
        // cout << i << endl;
        if(i>=26) { //wrap around table
            i=0;
        }
    }

    table[i].s = "tombstone";
    table[i].k = "";

}

void h::display() {
    for(int i=0;i<26;i++) {
        if(table[i].s=="occupied") {
            cout << table[i].k << " ";
        }
    }
    cout << endl;
}

int main() {
    h hash;
    string rawInput;
    vector<string> input;
    getline(cin, rawInput); //take input including space

	string instruction = "";
    string temp = "";

	// cout << rawInput << endl;

	for(int i=0;i<rawInput.length();i++) {
		if(rawInput[i]==' ') {
			input.push_back(temp);
			temp = "";
		}
		else if((rawInput[i]=='A') || (rawInput[i]=='D')) {
			instruction = instruction + rawInput[i];
		}

		else {
			temp.push_back(rawInput[i]);
		}
    }

    	input.push_back(temp);

   int size = input.size();

    // for (int i=0; i<size; i++) {

	// 	cout << input.at(i) << endl;

    // }
	// cout << instruction << endl;

    for (int i=0; i<size; i++) {
        if(instruction[i]=='A') {
			hash.insert(input[i]);
		}

		else if(instruction[i]=='D') {
			hash.remove(input[i]);
		}
		// cout << input.at(i) << endl;
		// cout << root << endl;
    }

    hash.display();

    // string input;
    // cin >> input;

    // if(input[0]=='A') {
    //     input.erase(0,1);
    //     hash.insert(input);
    //     hash.display();
    // }

    // else if(input[0]=='D') {
    //     input.erase(0,1);
    //     hash->remove(input);
    //     hash.display();
    // }
}
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int weight(char x) { //weight conversion (working)
    if(x-'A' < 26) { //upper case is 0-25
        return x-'A';
    }
    return x-'G'; //lower case is 26-51
}

int parent(int a, int root[]) {
    while(a != root[a])
    {
        root[a] = root[root[a]];
        a = root[a];
    }
    return a;
}

void union_find(int a, int b, int root[], int rank[])  {
    int d = parent(a, root);
    int e = parent(b, root);

    if(rank[d] > rank[e]) { //merge smaller subtrees into bigger subtrees
        root[e] = d;
        // root[d] = root[e];
    }

    else {
        root[d] = e;
    }

    if(rank[d] == rank[e]) {
        rank[e]++;
    }
}


int kruskal(pair <int, pair<int, int>> edges[], pair <int, pair<int, int>> existing[], int size) {
    int a = 0;
    int b = 0;
    int cost = 0;
    int minCost = 0;

    int root[size];
    int rank[size];

    for(int i = 0;i < size;i++) {
        root[i] = i;
        rank[i] = 0;
    }


     for (int i = 0; i < size; i++) { //existing roads

        // std::cout << "first " << get<1>(existing[i]).first << endl;
        // std::cout << "second " << get<1>(existing[i]).second << endl;

        a = get<1>(existing[i]).first;
        b = get<1>(existing[i]).second;

        if(a != 0 || b != 0) { // if existing road is not empty
            if(parent(a, root) != parent(b, root))
            {
                // union_find(a, b, root);
                union_find(a, b, root, rank);
            }

            else {
                // cout << "p" << endl;
                minCost += get<0>(existing[i]);

                // cout << "edges " << get<0>(edges[i]) << endl;
            }
        }

     }

    for (int i = 0; i < size; i++) { //new roads

        // std::cout << "first " << get<1>(existing[i]).first << endl;
        // std::cout << "second " << get<1>(existing[i]).second << endl;

        a = get<1>(edges[i]).first;
        b = get<1>(edges[i]).second;
        cost = get<0>(edges[i]);

        // cout << "cost " << cost << endl;

        if(parent(a, root) != parent(b, root)) {   //only select edge if it does not create a cycle (ie the two nodes forming it have different root nodes)
            minCost += cost;
            union_find(a, b, root, rank);
            // cout << "if mincost " << minCost << endl;
        }
        // else { //need or not?
        //     cost = 0;
        // }

     }

    return minCost;
}


int main() {
    // vector<vector<int>> country;
    // //{{0,0,0},{0,0,0},{0,0,0}};
    // //{{0,1,1},{1,0,1},{1,1,0}};
    // vector<vector<char>> build;
    // // = {{'A','B','D'},{'B','A','C'},{'D','C','A'}};
    // vector<vector<char>> destroy;
    // = {{'A','B','D'},{'B','A','C'},{'D','C','A'}};



    // for (int i = 0; i < size; i++) { //building
    //     for(int j=0; j<size;j++) {

    //         cout << country[i][j] <<build[i][j]<<destroy[i][j] << endl;

    //     }

    // }


    // string str = "";
    // getline(cin, str);
    // stringstream ss(str);

    string rawInput;
    getline(cin, rawInput); //take input including space

    // int c[100] = {0};
    // string b = "";
    // string d = "";


    // cout << rawInput << endl;
    // int count = 0;
    int check = 0; //which vector to store

    int cCount = 0;
    int bCount = 0;
    int dCount = 0;


    vector<int> c;
    vector<char> b;
    vector<char> d;

    for(int i=0;i<rawInput.length();i++) {
        if (rawInput[i]==' ') {
            check++;
        }
        else if(rawInput[i]!=',') {
            if(check == 0) {
                // cout << rawInput[i]-'0' << endl;
                // c[cCount]=(rawInput[i]-'0');
                c.push_back(rawInput[i]-'0');
                // cout << "aa " << c[cCount] << endl;
                cCount++;
            }
            else if(check == 1) {
                // cout << rawInput[i] << endl;
                // b[bCount]=(rawInput[i]);
                b.push_back(rawInput[i]);
                // cout << "bb " << b[bCount] << endl;
                bCount++;
            }
            else {
                // cout << rawInput[i] << endl;
                // d[dCount]=(rawInput[i]);
                d.push_back(rawInput[i]);
                // cout << "cc " << d[dCount] << endl;
                dCount++;
            }
        }
    }

    int size = sqrt(c.size());
    // cout << "size " << size << endl;

    int country[size][size];
    //{{0,0,0},{0,0,0},{0,0,0}};
    //{{0,1,1},{1,0,1},{1,1,0}};
    char build[size][size];
    // = {{'A','B','D'},{'B','A','C'},{'D','C','A'}};
    char destroy[size][size];

    // country.push_back(c);
    // build.push_back(b);
    // destroy.push_back(d);

    // int country[size][size] = {0};
    // string build = "";
    // string destroy = "";

    int anotherCount = 0;
    for(int i=0;i<size;i++) {
        for(int j=0;j<size;j++) {
            country[i][j] = c[anotherCount];
            build[i][j] = b[anotherCount];
            destroy[i][j] = d[anotherCount];
            anotherCount++;
        }
    }

    // for(int i=0;i<size;i++) {
    //     for(int j=0;j<size;j++) {
    //         cout << "country " << country[i][j] << endl;
    //         cout << "b " << build[i][j] << endl;
    //         cout << "d " << destroy[i][j] << endl;
    //     }
    // }

    //  for(int i=0;i<size;i++) {

    //         cout << "c2 " << c[i] << endl;
    //         cout << b[i] << endl;
    //         cout << d[i] << endl;

    // }

    // string firstParse;
    // // Parse the string
    // for (int i; ss >> i;) {
    //     firstParse.push_back(i);
    //     if (ss.peek() == ',')
    //         ss.ignore();
    // }

    // cout << "first parse " << firstParse << endl;


    pair <int, pair<int, int>> edges[size]; //build + edges
    pair<int, pair<int, int>> existing[size]; //destroy + edges

    int u = 0;
    int v = 0;

    for (int i = 0; i < size; i++) { //building
        for(int j=0; j<size;j++) {
            if(i>j) { //must be different countries & avoiding duplicate edges
                if(country[i][j] == 0) { //if no existing road
                    edges[u] = make_pair(weight(build[i][j]), make_pair(i,j));
                    u++;
                }
                else { //existing road
                    existing[v] = make_pair(weight(destroy[i][j]), make_pair(i, j));
                    v++;

                }
            }
        }

    }

    std::sort(existing,existing+size); // need descending
    std::sort(edges,edges+size);

    pair <int, pair<int, int>> sortE[size];
    // for(int i=size-1;i=0;i--) { (doesnt work for some reason)
    //     for(int j=0;j<size;j++) {
    //        sortE[j]=make_pair(get<0>(existing[i]),make_pair(get<1>(existing[j]).first,get<1>(existing[i]).second));
    //     }
    // }

    int j = size-1; //copy over sorted existing array and reverse it (so that in functions, can take away edge with min cost as it goes in last)
    for(int i=0;i<size;i++) {
        sortE[i]=make_pair(get<0>(existing[j]),make_pair(get<1>(existing[j]).first,get<1>(existing[j]).second));
        j--;

    }


    // for(int i=0;i<size;i++) {
    //     std::cout << "sorted " << get<1>(sortE[i]).first << std::endl;
    //     std::cout << "sorted " << get<1>(sortE[i]).second << std::endl;
    //     std::cout << "sorted " << get<0>(sortE[i]) << std::endl;

    // }

    // for(int i=0;i<size;i++) {
    //     std::cout << "existing " << get<1>(existing[i]).first << std::endl;
    //     std::cout << "existing " << get<1>(existing[i]).second << std::endl;
    //     std::cout << "weight " << get<0>(existing[i]) << std::endl;

    // //     std::cout << "new " << get<1>(edges[i]).first << std::endl;
    // //     std::cout << "new " << get<1>(edges[i]).second << std::endl;
    // //     std::cout << "weight " << get<0>(edges[i]) << std::endl;
    // }
    // // //         // std::cout << "not existing " << edges[0] << std::endl;


    int result = kruskal(edges, sortE, size);

    std::cout << result << endl;

    }
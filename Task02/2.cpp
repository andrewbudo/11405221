#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

int main() {
    string str;
    cin >> str;
    
    sort(str.begin(), str.end());
    
    set<string> permutations;
    do {
        permutations.insert(str);
    } while(next_permutation(str.begin(), str.end()));
    
    cout << permutations.size() << endl;
    for(const string& perm : permutations) {
        cout << perm << endl;
    }
    
    return 0;
}

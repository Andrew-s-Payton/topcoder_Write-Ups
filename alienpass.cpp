#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Alien {
    public:
        int Solution(string &s);
        int SolutionOptimized(string &s);
        unordered_set <string> Uniques;
};

int Alien::Solution(string &s) {
    // O(n^2) solution
    int i, j, total;
    string ns;

    total = 0;

    // Go through each character of that string where that character does not exist
    // O(n)
    for (i = 0; i < s.size(); i++) {
        ns = "";
        // O(n^2)
        for (j = 0; j < s.size(); j++) {
            if (j != i) ns += s[j]; 
        }    
        
        // O(1)
        if (Uniques.find(ns) == Uniques.end()) {
            total++;
            Uniques.insert(ns);
        }
    }
    return total;
}

int Alien::SolutionOptimized(string &s) {
    // O(n) solution
    int i, j, total;
    char c;

    total = 1;
    c = s[0];

    // O(n)
    for (i = 0; i < s.size(); i++) {
        if (s[i] != c) total++;
        c = s[i];
    }
    return total;
}

int main() {
    string s;
    Alien A;
    cin >> s;
    cout << A.SolutionOptimized(s) << endl;

    return 0;
}
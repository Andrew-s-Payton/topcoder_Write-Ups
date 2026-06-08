#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Given a string S solely composed of characters '<' and '>'
// Size is even
// Replace a '<' with a '>'
// let k be size / 2
// convert S to k '>'s followed by k '<''s
// Return minimum number of replacements needed to do

class MagDiv {
    public:
        int Solution(string &s);
};

int MagDiv::Solution(string &s) {
    int half, i, total;
    total = 0;
    half = s.size() / 2;

    for (i = 0; i < half; i++) {
        if (s[i] == '<') total++;
    }
    for (i = half; i < s.size(); i++) {
        if (s[i] == '>') total++;
    }

    return total;
}

int main() {
    string test;
    cin >> test;
    MagDiv M;
    cout << M.Solution(test) << endl;
    return 0;
}

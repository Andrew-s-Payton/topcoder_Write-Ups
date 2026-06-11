#include <iostream>
#include <vector>
using namespace std;

class Range {
    public:
        int Solution(vector <int> &arr);
};

int Range::Solution(vector <int> &arr) {
    int i, total, curr;
    total = 1;
    curr = -1;
    for (i = 0; i < arr.size()-1; i++) {
        curr = arr[i+1];
        if (arr[i] != curr-1) {
            total++;
        }
        curr = arr[i];
    }
    return total;
}

int main() {
    int t;
    vector <int> v;
    Range R;
    while (cin >> t) {
        if (t == -1) {
            break;
        }
        v.push_back(t);
    }
    cout << R.Solution(v) << endl;;
    return 0;
}
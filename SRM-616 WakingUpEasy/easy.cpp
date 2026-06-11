#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

class Easy {
    public:
        int Solution(vector <int> &volume, int S);
        void Inputs();
};

int Easy::Solution(vector <int> &volume, int S) {
    int i, total, tS;
    total = 0;
    for (i = 0; i < volume.size(); i++) {
        tS = S;
        S = S - volume[i];
        total++;
        printf("i = %d.  S before = %d.  volume[%d] = %d.  S after = %d\n", i, tS, i, volume[i], S);
        if (S < 0) return total;
    }
    return total;
}

void Easy::Inputs() {
    int S, t;
    vector <int> volumes;

    cin >> S;
    while (cin) {
        cin >> t;
        volumes.push_back(t);
        if (t == -1) break;
    }

    cout << Solution(volumes, S) << endl;
}

int main() {
    Easy E;
    E.Inputs();
    return 0;
}
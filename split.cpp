// Must pick a pile of stones with more than one stone
// Then must pick two other piles with at least one stone each
// TODO: Fully convert from vector to set data structure


#include <set>

using namespace std;

class SplitStone {
    public:
        bool Split(multiset <int> &p);
};

bool SplitStone::Split(multiset <int> &p) {
    int halfs;
    bool foundGreaterThanOne, foundOneExtra, foundTwoExtra, winRound;
    multiset <int>::iterator it, splitPile, extraOne, extraTwo;

    // Go through the vector and find the first element not equal to one
    for (it = p.begin(); it != p.end(); it++) {
        if (*it > 1 && !foundGreaterThanOne) {
            splitPile = it;
            foundGreaterThanOne = true;
        }
        else if (!foundTwoExtra) {
            if (!foundOneExtra) {
                extraOne = it;
                foundOneExtra = true;
            }
            else {
                extraTwo = it;
                foundTwoExtra = true;
            }
        }
    }

    if (foundGreaterThanOne && foundTwoExtra) {
        halfs = *(splitPile) / 2;
        p[extraOne] += halfs;
        p[extraTwo] += halfs;
        p.erase(splitPile);
        winRound = true;
    }
}
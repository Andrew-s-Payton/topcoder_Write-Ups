#include <iostream>
#include <vector>
using namespace std;

class Crypt {
    public:
        long long Solution(vector <int> &nums);
        void Inputs();
};

void Crypt::Inputs() {
    int input;
    vector <int> nums;
    while (cin >> input) {
        if (input == -1) {
            break;
        }
        nums.push_back(input);
    }

    cout << Solution(nums) << endl;
}

long long Crypt::Solution(vector <int> &nums) {
    int i, min;
    long long product;
    min = 0;
    product = 1;

    // Find minimum
    for (i = 0; i < nums.size(); i++) {
        if (nums[i] < nums[min]) {
            min = i;
        }
    }
    nums[min]++;

    for (i = 0; i < nums.size(); i++) {
        product *= nums[i];
    }

    return product;
}

int main() {
    Crypt C;
    C.Inputs();
    return 0;
}

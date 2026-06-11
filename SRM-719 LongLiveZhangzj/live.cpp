#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class LongLive {
    public:
        int Solution(vector <string> &speech, vector <string> &words);
};

// O(n+m)
int LongLive::Solution(vector <string> &speech, vector <string> &words) {
    unordered_set <string>::iterator it;
    unordered_set <string> setWords;
    int i, total;
    total = 0;

    // O(m)
    for (i = 0; i < words.size(); i++) {
        setWords.insert(words[i]);
    }

    // O(m)
    for (i = 0; i < speech.size(); i++) {
        if (setWords.find(speech[i]) != setWords.end()) {
            total++;
        }
    }

    return total;
}

int main() {
    string input;
    vector <string> words;
    vector <string> speech;
    LongLive L;

    cout << "Enter words to add to def: ";
    while (cin) {
        cin >> input;
        if (input == "STOP") break;
        words.push_back(input);
    }
    
    cin.clear();

    cout << "Enter words to add to speech: ";
    while (cin) {
        cin >> input;
        if (input == "STOP") break;
        speech.push_back(input);
    }

    cout << L.Solution(speech, words) << endl;

    return 0;
}
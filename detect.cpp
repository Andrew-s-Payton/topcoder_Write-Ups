#include <unordered_set>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Detect {
	public:
		bool DFS(int r, int c, char val, int length, int oR, int oC);
		int maxR;
		int maxC;
		int pos;
		bool loop;
		unordered_set <char> visitCheck;
		vector <string> grid;
};

bool Detect::DFS(int r, int c, char val, int length, int oR, int oC) {
	pos = r * maxC + c;

	// Out of bounds checking
	if (r < 0 || c < 0 || r >= maxR || c >= maxC) {
		return 0;
	}

	// Closed-loop check
	if (length >= 4 && r == oR && c == oC) {
		loop = true;
	}

	// Visit checking, O(1)
	if (visitCheck.find(pos) != visitCheck.end()) {
		return 0;
	}

	// If it finds a similar cell nearby do the DFS
	if (grid[r][c] == val) {
		// Mark as visited, O(1)
		visitCheck.insert(pos);
		
		// Check all nearby cells, since these already check visited overall program remains O(r*c)
		DFS(r+1, c, val, length+1, oR, oC);
		DFS(r-1, c, val, length+1, oR, oC);
		DFS(r, c+1, val, length+1, oR, oC);
		DFS(r, c-1, val, length+1, oR, oC);
	}

	return 0;
}

int main() {
	Detect D;
	string input;
	int i, j;

	// Get input
	while (cin >> input) {
		D.grid.push_back(input);
	}

	D.loop = false;

	// For every cell, O(r * c)
	for (i = 0; i < D.grid.size(); i++) {
		for (j = 0; j < D.grid[i].size(); j++) {
			// Set the max values and begin
			D.maxR = D.grid.size();
			D.maxC = D.grid[i].size();
			D.DFS(i, j, D.grid[i][j], 0, i, j);
		}
	}

	if (D.loop) {
		printf("Loop found.\n");
	}
	else {
		printf("Loop not found.\n");
	}

	return 0;
}


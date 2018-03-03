#include <iostream>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
#include <vector>
#include <array>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
using namespace std;

#define PI 3.14159265
#define PHI 1.61803398

#define D(x) cerr << #x << " = " << (x) << ", "

typedef unsigned int uint;
typedef unsigned long ul;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef unsigned char byte;

template<typename T> using V = vector<T>;
template<typename T, typename U> using P = pair<T,U>;
template<typename T, typename U> using umap = unordered_map<T,U>;
template<typename T, typename U> using uset = unordered_set<T,U>;
template<typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
template<typename T> using max_heap = priority_queue<T>;

int m, n;
V<V<bool>> grid;


int check(int i, int j, const V<V<bool>>& g)
{
	if (i >= 0 and j >= 0 and i < n and j < n and g[i][j]) return 1;
	return 0;
}

void turn()
{
	V<V<bool>> g = grid;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int c = 0;
			c += check(i-1, j-1, g);
			c += check(i-1, j, g);
			c += check(i-1, j+1, g);
			c += check(i, j-1, g);
			c += check(i, j+1, g);
			c += check(i+1, j-1, g);
			c += check(i+1, j, g);
			c += check(i+1, j+1, g);
			//D(i); D(j); D(c) << endl;
			if (grid[i][j] == true) {
				if (c < 2 or c > 3) grid[i][j] = false;
			}
			else if (grid[i][j] == false) {
				if (c == 3) grid[i][j] = true;
			}
		}
	}
}

int main()
{
	cin >> m >> n;
	grid = V<V<bool>>(n, V<bool>(n, false));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			// D(i); D(j) << endl;
			char c;
			cin >> c;
			if (c == '#') grid[i][j] = true;
		}
	}

	for (int i = 0; i < m; ++i) {
		// D(i) << endl;
		turn();
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << (grid[i][j] ? '#' : '.');
			if (j != n-1) cout << ' ';
		}
		cout << endl;
	}
}

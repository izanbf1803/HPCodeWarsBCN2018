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

int n, m;
V<V<int>> grid;

int main()
{
	int c = 0;
	cin >> n;
	grid = V<V<int>>(n, V<int>(n, 0));
	for (int i = n-1; i >= 0; --i) {
		for (int j = 0; j < n; ++j) {
			cin >> grid[i][j];
		}
	}
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		if (grid[y][x] == 1) {
			++c;
			grid[y][x] = 0;
		}
	}	
	cout << c << endl;
}

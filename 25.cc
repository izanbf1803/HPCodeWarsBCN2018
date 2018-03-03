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

int n;
V<bool> ex;
V<int> conn;
int times = 0;

bool has_ex(int start)
{
	V<bool> visited(n, false);
	queue<int> q;
	q.push(start);
	while (not q.empty()) {
		int x = q.front();
		q.pop();
		if (x == 0) return true;
		visited[x] = true;
		if (not visited[conn[x]]) q.push(conn[x]);
	}
	return false;
}

int main()
{	
	cin >> n;
	ex = V<bool>(n);
	conn = V<int>(n);

	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		conn[a] = b;
	}

	ex[0] = true;
	int c = 0;
	for (int i = 0; i < n; ++i) {
		if (has_ex(i)) {
			++c;
		}
	}
	cout << c << endl;
}

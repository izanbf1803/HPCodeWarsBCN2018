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

struct Point {
	int x, y;
};

Point operator+(Point a, Point b) { return {a.x+b.x, a.y+b.y}; }

const V<Point> dirs = {
	{-1, 0},
	{+1, 0},
	{0, -1},
	{0, +1},
};

int x0_, y0_, xf_, yf_;
int dx, dy, n;
V<V< set<P<int,int>> >> locked;

int BFS()
{
	V<V<int>> dist(dy, V<int>(dx, -1));
	queue<Point> q;
	q.push({0,0});
	dist[0][0] = 0;
	while (not q.empty()) {
		Point p = q.front();
		// D(p.x); D(p.y) << endl;
		q.pop();
		for (Point dir : dirs) {
			Point z = p + dir;
			if (z.x >= 0 and z.y >= 0 and z.x < dx and z.y < dy and dist[z.y][z.x] == -1 and 
				locked[p.y][p.x].count(make_pair(z.y, z.x)) == 0) 
			{
				dist[z.y][z.x] = 1 + dist[p.y][p.x];
				q.push(z);
			}
		}
	}
	return dist[dy-1][dx-1];
}

void parse_s(string& s)
{
	V<int> a(4, 0);
	int index = 0;
	int k = 0;
	for (char c : s) {
		if (c == ',') {
			a[index] = k;
			k = 0;
			++index;
		}
		else {
			k *= 10;
			k += c - '0';
		}
	}
	a[index] = k;
	x0_ = a[0];
	y0_ = a[1];
	xf_ = a[2];
	yf_ = a[3];
	//D(x0_); D(y0_); D(xf_); D(yf_) << endl;
}

void remove_adj_vertical(int i, int j)
{
	//D("B") << endl;
	if (i-1 >= 0) {
		locked[i][j].insert(make_pair(i-1, j));
		locked[i-1][j].insert(make_pair(i, j));
	}
	//D("B-") << endl;
}

void remove_adj_horizontal(int i, int j)
{
	//D("A") << endl;
	if (j-1 >= 0) {
		// D(i); D(j) << endl;
		locked[i][j].insert(make_pair(i, j-1));
		locked[i][j-1].insert(make_pair(i, j));
	}
	//D("A-") << endl;
}

int main()
{
	cin >> dx >> dy >> n;
	locked = V<V< set<P<int,int>> >>(dy, V< set<P<int,int>> >(dx));
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		parse_s(s);
		if (xf_ < x0_) swap(x0_, xf_);
		if (yf_ < y0_) swap(y0_, yf_);
		if (x0_ == xf_) {
			for (int j = y0_; j < yf_; ++j) {
				remove_adj_vertical(x0_, j);
			}
		}
		else {
			for (int j = x0_; j < xf_; ++j) {
				remove_adj_horizontal(j, y0_);
			}
		}
	}
	cout << BFS() << endl;
}

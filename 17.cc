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

int main()
{
	string s;
	while (cin >> s) {
		int n = s.size();
		V<int> a(n);
		for (int i = 0; i < n; ++i) {
			a[i] = s[i] - '0';
		}
		int sum_ = 0;
		for (int i = 0; i < n; ++i) {
			if (a[i] == a[(i+1)%n]) {
				if (a[i] % 2 == 0) {
					sum_ += a[i] * (i+1);
				}
				else {
					sum_ += a[i];
				}
			}
		}
		cout << sum_ << endl;
	}
}

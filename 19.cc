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
	int caca;
	cin >> caca;

	map<char,int> col;
	string s;
	while (getline(cin, s)) {
		for (char c : s) {
			if (col.find(c) == col.end()) {
				col[c] = 1;
			}
			else {
				col[c] = col[c]+1;
			}	
		}	
	}
	for (auto it : col) {
		cout << "- " << ceil(it.second / 100.0) << " skeins of yarn " <<  it.first << endl;
	}
}

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

map<char, char> complement;
set<char> opening;
set<char> closing;
string s, r;

int main()
{
	opening.insert('(');
	opening.insert('[');
	opening.insert('{');
	closing.insert(')');
	closing.insert(']');
	closing.insert('}');
	complement['('] = ')';
	complement['{'] = '}';
	complement['['] = ']';
	complement[')'] = '(';
	complement['}'] = '{';
	complement[']'] = '[';

	getline(cin, s);
	r = s;

	stack<char> open;
	int fix = 0;

	for (int i = 0; i < s.size(); ++i) {
		if (opening.count(s[i]) > 0) {
			open.push(s[i]);
		}
		else if (closing.count(s[i]) > 0) {
			if (s[i] != complement[open.top()]) {
				r[i] = complement[open.top()];
				++fix;
			}
			open.pop();
		}
	}

	cout << r << endl << fix << " fixes made to the formula." << endl;
}

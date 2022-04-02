#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
const double PI = acos(-1);
const ll mod7 = 1e9 + 7;
const ll mod9 = 998244353;
const ll INF = 2 * 1024 * 1024 * 1023;
#define forn(i, n) for (int i = 0; i < int(n); i++)
 
ll l, r, k, n, m, p, q, u, v, w, x;
 
//////////////////  LIBRARY CODE /////////////////////

//////////////////////////////////////////////////////
 
bool multiTest = false;
void solve() {

	ll a,b,c,d;
	cin >> a >> b >> c >> d;

	bool swapped = false;
	if(b > a) {
		swapped = true;
		swap(a, b);
		swap(c, d);
	}

	vector<vi> ans;
	if(a == b) {
		if(c != d) {
			cout << 0 << '\n';
			return;
		}
		int cur = a;
		while(cur > 1) {
			if(cur % 2) {
				ans.push_back({1, cur, cur});
				cur++;
			}
			ans.push_back({2, cur, cur});
			cur /= 2;
		}

		while(cur != c) {
			ans.push_back({1, cur, cur});
			cur++;
		}

		cout << ans.size() << '\n';
		for(auto z : ans) {
			for(auto y : z) cout << y << ' ';
			cout << '\n';
		}
		return;
	}	

	if(c == d) {
		cout << 0 << '\n';
		return;
	}

	int cura = a;
	int curb = b;

	while((cura - curb) % 2 == 0) {
		if(cura % 2) {
			if(swapped) ans.push_back({1, curb, cura});
			else ans.push_back({1, cura, curb});
			cura++;
			curb++;
		}
		if(swapped) ans.push_back({2, curb, cura});
		else ans.push_back({2, cura, curb});
		cura /= 2;
		curb /= 2;
	}

	int minDiff = cura - curb;
	int finaldiff = c-d;

	if(minDiff * finaldiff < 0) {
		cout << 0 << '\n';
		return;
	}

	if(finaldiff % minDiff) {
		cout << 0 << '\n';
		return;
	}

	if(curb > d) {
		cout << 0 << '\n';
		return;
	}

	int starta = cura;
	int startb = curb;

	while(cura != c) {
		if(swapped) ans.push_back({1, curb, cura});
		else ans.push_back({1, cura, curb});
		curb++;
		cura++;
	}

	int firstInterval = d + minDiff;
	int secondInterval = d + minDiff*2;

	while(true) {
		if(secondInterval > c) break;
		if(swapped) ans.push_back({3, d, firstInterval, firstInterval, secondInterval});
		else ans.push_back({3, secondInterval, firstInterval, firstInterval, d});
		firstInterval += minDiff;
		secondInterval += minDiff;
	}

	cout << ans.size() << '\n';
	for(auto y : ans) {
		for(auto z : y) {
			cout << z << ' ';
		}
		cout << '\n';
	}

}

int main() {
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    #ifdef yangster
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
 
    int t = 1;
    if (multiTest) cin >> t;
    for (int ii = 0; ii < t; ii++) {
        solve();
    }
 
}

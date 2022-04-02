#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
const double PI = 3.14159265358979323846;
const ll mod7 = 1e9 + 7;
const ll mod9 = 998244353;
const ll MOD = mod9;
const ll INF = 2 * 1024 * 1024 * 1023;
#define forn(i, n) for (int i = 0; i < int(n); i++)


ll k, n, m, q, u, v, w;

ll a;

//////////////////  LIBRARY CODE /////////////////////

//////////////////////////////////////////////////////

bool multiTest = false;
void solve() {

    string s;
    cin >> s;

    cout << (s.substr(0,3) == "555" ? "YES" : "NO") << '\n';

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
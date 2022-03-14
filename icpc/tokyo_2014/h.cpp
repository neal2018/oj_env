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

vector<int> primes(0);
void gen_primes(int a) {
  vector<bool> is_prime(a + 1, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i * i <= a; i++) {
    if (is_prime[i]) {
      for (int j = i * i; j <= a; j += i) is_prime[j] = false;
    }
  }
  for (int i = 0; i <= a; i++) {
    if (is_prime[i]) primes.push_back(i);
  }
}
vector<ll> gen_factors_prime(ll a) {
  vector<ll> factors;
  factors.push_back(1);
  for (int z : primes) {
    if (z * z > a) {
      z = a;
    }
    int cnt = 0;
    while (a % z == 0) {
      cnt++;
      a /= z;
    }
    ll num = z;
    int size = factors.size();
    for (int i = 1; i <= cnt; i++) {
      for (int j = 0; j < size; j++) {
        factors.push_back(num * factors[j]);
      }
      num *= z;
    }
    if (a == 1) break;
  }
  return factors;
}
vector<ll> get_primes(ll num) {
  vector<ll> curPrime;
  if (num == 1) return curPrime;
  for (int z : primes) {
    if (z * z > num) {
      curPrime.push_back(num);
      break;
    }
    if (num % z == 0) {
      curPrime.push_back(z);
      while (num % z == 0) num /= z;
    }
    if (num == 1) break;
  }
  return curPrime;
}

//////////////////////////////////////////////////////

bool multiTest = false;
void solve() {
  gen_primes(1e5);

  cin >> n;

  set<ll> ans;

  forn(i, n) {
    ll z;
    cin >> z;

    vector<ll> primes = get_primes(z);
    for (ll y : primes) {
      ans.insert(y);
    }
  }

  int cnt = 0;
  for (ll z : ans) {
    if (cnt != 0 && cnt % 5 == 0) cout << '\n';
    cout << z;
    cnt++;
    if (cnt % 5 != 0) cout << ' ';
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
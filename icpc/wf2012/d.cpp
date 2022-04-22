#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = double;

const auto PI = acos(-1);
constexpr ld eps = 1e-12;
const int MX = 101;
const int MXLEN = 5e5;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(10);

  vector<ll> fa(MX), fb(MX), fab(MX), fba(MX), fbb(MX);
  vector<string> F(MX);
  int k = -1;
  fa[0] = 1;
  fa[1] = 0;
  fb[0] = 0;
  fb[1] = 1;
  fbb[0] = 0;
  fbb[1] = 0;
  F[0] = "0", F[1] = "1";
  for (int i = 2; i < MX; i++) {
    fa[i] = fa[i - 2] + fa[i - 1];
    fb[i] = fb[i - 2] + fb[i - 1];
    fab[i] = fab[i - 2] + fab[i - 1];
    fba[i] = fba[i - 2] + fba[i - 1];
    fbb[i] = fbb[i - 2] + fbb[i - 1];
    if (i & 1)
      fab[i]++;
    else if (i != 2)
      fbb[i]++;
    if (i == 2) fba[i]++;
    if (k == -1) {
      F[i] = F[i - 1] + F[i - 2];
      if ((int)F[i].length() > MXLEN) {
        k = i - 1;
      }
    }
  }

  auto get_next = [&](string& pat) {
    int m = (int)pat.length();
    vector<int> nex(m);
    for (int i = 1, j = 0; i < m; i++) {
      while (j && pat[j] != pat[i]) j = nex[j - 1];
      if (pat[j] == pat[i]) j++;
      nex[i] = j;
    }
    return nex;
  };

  auto count_matches = [&](string p, string a, string b) {
    string c = a + b;
    // cout << "I am trying to find " << p << " in " << c << '\n';
    int n1 = (int)a.length(), n2 = (int)b.length();
    int matches = 0;
    auto nex = get_next(p);
    for (int i = 0, j = 0; i < n1 + n2; i++) {
      while (j && p[j] != c[i]) j = nex[j - 1];
      if (p[j] == c[i]) j++;
      if (j == (int)p.length()) {
        // cout << i << ' ' << j << " wat\n";
        if (n2 == 0)
          matches++;
        else {
          int si = i - (int)p.length() + 1;
          if (i >= n1 && si < n1) matches++;
        }
        j = nex[j - 1];
      }
    }
    return matches;
  };

  auto smart = [&](ll n, string p) {
    n -= k;
    ll a_cont = count_matches(p, F[k], "");
    ll b_cont = count_matches(p, F[k + 1], "");
    ll ab_cont = count_matches(p, F[k], F[k + 1]);
    ll ba_cont = count_matches(p, F[k + 1], F[k]);
    ll bb_cont = count_matches(p, F[k + 1], F[k + 1]);
    // cout << a_cont << ' ' << b_cont << ' ' << 
    return a_cont * fa[n] + b_cont * fb[n] + ab_cont * fab[n] + ba_cont * fba[n] + bb_cont * fbb[n];
  };
  auto bf = [&](ll n, string p) {
    ll m = p.size();
    ll res = 0;
    for (int i = 0; i + m <= F[n].size(); i++) {
      if (F[n].substr(i, m) == p) res++;
    }
    return res;
  };
  // cout << "k= " << k << "\n";
  // for (int i = 0; i < k; i++) cout << F[i].size() << "\n";
  ll T = 1, n;
  while (cin >> n) {
    cout << "Case " << T << ": ";
    string p;
    cin >> p;
    // k = 15;
    {
      ll res = 0;
      if (n <= k)
        res = count_matches(p, F[n], "");
      else {
        res = smart(n, p);
      }
      // assert(res == bf(n, p));
      // ll t = bf(n, p);
      // cout << F[n] << "\n";
      // cout << res << " " << t << "\n";
      cout << res << "\n";
    }
    T++;
  }
}

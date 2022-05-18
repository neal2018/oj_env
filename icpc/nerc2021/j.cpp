#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);

  int n;
  cin >> n;

  vector<vector<ll>> cost(n, vector<ll>(n)), pref(n, vector<ll>(n + 1));
  for(int i = 0; i < n; i++) {
    pref[i][0] = 0; 
    for(int j = 0; j < n; j++) {
      cin >> cost[i][j];
      pref[i][j + 1] = cost[i][j] + pref[i][j];
    }
  }

  auto get = [&](int i, int l, int r) {
    return pref[i][r + 1] - pref[i][l];
  };

  vector<vector<ll>> dp(n, vector<ll>(n, -1)), root(n, vector<ll>(n));
  for(int i = 0; i < n; i++) {
    dp[i][i] = get(i, 0, i - 1) + get(i, i + 1, n - 1);
    root[i][i] = i;
  }
  for(int i = 1; i < n; i++) {
    for(int j = 0; j < n - i; j++) {
      int l = j, r = j + i;
      ll incr = 0;
      for(int k = l; k <= r; k++) {
        incr += get(k, 0, l - 1);
        incr += get(k, r + 1, n - 1);
      }
      for(int k = l; k <= r; k++) {
        ll cand = incr;
        if(k > l) cand += dp[l][k - 1];
        if(k < r) cand += dp[k + 1][r];
        if(dp[l][r] == -1 || cand < dp[l][r]) {
          dp[l][r] = cand;
          root[l][r] = k;
        }
      }
    }
  }

  vector<int> parent(n, - 1);
  function<void(int,int,int)> recurse = [&](int par, int l, int r) {
    if(l > r) return;
    int mid = (int)root[l][r];
    /*
    if(mid < l || mid > r) {
      cout << "wat? " << l << ' ' << r << ' ' << mid << '\n';
      assert(0); 
    } */
    parent[mid] = par;
    recurse(mid, l, mid - 1);
    recurse(mid, mid + 1, r); 
  };
  recurse(-1, 0, n - 1);

  for(int i = 0; i < n; i++) cout << parent[i] + 1 << ' ';
  cout << '\n';
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void print(__int128 x) {
  constexpr ll P = 1e18;
  if (x < P) {
    cout << ll(x) << "\n";
  } else {
    cout << ll(x / P) << setw(18) << setfill('0') << ll(x % P) << "\n";
  }
}

constexpr int N = 51;
__int128 comb[N][N];

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  for (int i = 0; i < N; i++) {
    comb[0][i] = 0, comb[i][0] = 1;
  }
  for (int i = 1; i < N; i++) {
    for (int j = 1; j < N; j++) {
      comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
    }
  }
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  for (auto& x : a) cin >> x;
  sort(a.begin(), a.end());
  ll l, r;
  cin >> l >> r;
  auto solve = [&](ll limit) mutable {
    auto t = a;
    __int128 res = 0, remain = k;
    while (t.size() && remain) {
      while (t.size() && t.back() >= limit) {
        t.pop_back();
      }
      if (remain > t.size()) {
        break;
      }
      if (t.size()) {
        res += comb[(int(t.size()) - 1)][remain];
        limit -= t.back();
        t.pop_back();
        remain--;
      }
      if (remain == 0) res++;
    }
    return res;
  };
  auto x = solve(r + 1);
  auto y = solve(l);
  print(x - y);
}

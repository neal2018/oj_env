#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool solve() {
  ll n, r, R;
  cin >> n >> r >> R;
  vector<ll> a(n);
  for (auto& x : a) cin >> x;
  if (r == 0) {
    return true;
  } else if ((r <= 1000 && R == 1'000'000'000) || n == 2) {
    auto sum = accumulate(a.begin(), a.end(), 0ll);
    for (auto& x : a) {
      if (R * x >= r * (sum - x) && r * (sum - x) >= r * x) {
        return true;
      }
    }
    return false;
  } else {
    return true;
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << (solve() ? "YES\n" : "NO\n");
}
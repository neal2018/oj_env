#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  ll n, m;
  cin >> n >> m;
  vector<ll> a(n), b(m);
  for (auto& x : a) cin >> x;
  for (auto& x : b) cin >> x, x--;
  set<int> st(b.begin(), b.end());
  ll maxi = *max_element(a.begin(), a.end());
  for (int i = 0; i < n; i++) {
    if (maxi == a[i] && st.count(i)) {
      cout << "Yes\n";
      return 0;
    }
  }
  cout << "No\n";
}

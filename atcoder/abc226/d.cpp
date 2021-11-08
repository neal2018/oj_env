#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
  set<pair<int, int>> st;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int dx = x[i] - x[j], dy = y[i] - y[j];
      if (dy == 0) st.insert({1, 0}), st.insert({-1, 0});
      if (dx == 0) st.insert({0, 1}), st.insert({0, -1});
      if (dx == 0 || dy == 0) continue;
      int g = abs(__gcd(dx, dy));
      dx /= g, dy /= g;
      st.insert({dx, dy}), st.insert({-dx, -dy});
    }
  }
  cout << st.size() << '\n';
}
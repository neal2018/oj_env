#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T, k, x1, x2, y1, y2;
  cin >> T;
  // auto solve = [&] {
  // };
  for (ll ttt = 1; ttt <= T; ttt++) {
    cin >> k;
    vector<ll> xs, ys;
    for (int i = 0; i < k; i++) {
      cin >> x1 >> y1 >> x2 >> y2;
      xs.push_back(x1);
      xs.push_back(x2);
      ys.push_back(y1);
      ys.push_back(y2);
    }
    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());

    cout << "Case #" << ttt << ": " << xs[k - 1] << ' ' << ys[k - 1] << '\n';
  }
  return 0;
}
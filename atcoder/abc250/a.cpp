#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  ll h, w, r, c;
  cin >> h >> w >> r >> c;
  ll cnt = 0;
  vector<pair<ll, ll>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  for (auto& [di, dj] : directions) {
    ll ii = r + di, jj = c + dj;
    if (1 <= ii && ii <= h && 1 <= jj && jj <= w) {
      cnt++;
    }
  }
  cout << cnt << "\n";
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  // int T;
  // cin >> T;
  // while (T--) {
  //   int n, m, k;
  //   string s;
  //   cin >> n >> m >> k >> s;
  // }
  vector<pair<int, int>> a = {{1, 2}};
  auto &&[x, y] = a.back();
  a.pop_back();
  cout << x << y << "\n";
}

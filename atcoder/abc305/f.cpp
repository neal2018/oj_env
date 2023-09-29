#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  auto get_neighbor = [] {
    int cnt;
    cin >> cnt;
    vector<int> a(cnt);
    for (auto& x : a) cin >> x, x--;
    return a;
  };
  vector<int> seen(n);
  seen[0] = 1;
  function<void(int, int)> dfs = [&](int node, int fa) {
    if (node == n - 1) {
      string s;
      cin >> s;
      exit(0);
    }
    auto a = get_neighbor();
    for (auto& x : a) {
      if (seen[x] == 0) {
        seen[x] = 1;
        cout << x + 1 << endl;
        dfs(x, node);
      }
    }
    cout << fa + 1 << endl;
    get_neighbor();
  };
  dfs(0, -1);
}

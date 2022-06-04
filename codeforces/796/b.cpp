#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  auto ask = [](string& s) {
    cout << "? " << s << endl;
    int res = 0;
    cin >> res;
    return res;
  };
  ll n, m;
  cin >> n >> m;
  string s(m, '0');
  vector<pair<int, int>> a(m);
  for (auto i : views::iota(0, m)) {
    s[i] = '1';
    a[i] = {ask(s), i};
    s[i] = '0';
  }
  ranges::sort(a);
  int cur = 0;
  for (auto& [v, i] : a) {
    s[i] = '1';
    int nex = ask(s);
    if (nex - cur != v) {
      s[i] = '0';
    } else {
      cur = nex;
    }
  }
  cout << "! " << cur << endl;
}

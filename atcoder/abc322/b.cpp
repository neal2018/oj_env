#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  string s, t;
  cin >> n >> m >> s >> t;
  // cout << t.substr(n) << " " << s << '\n';
  auto is_prefix = (t.substr(0, n) == s);
  auto is_suffix = (t.substr(m - n, n) == s);
  if (is_prefix && is_suffix) {
    cout << "0\n";
  } else if (is_prefix && !is_suffix) {
    cout << "1\n";
  } else if (!is_prefix && is_suffix) {
    cout << "2\n";
  } else {
    cout << "3\n";
  }
}

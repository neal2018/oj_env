#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
const ll MOD = 1e9 + 7;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T, n;
  string s;
  cin >> T;
  while (T--) {
    cin >> n >> s;
    int one = count(s.begin(), s.end(), '0');
    vector<int> v;
    for (int i = 0; i < one; i++) {
      if (s[i] == '1') v.push_back(i + 1);
    }
    for (int i = one; i < n; i++) {
      if (s[i] == '0') v.push_back(i + 1);
    }
    cout << (v.size() > 0) << '\n';
    if (v.size()) {
      cout << v.size() << ' ';
      for (auto& x : v) cout << x << ' ';
      cout << '\n';
    }
  }
}
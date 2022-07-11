#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    auto s = to_string(n);
    s[0] = '1';
    for (int i = 1; i < s.size(); i++) s[i] = '0';
    int t = stoi(s);
    cout << n - t << "\n";
  }
}

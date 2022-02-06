#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    ll one = count(s.begin(), s.end(), '1'), zero = s.size() - one;
    cout << min(one, zero) - (one == zero) << "\n";
  }
}
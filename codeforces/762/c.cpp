#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T;
  string a, s;
  cin >> T;
  while (T--) {
    cin >> a >> s;
    function<string(int, int)> f = [&](int i, int j) {
      if (i == -1 && j == -1) return (string) "";
      if (j < 0) return (string) "-1";
      if (i < 0) return s.substr(0, j + 1);
      if (s[j] >= a[i]) {
        auto t = f(i - 1, j - 1);
        if (t != "-1") return (t + (char)(s[j] - a[i] + '0'));
      } else if (j != 0 && s[j - 1] == '1') {
        auto t = f(i - 1, j - 2);
        if (t != "-1") return (t + (char)(s[j] - a[i] + 10 + '0'));
      }
      return (string) "-1";
    };
    cout << stoll(f((int)a.size() - 1, (int)s.size() - 1)) << '\n';
  }
}
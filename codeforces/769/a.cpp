#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T;
  cin >> T;
  for (; T--;) {
    int n;
    string s;
    cin >> n >> s;
    int f = 1;
    for (int i = 0; i < n - 1; i++) {
      if (s[i] == s[i + 1]) f = 0;
    }
    for (int i = 1; i < n - 1; i++) {
      if (s[i - 1] == s[i + 1]) f = 0;
    }
    cout << (f ? "YES\n" : "NO\n");
  }
}
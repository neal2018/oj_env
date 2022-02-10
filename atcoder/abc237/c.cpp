#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  string s;
  cin >> s;
  int n = int(s.size());
  int start = 0, end = n - 1;
  while (start < end) {
    if (s[start] == 'a' && s[end] == 'a') {
      start++, end--;
    } else if (s[end] == 'a') {
      end--;
    } else {
      break;
    }
  }
  int f = 1;
  while (start < end) {
    if (s[start] != s[end]) {
      f = 0;
      break;
    }
    start++, end--;
  }
  cout << (f ? "Yes\n" : "No\n");
}

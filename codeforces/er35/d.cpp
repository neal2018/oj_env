#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  for (int tt = 0; tt < T; tt++) {
    int n;
    string s;
    cin >> n >> s;
    int big = 0, sz = 0;
    for (int i = 0, j; i < n; i = j) {
      for (j = i; j < n && s[i] == s[j];) j++;
      big = min(big + j - i - 1, sz + 1), sz++;
    }
    cout << big + (sz - big + 1) / 2 << "\n";
  }
}

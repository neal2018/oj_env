#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  for (auto& x : a) cin >> x;
  for (auto& s : a) {
    for (int i = 0, j; i < m; i = j) {
      for (j = i; j < m && s[i] == s[j];) j++;
      if (s[i] == '.') continue;
      for (int k = i; k + 1 < j; k += 2) {
        s[k] = 'P', s[k + 1] = 'C';
      }
    }
    cout << s << "\n";
  }
}

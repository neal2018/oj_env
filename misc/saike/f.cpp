#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  vector<vector<int>> a(26);
  for (int i = 0; i < n; i++) {
    a[s[i] - 'A'].push_back(i);
  }
  int last = [&] {
    int cur = n;
    for (int i = n - 1; i >= 0; i--) {
      int c = t[i] - 'A';
      while (a[c].size() && a[c].back() >= cur) {
        a[c].pop_back();
      }
      if (a[c].size()) {
        cur = a[c].back();
        a[c].pop_back();
      } else {
        return i;
      }
    }
    return -1;
  }();
  cout << last + 1 << "\n";
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    string s;
    cin >> s;
    map<int, char> mp;
    if ([&] {
          for (int i = 0; i < n; i++) {
            if (mp.count(a[i])) {
              if (mp[a[i]] != s[i]) return false;
            }
            mp[a[i]] = s[i];
          }
          return true;
        }()) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}

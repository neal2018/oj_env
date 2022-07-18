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
    vector<set<string>> st(9);
    vector<string> a(n);
    for (auto& x : a) cin >> x, st[x.size()].insert(x);
    for (auto& s : a) {
      [&] {
        for (int i = 1; i < s.size(); i++) {
          if (st[i].count(s.substr(0, i)) && st[s.size() - i].count(s.substr(i))) {
            cout << "1";
            return;
          }
        }
        cout << "0";
      }();
    }
    cout << "\n";
  }
}

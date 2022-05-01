#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int T;
  cin >> T;
  while (T--) {
    ll n;
    string s;
    cin >> n >> s;
    vector<int> q, nq;
    auto check = [&](int i) {
      if (i >= n - 1) return false;
      if (i < 0) return false;
      auto t = s.substr(i, 2);
      if (t == "RB" || t == "BR" || t == "BE" || t == "RE" || t == "EB" || t == "ER") return true;
      return false;
    };
    auto clear = [&](int i) { s[i] = 'E', s[i + 1] = 'E'; };
    for (int i = 0; i < n - 1; i++) {
      if (check(i)) q.push_back(i);
    }
    for (; q.size(); swap(q, nq), nq.clear()) {
      for (auto& node : q) {
        clear(node);
        for (auto& ne : {node - 1, node + 1}) {
          if (check(ne)) nq.push_back(ne);
        }
      }
    }
    if (count(s.begin(), s.end(), 'R') == 0 && count(s.begin(), s.end(), 'B') == 0) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}

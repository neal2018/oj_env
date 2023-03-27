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
    vector<int> pos, neg;
    for (int i = 0, x; i < n; i++) {
      cin >> x;
      if (x > 0) pos.push_back(x);
      if (x < 0) neg.push_back(-x);
    }
    sort(pos.rbegin(), pos.rend());
    sort(neg.rbegin(), neg.rend());
    if (pos.size() == 0 && neg.size() == 0) {
      cout << "No\n";
      continue;
    }
    vector<int> res(n);
    ll cur = 0, cur_i = 0;
    int i = 0, j = 0;
    while (i < pos.size() && j < neg.size()) {
      if (cur <= 0) {
        res[cur_i++] = pos[i];
        cur += pos[i++];
      } else {
        res[cur_i++] = -neg[j];
        cur -= neg[j++];
      }
    }
    while (i < pos.size()) {
      res[cur_i++] = pos[i++];
    }
    while (j < neg.size()) {
      res[cur_i++] = -neg[j++];
    }
    cout << "Yes\n";
    for (auto& x : res) cout << x << " ";
    cout << "\n";
  }
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int x;
    cin >> x;
    vector<int> res;
    for (int i = 0; i < 31; i++) {
      if (x & (1 << i)) res.push_back(i);
    }
    int last = res.back() - 1;
    res.pop_back();
    while (last >= 0) {
      res.push_back((last));
      last--;
    }
    cout << res.size() + 1 << "\n";
    cout << x << " ";
    for (auto& t : res) {
      x -= (1 << t);
      cout << x << " ";
    }
    cout << "\n";
  }
}

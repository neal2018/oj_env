#include <bits/stdc++.h>
using namespace std;
#define ll long long
// #define LOCAL

int main() {
#ifdef LOCAL
  ifstream cin("/Users/neallai/Projects/oj_env/input.txt");
  ofstream cout("/Users/neallai/Projects/oj_env/output.txt");
#endif  // LOCAL
  int T, n;
  cin >> T;
  while (T--) {
    cin >> n;
    auto solve = [&](int n) {
      vector<int> a(n), res;
      for (auto& x : a) cin >> x;
      for (int i = 0; i < n; i++) {
        if (((i + 1) & 1) != (a[i] & 1)) {
          cout << -1 << endl;
          return;
        }
      }
      auto find_pos = [&](int x) { return (int)(find(a.begin(), a.end(), x) - a.begin()); };
      auto flip = [&](int x) {
        res.push_back(x);
        reverse(a.begin(), a.begin() + x + 1);
      };
      auto print = [&]() {
        for (auto& x : a) cout << x << " ";
        cout << endl;
      };
      for (int i = n; i >= 3; i -= 2) {
        int pos = find_pos(i);
        flip(pos);
        int pre_pos = find_pos(i - 1);
        flip(pre_pos - 1);
        flip(pre_pos + 1);
        flip(2);
        flip(i - 1);
      }
      cout << res.size() << endl;
      for (auto& x : res) cout << x + 1 << " ";
      cout << endl;
    };
    solve(n);
  }
}
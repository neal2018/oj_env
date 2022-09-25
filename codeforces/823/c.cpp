#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    vector<int> stk, remain;
    for (auto& c : s) {
      while (stk.size() && stk.back() > (c - '0')) {
        remain.push_back(min(stk.back() + 1, 9));
        stk.pop_back();
      }
      stk.push_back(c - '0');
    }
    for (auto& x : remain) stk.push_back(x);
    sort(stk.begin(), stk.end());
    for (auto& x : stk) cout << x;
    cout << "\n";
  }
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    string s;
    cin >> n >> s;
    vector<int> stk2;
    s = '(' + s + ')';
    ll res = 0;
    for (auto& x : s) {
      if (x == '(') {
        stk2.push_back(-1);
      } else {
        int cnt = 0;
        while (stk2.back() != -1) {
          stk2.pop_back();
          cnt++;
        }
        stk2.back() = 1;
        if (cnt) res++;
      }
    }
    cout << res << "\n";
  }
}

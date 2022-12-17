#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n;
    string s;
    cin >> n >> s;
    vector<int> a(n + 1);
    for (int i = 0; i < n; i++) a[i + 1] = a[i] + (s[i] == '(' ? 1 : -1);
    ll mini = 0;
    {
      vector<int> stk;
      for (int i = 0; i <= a.size(); i++) {
        while (stk.size() && (i == a.size() || a[stk.back()] >= a[i])) {
          auto id = stk.back();
          stk.pop_back();
          ll left = id - (stk.size() ? stk.back() : -1);
          ll right = i - id;
          mini += (left * right - 1) * a[id];
        }
        stk.push_back(i);
      }
    }
    ll maxi = 0;
    sort(a.begin(), a.end(), greater());
    for (int i = 0; auto& x : a) {
      maxi += x * (n - i);
      i++;
    }
    cout << maxi - mini << "\n";
  }
}

#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  vector<int> mini(1200, 1e9);
  set<int> st = {0};
  for (auto& x : a) {
    for (int i = 0; i <= 1024; i++) {
      if (mini[i] < x) {
        st.insert(x ^ i);
        mini[x ^ i] = min(x, mini[x ^ i]);
      }
    }
    mini[x] = min(x, mini[x]);
    st.insert(x);
  }
  cout << st.size() << '\n';
  for (auto& x : st) cout << x << " ";
  cout << '\n';
}
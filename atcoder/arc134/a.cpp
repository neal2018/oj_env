#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  ll n, l, w;
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> l >> w;
  map<ll, ll> st;  // pos, di
  st[0] = 0, st[l] = 0;
  for (ll i = 0, x; i < n; i++) {
    cin >> x;
    st[x]++, st[x + w]--;
  }
  ll cur = 0, need = 0;
  for (auto it = st.begin(); it != st.end(); it++) {
    if (it->first >= l) break;
    cur += it->second;
    if (cur == 0) {
      auto tt = it;
      tt++;
      ll nex = tt->first;
      ll add = (nex - it->first + w - 1) / w;
      need += add;
      cur++;
      st[it->first + add * w]--;
    }
  }
  cout << need << "\n";
}
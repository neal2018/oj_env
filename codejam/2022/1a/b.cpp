#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

constexpr ll inf = 1e9;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int T;
  cin >> T;
  for (int case_num = 1; case_num <= T; case_num++) {
    int n;
    cin >> n;
    ll sum = 0;
    for (int i = 0; i < 30; i++) {
      cout << (1ll << i) << " ";
      sum += (1ll << i);
    }
    set<ll> st;
    for (int i = 0; i < 70; i++) {
      cout << inf - i << " ";
      sum += inf - i;
      st.insert(i - inf);
    }
    cout << endl;
    for (int i = 0; i < 100; i++) {
      ll x;
      cin >> x;
      sum += x;
      st.insert(-x);
    }
    ll need = sum / 2;
    while (need > (1ll << 30) && st.size()) {
      auto maxi = -*st.begin();
      st.erase(st.begin());
      need -= maxi;
      cout << maxi << " ";
    }
    for (int i = 0; i < 30; i++) {
      if (need & (1ll << i)) {
        cout << (1ll << i) << " ";
      }
    }
    cout << endl;
  }
}

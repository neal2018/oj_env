#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  ll T, s, n;
  cin >> T;
  while (T--) {
    cin >> s >> n;
    string ss = to_string(s);
    ll sum = 0;
    multiset<ll> st;
    for (int i = ss.size() - 1, mul = 1; i >= 0; i--, mul *= 10) {
      sum += ss[i] - '0';
      for (ll x = 0; x < ss[i] - '0'; x++) st.insert(mul);
    }
    if (sum >= n) {
      while (n > 1) {
        cout << *st.begin() << " ";
        n--, s -= *st.begin();
        st.erase(st.begin());
      }
      cout << s << '\n';
    } else {
      ll diff = n - sum;
      vector<ll> ones;
      while (diff > 0) {
        ll x = *st.begin();
        st.erase(st.begin());
        ll mul = 1;
        for (ll temp = x; temp % 10 == 0; temp /= 10) mul *= 10;
        if (mul == 1) {
          ones.push_back(x);
          continue;
        }
        mul /= 10;
        diff++;
        while (diff > 0 && x > 0) {
          if (diff == 1) {
            diff--;
            st.insert(x);
          } else {
            x -= mul;
            diff--;
            st.insert(mul);
          }
        }
      }
      for (auto& x : ones) cout << x << " ";
      for (auto& x : st) cout << x << " ";
      cout << '\n';
    }
  }
}
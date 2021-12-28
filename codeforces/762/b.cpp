#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T, n;
  cin >> T;
  auto f = [&]() {
    cin >> n;
    set<ll> st;
    ll a = 1;
    while (a * a <= n) {
      st.insert(a * a), a++;
    }
    a = 1;
    while (a * a * a <= n) {
      st.insert(a * a * a), a++;
    }
    cout << st.size() << '\n';
  };
  while (T--) f();
}
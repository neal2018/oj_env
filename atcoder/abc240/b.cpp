#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  set<ll> st;
  for (auto& x : a) cin >> x, st.insert(x);
  cout << st.size() << "\n";
}

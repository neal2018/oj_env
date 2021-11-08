#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, l;
  cin >> n;
  set<vector<int>> st;
  for (int i = 0; i < n; i++) {
    cin >> l;
    vector<int> a(l);
    for (auto& x : a) cin >> x;
    st.insert(a);
  }
  cout << st.size() << '\n';
}
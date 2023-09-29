#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  string s, t;
  cin >> n >> s >> t;
  replace(s.begin(), s.end(), '0', 'o');
  replace(s.begin(), s.end(), '1', 'l');
  replace(t.begin(), t.end(), '0', 'o');
  replace(t.begin(), t.end(), '1', 'l');
  cout << ((s == t ? "Yes\n" : "No\n"));
}

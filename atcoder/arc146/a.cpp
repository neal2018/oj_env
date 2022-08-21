#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<string> a(n);
  for (auto& x : a) cin >> x;
  auto cmp_size = [&](auto& x, auto& y) { return x.size() > y.size(); };
  auto cmp_lex = [&](auto& x, auto& y) { return x + y > y + x; };
  sort(a.begin(), a.end(), cmp_size);

  int t = 0;
  while (t < n && a[0].size() == a[t].size()) t++;
  int i = t;
  while (i < n && a[i].size() == a[t].size()) i++;
  sort(a.begin(), a.begin() + t, cmp_lex);
  sort(a.begin() + t, a.begin() + i, cmp_lex);
  sort(a.begin(), a.begin() + 3, cmp_lex);

  for (int i = 0; i < 3; i++) cout << a[i];
  cout << "\n";
}

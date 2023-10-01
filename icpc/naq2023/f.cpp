#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  string s;
  cin >> s;
  int a1 = 0, a2 = 0;
  set<char> v{'a', 'e', 'i', 'o', 'u'};
  set<char> vv{'a', 'e', 'i', 'o', 'u', 'y'};
  for (auto& x : s) {
    if (v.count(x)) a1++;
    if (vv.count(x)) a2++;
  }
  cout << a1 << " " << a2 << "\n";
}

#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T;
  cin >> T;
  string s, t;
  for (; T--;) {
    cin >> s >> t;
    ll a = count(s.begin(), s.end(), 'a');
    ll b = count(s.begin(), s.end(), 'b');
    ll c = count(s.begin(), s.end(), 'c');
    string remain = "";
    for (auto& x : s) {
      if (x != 'a' && x != 'b' && x != 'c') remain.push_back(x);
    }
    sort(remain.begin(), remain.end());
    if (t != "abc" || a * b * c == 0) {
      cout << string(a, 'a') + string(b, 'b') + string(c, 'c') + remain << '\n';
    } else {
      cout << string(a, 'a') + string(c, 'c') + string(b, 'b') + remain << '\n';
    }
  }
}
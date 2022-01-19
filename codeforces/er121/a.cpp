#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T;
  cin >> T;
  auto f = [&]() {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    cout << s << "\n";
  };
  for (; T--;) f();
}
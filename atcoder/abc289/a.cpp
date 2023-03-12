#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  string s;
  cin >> s;
  for (auto& c : s) c ^= '0' ^ '1';
  cout << s << "\n";
}

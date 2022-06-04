#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n;
    cin >> n;
    vector<string> a(2 * n + 1);
    map<char, int> mp;
    for (auto& s : a) {
      cin >> s;
      for (auto& c : s) mp[c]++;
    }
    cout << ranges::find_if(mp, [](auto x) { return x.second & 1; })->first << "\n";
  }
}

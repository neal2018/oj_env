#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  map<char, int> mp = {{'A', 0}, {'B', 3}, {'C', 4}, {'D', 8}, {'E', 9}, {'F', 14}, {'G', 23}};
  char p, q;
  cin >> p >> q;
  cout << abs(mp[p] - mp[q]) << "\n";
}

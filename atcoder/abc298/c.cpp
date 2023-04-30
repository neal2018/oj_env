#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, q;
  cin >> n >> q;
  vector<multiset<int>> boxes(n);
  map<int, set<int>> cards;
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int i, j;
      cin >> i >> j, i--, j--;
      boxes[j].insert(i);
      cards[i].insert(j);
    } else if (t == 2) {
      int i;
      cin >> i, i--;
      for (auto& x : boxes[i]) {
        cout << x + 1 << " ";
      }
      cout << "\n";
    } else {
      int i;
      cin >> i, i--;
      for (auto& x : cards[i]) {
        cout << x + 1 << ' ';
      }
      cout << "\n";
    }
  }
}

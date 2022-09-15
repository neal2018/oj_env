#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    if (n > m) {
      cout << "No\n";
      continue;
    }
    int remain = m - n;
    if (n % 2 == 0 && remain % 2 == 1) {
      cout << "No\n";
      continue;
    }
    vector<int> res(n, 1);
    if (n % 2 == 1) {
      res[0] += remain;
    } else {
      res[0] += remain / 2;
      res[1] += remain / 2;
    }
    cout << "Yes\n";
    for (auto& x : res) {
      cout << x << " ";
    }
    cout << "\n";
  }
}

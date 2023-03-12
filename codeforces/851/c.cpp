#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    if (n % 2 == 0) {
      cout << "No\n";
      continue;
    }
    cout << "Yes\n";
    vector<int> res(n);
    for (int i = 0; i < n / 2 + 1; i++) res[i] = n + n / 2 + 1 + i;
    for (int i = n / 2 + 1; i < n; i++) res[i] = n + i - n / 2;
    for (int i = 0; i < n; i++) cout << i + 1 << " " << res[i] << "\n";
  }
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int a, b;
    cin >> a >> b;
    char c = a > b ? '0' : '1';
    for (int t = min(a, b); t--;) cout << "01";
    for (int t = max(a, b) - min(a, b); t--;) cout << c;
    cout << "\n";
  }
}

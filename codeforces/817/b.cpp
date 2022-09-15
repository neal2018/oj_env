#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    string a, b;
    cin >> n >> a >> b;
    replace(a.begin(), a.end(), 'G', 'B');
    replace(b.begin(), b.end(), 'G', 'B');
    cout << (a == b ? "YES\n" : "NO\n");
  }
}

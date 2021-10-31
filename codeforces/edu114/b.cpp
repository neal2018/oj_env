#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(int argc, char const* argv[]) {
  int T, a, b, c, m;
  cin >> T;
  while (T--) {
    cin >> a >> b >> c >> m;
    int maxi = max(a - 1, 0) + max(b - 1, 0) + max(c - 1, 0);
    int mini = 1e9;
    if (c < a) swap(a, c);
    if (c < b) swap(b, c);
    if (b < a) swap(a, b);  // c>=b>=a
    mini = min(mini, c - a - b - 1);
    if (mini <= m && m <= maxi) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
    // bababababcb
    // 4 6 1
  }
}
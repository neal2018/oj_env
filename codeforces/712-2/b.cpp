#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
const ll MOD = 1e9 + 7;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T, n;
  string a, b;
  cin >> T;
  while (T--) {
    cin >> n >> a >> b;
    vector<int> diff(n + 1);
    for (int i = 0; i < n; i++) diff[i + 1] = diff[i] + (a[i] == '0' ? -1 : 1);
    int can = 1;
    for (int i = n - 1, f = 0; i >= 0 && can; i--) {
      if ((a[i] - '0') != ((b[i] - '0') ^ f)) {
        if (diff[i + 1] != 0) {
          can = 0;
        } else {
          f = !f;
        }
      }
    }
    cout << (can ? "YES\n" : "NO\n");
  }
}
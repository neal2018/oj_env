#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    string s;
    cin >> n >> s;
    int cur = 0;
    for (auto c : s) {
      if (c == '+') {
        cur++;
      } else {
        cur--;
      }
    }
    cout << abs(cur) << "\n";
  }
}

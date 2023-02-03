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
    int i = 0, j = n - 1;
    while (i < j) {
      if (s[i] ^ s[j]) {
        i++, j--;
      } else {
        break;
      }
    }
    cout << n - 2 * i << "\n";
  }
}

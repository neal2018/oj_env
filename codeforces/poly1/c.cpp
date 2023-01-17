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
    char prev = '?';
    int streaking = 0;
    for (int i = 0; i < n - 1; i++) {
      if (s[i] != prev) {
        prev = s[i], streaking = 1;
      } else {
        streaking++;
      }
      cout << i + 2 - streaking << " ";
    }
    cout << "\n";
  }
}

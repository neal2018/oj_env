#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  string t = "Timur";
  sort(t.begin(), t.end());
  while (T--) {
    int n;
    string s;
    cin >> n >> s;
    sort(s.begin(), s.end());
    cout << (t == s ? "YES\n" : "NO\n");
  }
}

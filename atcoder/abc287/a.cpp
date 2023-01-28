#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, cnt = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    if (s[0] == 'F') cnt++;
  }
  cout << (cnt > n / 2 ? "Yes\n" : "No\n");
}
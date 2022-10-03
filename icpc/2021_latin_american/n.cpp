#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  auto parse = [&] {
    string s;
    cin >> s;
    int x = 0;
    for (auto& c : s) {
      if (isdigit(c)) {
        x = 10 * x + (c - '0');
      }
    }
    return x;
  };
  int res = 0;
  int account = parse();
  while (n--) {
    account += parse();
    if (account % 100) res++;
    // cout << account << "\n";
  }
  cout << res << "\n";
}

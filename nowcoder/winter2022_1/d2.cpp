#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

bool check(int n) {
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  int i = 5;
  while (i * i <= n) {
    if (n % i == 0 || n % (i + 2) == 0) return false;
    i = i + 6;
  }
  return true;
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  vector<int> mini = {2, 6, 30, 210, 2310, 30030, 510510, 9699690, 223092870};
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    if (n == 1) {
      cout << -1 << "\n";
      continue;
    }
    auto it_mini = upper_bound(mini.begin(), mini.end(), n);
    cout << *(--it_mini) << " ";
    while (true) {
      if (check(n)) {
        cout << n << "\n";
        break;
      }
      n--;
    }
  }
}
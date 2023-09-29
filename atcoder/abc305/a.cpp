#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  if (n % 5 < 3) {
    cout << n / 5 * 5 << "\n";
  } else {
    cout << n / 5 * 5 + 5 << "\n";
  }
}

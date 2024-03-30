#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int a, b;
    cin >> a >> b;
    cout << [&] {
      if (abs(a - b) % 2 == 0) {
        return "Bob\n";
      } else {
        return "Alice\n";
      }
    }();
  }
}

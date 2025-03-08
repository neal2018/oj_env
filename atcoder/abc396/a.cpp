#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto& x : a) std::cin >> x;

  if ([&] {
        int same = 1;
        for (int i = 1; i < n; i++) {
          if (a[i] == a[i - 1]) {
            same++;
          } else {
            same = 1;
          }
          if (same >= 3) {
            return true;
          }
        }

        return false;
      }()) {
    std::cout << "Yes\n";
  } else {
    std::cout << "No\n";
  }
}

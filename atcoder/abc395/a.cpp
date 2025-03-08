#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (auto& x : a) std::cin >> x;
  std::cout << ([&] {
    for (int i = 0; i < n - 1; i++) {
      if (a[i + 1] <= a[i]) {
        return false;
      }
    }
    return true;
  }()
                    ? "Yes\n"
                    : "No\n");
}

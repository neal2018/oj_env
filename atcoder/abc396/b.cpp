#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::vector<int> a(100);
  int q;
  std::cin >> q;
  while (q--) {
    int t;
    std::cin >> t;
    if (t == 1) {
      int x;
      std::cin >> x;
      a.push_back(x);
    } else {
      std::cout << a.back() << "\n";
      a.pop_back();
    }
  }
}

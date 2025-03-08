#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

constexpr int inf = 1e9;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<int> v2r(n);
  std::iota(v2r.begin(), v2r.end(), 0);
  std::vector<int> r2v(n);
  std::iota(r2v.begin(), r2v.end(), 0);

  std::vector<int> p(n);
  std::iota(p.begin(), p.end(), 0);
  int q;
  std::cin >> q;
  while (q--) {
    int t;
    std::cin >> t;
    if (t == 1) {
      int a, b;
      std::cin >> a >> b, a--, b--;
      p[a] = r2v[b];
    } else if (t == 2) {
      int a, b;
      std::cin >> a >> b, a--, b--;
      int va = r2v[a], vb = r2v[b];
      r2v[a] = vb, r2v[b] = va;
      v2r[va] = b, v2r[vb] = a;
    } else {
      int a;
      std::cin >> a, a--;
      std::cout << v2r[p[a]] + 1 << "\n";
    }
  }
}

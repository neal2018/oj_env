#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    auto ask = [&](int i, int j) {
      cout << "? " << i + 1 << " " << j + 1 << endl;
      int res;
      cin >> res;
      return res;
    };
    auto answer = [&](int i, int j) { cout << "! " << i + 1 << " " << j + 1 << endl; };
    int a1 = ask(0, 0);
    int a2 = ask(n - 1, m - 1);
    int r1 = min(n - 1, a1), r2 = max(0, n - (a2 + 1));
    int c1 = min(m - 1, a1), c2 = max(0, m - (a2 + 1));
    if (r1 != r2 && c1 != c2) {
      if (ask(r1, c2) == 0) {
        answer(r1, c2);
      } else {
        answer(r2, c1);
      }
    } else if (r1 == r2 && c1 != c2) {
      int dist = ask(r1, 0);
      answer(r1, dist);
    } else if (r1 != r2 && c1 == c2) {
      int dist = ask(0, c1);
      answer(dist, c1);
    } else {
      answer(r1, c1);
    }
  }
}

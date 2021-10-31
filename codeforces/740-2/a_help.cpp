#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define LOCAL

int main() {
#ifdef LOCAL
  ifstream cin("/Users/neallai/Projects/oj_env/input.txt");
  ofstream cout("/Users/neallai/Projects/oj_env/output.txt");
#endif  // LOCAL
  int T, n;
  cin >> T;
  while (T--) {
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    int i = 0;
    while (true) {
      if (is_sorted(a.begin(), a.end())) {
        cout << i << endl;
        break;
      }
      i++;
      int start = (i % 2 == 0);
      for (; start < n - 1; start += 2) {
        if (a[start] > a[start + 1]) {
          swap(a[start], a[start + 1]);
        }
      }
      // for (auto&x:a)cout<<x<<" ";cout<<endl;
    }
  }
}

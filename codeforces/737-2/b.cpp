#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
  int n, t, k;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
      mp[a[i]] = i;
    }
    sort(a.begin(), a.end());

    int cnt = 0;
    int pre = -10;
    for (int i = 0; i < n; i++) {
      if (mp[a[i]] != pre + 1) {
        cnt++;
      }
      pre = mp[a[i]];  // index in a
    }
    if (cnt <= k && k <= n) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
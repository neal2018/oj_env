#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const double PI = acos(-1);

class NonbinarySearch {
public:
  int search(int n) {
    ll l = 1, r = n, res = 1;
    while (l < r) {
      res++;
      ll mid1 = (l + r) / 2, mid2 = (l + r + 1) / 2;
      ll pos1 = mid1 - 1, pos2 = mid2 + 1;
      if ((l <= pos1 && pos1 <= r) || (l <= pos2 && pos2 <= r)) {
        ll len1 = pos1 - l, is_left1 = 1;
        ll is_good1 = (l <= pos1 && pos1 <= r);
        if (r - pos1 > len1) {
          len1 = r - pos1, is_left1 = 0;
        }
        ll len2 = pos2 - l, is_left2 = 1;
        ll is_good2 = (l <= pos2 && pos2 <= r);
        if (r - pos2 > len1) {
          len2 = r - pos2, is_left2 = 0;
        }
        if (len1 * is_good1 > len2 * is_good2) {
          if (is_left1) {
            r = pos1 - 1;
          } else {
            l = pos1 + 1;
          }
        } else {
          if (is_left2) {
            r = pos2 - 1;
          } else {
            l = pos2 + 1;
          }
        }
      } else {
        ll len1 = mid1 - l, is_left1 = 1;
        ll is_good1 = (l <= mid1 && mid1 <= r);
        if (r - mid1 > len1) {
          len1 = r - mid1, is_left1 = 0;
        }
        ll len2 = mid2 - l, is_left2 = 1;
        ll is_good2 = (l <= mid2 && mid2 <= r);
        if (r - mid2 > len1) {
          len2 = r - mid2, is_left2 = 0;
        }
        if (len1 * is_good1 > len2 * is_good2) {
          if (is_left1) {
            r = mid1 - 1;
          } else {
            l = mid1 + 1;
          }
        } else {
          if (is_left2) {
            r = mid2 - 1;
          } else {
            l = mid2 + 1;
          }
        }
      }
    }
    return res;
  }
};

int main() {
  auto a = NonbinarySearch();
  for (int i = 2; i < 100000; i++) {
    auto t = a.search(i);
    int n = i;
    int ans = 0;
    {
      n = i;
      while (n > 2) {
        n = n / 2 + 1;
        ans++;
      }
      ans += n;
      // cout << ans << "\n";
    }
    if (t != ans) {
      cout << i << "\n";
      cout << t << " "<<ans<<"\n";
      exit(0);
    }
  }
  // cout << t << "\n";
}

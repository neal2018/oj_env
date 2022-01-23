#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<int> a(m);
  for (auto& x : a) cin >> x;
  vector<string> bad, good;
  int pre = a[0], cur = a[0];
  if (pre != 1) {
    if (2 == pre) {
      good.push_back(to_string(1));
    } else {
      good.push_back(to_string(1) + '-' + to_string(pre - 1));
    }
  }
  for (int i = 1; i < m; i++) {
    if (a[i] == a[i - 1] + 1) {
      continue;
    } else {
      // cout << pre << " " << a[i - 1] << " " << a[i] << "\n";
      if (a[i - 1] == pre) {
        bad.push_back(to_string(a[i - 1]));
      } else {
        bad.push_back(to_string(pre) + '-' + to_string(a[i - 1]));
      }
      if (a[i - 1] + 1 == a[i] - 1) {
        good.push_back(to_string(a[i] - 1));
      } else {
        good.push_back(to_string(a[i - 1] + 1) + '-' + to_string(a[i] - 1));
      }
      pre = a[i];
    }
  }
  if (a[m - 1] == pre) {
    bad.push_back(to_string(a[m - 1]));
  } else {
    bad.push_back(to_string(pre) + '-' + to_string(a[m - 1]));
  }
  if (a[m - 1] != n) {
    if (a[m - 1] + 1 == n) {
      good.push_back(to_string(n));
    } else {
      good.push_back(to_string(a[m - 1] + 1) + '-' + to_string(n));
    }
  }
  cout << "Errors: ";
  for (int i = 0; i < bad.size(); i++) {
    if (i == 0) {
    } else if (i == (int)bad.size() - 1) {
      cout << " and ";
    } else {
      cout << ", ";
    }
    cout << bad[i];
  }
  cout << "\n";
  cout << "Correct: ";
  for (int i = 0; i < good.size(); i++) {
    if (i == 0) {
    } else if (i == (int)good.size() - 1) {
      cout << " and ";
    } else {
      cout << ", ";
    }
    cout << good[i];
  }
  cout << "\n";
}
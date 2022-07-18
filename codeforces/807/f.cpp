#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  auto ask = [&](const string& s) {
    cout << s << endl;
    int res;
    cin >> res;
    if (res == n || res == -1) exit(0);
    return res;
  };

  string all_T(n, 'T'), res(n, '?');
  int cnt_T = ask(all_T);

  string all_TF(n, 'T');
  for (int i = 1; i < n; i += 2) all_TF[i] = 'F';
  int cnt_TF = ask(all_TF);

  int l = 0, r = n - 1;
  while (r >= l) {
    if (r == l) {
      string s(all_T);
      s[l] = 'F';
      int k = ask(s);

      if (k > cnt_T) {
        res[l] = 'F';
      } else {
        res[l] = 'T';
      }
      l++, r--;
    } else {
      string s(all_T);
      s[l] = 'F';
      s[l + 1] = 'F';
      int k = ask(s) - cnt_T;

      if (k == 2) {
        res[l] = 'F';
        res[l + 1] = 'F';
        l += 2;
      } else if (k == -2) {
        res[l] = 'T';
        res[l + 1] = 'T';
        l += 2;
      } else {
        if (r == l + 1) {
          s = all_T;
          s[l] = 'F';
          k = ask(s);
          if (k > cnt_T) {
            res[l] = 'F';
            res[l + 1] = 'T';
          } else {
            res[l] = 'T';
            res[l + 1] = 'F';
          }
          l += 2;
        } else {
          s = all_TF;
          s[l] = 'F';
          s[l + 1] = 'T';
          s[r] = s[r] ^ 'T' ^ 'F';
          k = ask(s) - cnt_TF;
          if (k == 3) {
            res[l] = 'F';
            res[l + 1] = 'T';
            res[r] = s[r];
          } else if (k == 1) {
            res[l] = 'F';
            res[l + 1] = 'T';
            res[r] = all_TF[r];
          } else if (k == -1) {
            res[l] = 'T';
            res[l + 1] = 'F';
            res[r] = s[r];
          } else {
            res[l] = 'T';
            res[l + 1] = 'F';
            res[r] = all_TF[r];
          }
          l += 2, r--;
        }
      }
    }
  }
  ask(res);
}

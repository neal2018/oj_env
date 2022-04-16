#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

const double PI = acos(-1);

class SingleOrDouble {
public:
  double probAlice(int N, int D, int A, int B) {
    auto mul = [&](const vector<double>& aa, const vector<double>& bb) {
      int n = (int)aa.size(), m = (int)bb.size(), bit = 1;
      while ((1 << bit) < n + m - 1) bit++;
      int len = 1 << bit;
      vector<complex<double>> a(len), b(len);
      vector<int> rev(len);
      for (int i = 0; i < n; i++) a[i].real(aa[i]);
      for (int i = 0; i < m; i++) b[i].real(bb[i]);
      for (int i = 0; i < len; i++) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (bit - 1));
      auto fft = [&](vector<complex<double>>& p, int inv) {
        for (int i = 0; i < len; i++)
          if (i < rev[i]) swap(p[i], p[rev[i]]);
        for (int mid = 1; mid < len; mid *= 2) {
          auto w1 = complex<double>(cos(PI / mid), (inv ? -1 : 1) * sin(PI / mid));
          for (int i = 0; i < len; i += mid * 2) {
            auto wk = complex<double>(1, 0);
            for (int j = 0; j < mid; j++, wk = wk * w1) {
              auto x = p[i + j], y = wk * p[i + j + mid];
              p[i + j] = x + y, p[i + j + mid] = x - y;
            }
          }
        }
        if (inv == 1) {
          for (int i = 0; i < len; i++) p[i].real(p[i].real() / len);
        }
      };
      fft(a, 0), fft(b, 0);
      for (int i = 0; i < len; i++) a[i] = a[i] * b[i];
      fft(a, 1);
      a.resize(n + m - 1);
      vector<double> res(n + m - 1);
      for (int i = 0; i < n + m - 1; i++) res[i] = a[i].real();
      return res;
    };
    auto x = mul({1, 1}, {1, 1});
    vector<double> single(D, 1.0 / D), p(D, 1.0 / D);
    for (int i = 1; i < N; i++) {
      p = mul(p, single);
    }
    double pa = p[A - N], pb = p[B - N];
    double res = (pa + pa * pb) / (pa + pa * pb + pb * pb);
    return res;
  }
};

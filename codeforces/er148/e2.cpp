/**
 *    author:  Penguin07
 *    created: [2023-05-13 10:00:21]
 **/
#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <cstring>
#include <iostream>
#include <numeric>
#include <random>
#include <type_traits>
#include <vector>
#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_large"

namespace std {
template <typename _Size>
inline _Size __lg(_Size __n) {
  _Size __k;
  for (__k = 0; __n != 0; __n >>= 1) ++__k;
  return __k - 1;
}

static struct FastInput {
  static constexpr int BUF_SIZE = 1 << 20;
  char buf[BUF_SIZE];
  size_t chars_read = 0;
  size_t buf_pos = 0;
  FILE* in = stdin;
  char cur = 0;

  inline char get_char() {
    if (buf_pos >= chars_read) {
      chars_read = fread(buf, 1, BUF_SIZE, in);
      buf_pos = 0;
      buf[0] = (chars_read == 0 ? -1 : buf[0]);
    }
    return cur = buf[buf_pos++];
    // return cur = getchar_unlocked();
  }

  inline void tie(int) {}

  inline explicit operator bool() { return cur != -1; }

  inline static bool is_blank(char c) { return c <= ' '; }

  inline bool skip_blanks() {
    while (is_blank(cur) && cur != -1) {
      get_char();
    }
    return cur != -1;
  }

  inline FastInput& operator>>(char& c) {
    skip_blanks();
    c = cur;
    return *this;
  }

  inline FastInput& operator>>(std::string& s) {
    if (skip_blanks()) {
      s.clear();
      do {
        s += cur;
      } while (!is_blank(get_char()));
    }
    return *this;
  }

  template <class T>
  inline FastInput& read_integer(T& n) {
    // unsafe, doesn't check that characters are actually digits
    n = 0;
    if (skip_blanks()) {
      int sign = +1;
      if (cur == '-') {
        sign = -1;
        get_char();
      }
      do {
        n += n + (n << 3) + cur - '0';
      } while (!is_blank(get_char()));
      n *= sign;
    }
    return *this;
  }

  template <class T>
  inline typename std::enable_if<std::is_integral<T>::value, FastInput&>::type operator>>(T& n) {
    return read_integer(n);
  }

  inline FastInput& operator>>(__int128& n) { return read_integer(n); }

  template <class T>
  inline typename std::enable_if<std::is_floating_point<T>::value, FastInput&>::type operator>>(
      T& n) {
    n = 0;
    if (skip_blanks()) {
      std::string s;
      (*this) >> s;
      sscanf(s.c_str(), "%lf", &n);
    }
    return *this;
  }
} fast_input;

#define istream FastInput
#define cin fast_input

static struct FastOutput {
  static constexpr int BUF_SIZE = 1 << 20;
  char buf[BUF_SIZE];
  size_t buf_pos = 0;
  static constexpr int TMP_SIZE = 1 << 20;
  char tmp[TMP_SIZE];
  FILE* out = stdout;

  inline void put_char(char c) {
    buf[buf_pos++] = c;
    if (buf_pos == BUF_SIZE) {
      fwrite(buf, 1, buf_pos, out);
      buf_pos = 0;
    }
    // putchar_unlocked(c);
  }

  ~FastOutput() { fwrite(buf, 1, buf_pos, out); }

  inline FastOutput& operator<<(char c) {
    put_char(c);
    return *this;
  }

  inline FastOutput& operator<<(const char* s) {
    while (*s) {
      put_char(*s++);
    }
    return *this;
  }

  inline FastOutput& operator<<(const std::string& s) {
    for (int i = 0; i < (int)s.size(); i++) {
      put_char(s[i]);
    }
    return *this;
  }

  template <class T>
  inline char* integer_to_string(T n) {
    // beware of TMP_SIZE
    char* p = tmp + TMP_SIZE - 1;
    if (n == 0) {
      *--p = '0';
    } else {
      bool is_negative = false;
      if (n < 0) {
        is_negative = true;
        n = -n;
      }
      while (n > 0) {
        *--p = (char)('0' + n % 10);
        n /= 10;
      }
      if (is_negative) {
        *--p = '-';
      }
    }
    return p;
  }

  template <class T>
  inline typename std::enable_if<std::is_integral<T>::value, char*>::type stringify(T n) {
    return integer_to_string(n);
  }

  inline char* stringify(__int128 n) { return integer_to_string(n); }

  template <class T>
  inline typename std::enable_if<std::is_floating_point<T>::value, char*>::type stringify(T n) {
    sprintf(tmp, "%.17f", n);
    return tmp;
  }

  template <class T>
  inline FastOutput& operator<<(const T& n) {
    auto p = stringify(n);
    for (; *p != 0; p++) {
      put_char(*p);
    }
    return *this;
  }
} fast_output;

#define ostream FastOutput
#define cout fast_output

}  // namespace std

namespace felix {

namespace internal {

#ifndef _MSC_VER
template <class T>
using is_signed_int128 = typename std::conditional<std::is_same<T, __int128_t>::value ||
                                                       std::is_same<T, __int128>::value,
                                                   std::true_type, std::false_type>::type;
template <class T>
using is_unsigned_int128 = typename std::conditional<std::is_same<T, __uint128_t>::value ||
                                                         std::is_same<T, unsigned __int128>::value,
                                                     std::true_type, std::false_type>::type;
template <class T>
using make_unsigned_int128 =
    typename std::conditional<std::is_same<T, __int128_t>::value, __uint128_t, unsigned __int128>;
template <class T>
using is_integral =
    typename std::conditional<std::is_integral<T>::value || is_signed_int128<T>::value ||
                                  is_unsigned_int128<T>::value,
                              std::true_type, std::false_type>::type;
template <class T>
using is_signed_int =
    typename std::conditional<(is_integral<T>::value && std::is_signed<T>::value) ||
                                  is_signed_int128<T>::value,
                              std::true_type, std::false_type>::type;
template <class T>
using is_unsigned_int =
    typename std::conditional<(is_integral<T>::value && std::is_unsigned<T>::value) ||
                                  is_unsigned_int128<T>::value,
                              std::true_type, std::false_type>::type;
template <class T>
using to_unsigned = typename std::conditional<
    is_signed_int128<T>::value, make_unsigned_int128<T>,
    typename std::conditional<std::is_signed<T>::value, std::make_unsigned<T>,
                              std::common_type<T>>::type>::type;
#else
template <class T>
using is_integral = typename std::is_integral<T>;
template <class T>
using is_signed_int = typename std::conditional<is_integral<T>::value && std::is_signed<T>::value,
                                                std::true_type, std::false_type>::type;
template <class T>
using is_unsigned_int =
    typename std::conditional<is_integral<T>::value && std::is_unsigned<T>::value, std::true_type,
                              std::false_type>::type;
template <class T>
using to_unsigned = typename std::conditional<is_signed_int<T>::value, std::make_unsigned<T>,
                                              std::common_type<T>>::type;
#endif

template <class T>
using is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;
template <class T>
using is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;
template <class T>
using to_unsigned_t = typename to_unsigned<T>::type;

}  // namespace internal

}  // namespace felix

namespace felix {

namespace internal {

template <class T>
constexpr T safe_mod(T x, T m) {
  x %= m;
  if (x < 0) {
    x += m;
  }
  return x;
}

}  // namespace internal

}  // namespace felix

namespace felix {

namespace internal {

template <class T>
constexpr std::pair<T, T> inv_gcd(T a, T b) {
  a = safe_mod(a, b);
  if (a == 0) {
    return {b, 0};
  }
  T s = b, t = a;
  T m0 = 0, m1 = 1;
  while (t) {
    T u = s / t;
    s -= t * u;
    m0 -= m1 * u;
    auto tmp = s;
    s = t;
    t = tmp;
    tmp = m0;
    m0 = m1;
    m1 = tmp;
  }
  if (m0 < 0) {
    m0 += b / s;
  }
  return {s, m0};
}

}  // namespace internal

}  // namespace felix

namespace felix {

template <int id>
struct modint {
public:
  static constexpr int mod() { return (id > 0 ? id : md); }

  static constexpr void set_mod(int m) {
    if (id > 0 || md == m) {
      return;
    }
    md = m;
    facts.resize(1);
    inv_facts.resize(1);
    invs.resize(1);
  }

  static constexpr void prepare(int n) {
    int sz = (int)facts.size();
    if (sz == mod()) {
      return;
    }
    n = 1 << std::__lg(2 * n - 1);
    if (n < sz) {
      return;
    }
    if (n < (sz - 1) * 2) {
      n = std::min((sz - 1) * 2, mod() - 1);
    }
    facts.resize(n + 1);
    inv_facts.resize(n + 1);
    invs.resize(n + 1);
    for (int i = sz; i <= n; i++) {
      facts[i] = facts[i - 1] * i;
    }
    auto eg = internal::inv_gcd(facts.back()(), mod());
    assert(eg.first == 1);
    inv_facts[n] = eg.second;
    for (int i = n - 1; i >= sz; i--) {
      inv_facts[i] = inv_facts[i + 1] * (i + 1);
    }
    for (int i = n; i >= sz; i--) {
      invs[i] = inv_facts[i] * facts[i - 1];
    }
  }

  constexpr modint() : value(0) {}
  template <class T, internal::is_signed_int_t<T>* = nullptr>
  constexpr modint(T v) : value(v >= 0 ? v % mod() : v % mod() + mod()) {}
  template <class T, internal::is_unsigned_int_t<T>* = nullptr>
  constexpr modint(T v) : value(v % mod()) {}

  constexpr int operator()() const { return value; }
  template <class T>
  explicit constexpr operator T() const {
    return static_cast<T>(value);
  }

  constexpr modint inv() const {
    if (id > 0 && value < std::min(umod() >> 1, 1U << 18)) {
      prepare(value);
      return invs[value];
    } else {
      auto eg = internal::inv_gcd(value, umod());
      assert(eg.first == 1);
      return eg.second;
    }
  }

  constexpr modint fact() const {
    prepare(value);
    return facts[value];
  }

  constexpr modint inv_fact() const {
    prepare(value);
    return inv_facts[value];
  }

  constexpr modint& operator+=(const modint& rhs) & {
    value += rhs.value;
    if (value >= umod()) {
      value -= umod();
    }
    return *this;
  }

  constexpr modint& operator-=(const modint& rhs) & {
    value -= rhs.value;
    if (value >= umod()) {
      value += umod();
    }
    return *this;
  }

  constexpr modint& operator*=(const modint& rhs) & {
    unsigned long long z = value;
    z *= rhs.value;
    value = (unsigned int)(z % umod());
    return *this;
  }

  constexpr modint& operator/=(const modint& rhs) & { return *this *= rhs.inv(); }

  friend constexpr modint operator+(modint lhs, modint rhs) { return lhs += rhs; }
  friend constexpr modint operator-(modint lhs, modint rhs) { return lhs -= rhs; }
  friend constexpr modint operator*(modint lhs, modint rhs) { return lhs *= rhs; }
  friend constexpr modint operator/(modint lhs, modint rhs) { return lhs /= rhs; }

  constexpr modint operator+() const { return *this; }
  constexpr modint operator-() const { return modint() - *this; }
  constexpr bool operator==(const modint& rhs) const { return value == rhs.value; }
  constexpr bool operator!=(const modint& rhs) const { return value != rhs.value; }

  constexpr modint pow(unsigned long long p) const {
    modint a(*this), res(1);
    while (p) {
      if (p & 1) {
        res *= a;
      }
      a *= a;
      p >>= 1;
    }
    return res;
  }

  constexpr bool has_sqrt() const {
    if (mod() == 2 || value == 0) {
      return true;
    }
    if (pow((mod() - 1) / 2) != 1) {
      return false;
    }
    return true;
  }

  constexpr modint sqrt() const {
    if (mod() == 2 || value < 2) {
      return *this;
    }
    assert(pow((mod() - 1) / 2) == 1);
    modint b = 1;
    while (b.pow((mod() - 1) >> 1)() == 1) {
      b += 1;
    }
    long long m = mod() - 1, e = __builtin_ctz(m);
    m >>= e;
    modint x = modint(value).pow((m - 1) >> 1);
    modint y = modint(value) * x * x;
    x *= value;
    modint z = b.pow(m);
    while (y() != 1) {
      long long j = 0;
      modint t = y;
      while (t() != 1) {
        t *= t;
        j++;
      }
      z = z.pow(1LL << (e - j - 1));
      x *= z;
      z *= z;
      y *= z;
      e = j;
    }
    return x;
  }

  friend constexpr std::istream& operator>>(std::istream& in, modint& num) {
    long long x;
    in >> x;
    num = modint<id>(x);
    return in;
  }

  friend constexpr std::ostream& operator<<(std::ostream& out, const modint& num) {
    return out << num();
  }

private:
  unsigned int value;
  static int md;
  static std::vector<modint> facts, inv_facts, invs;

  static constexpr unsigned int umod() { return mod(); }
};

template <int id>
int modint<id>::md = 998244353;
template <int id>
std::vector<modint<id>> modint<id>::facts = {1};
template <int id>
std::vector<modint<id>> modint<id>::inv_facts = {1};
template <int id>
std::vector<modint<id>> modint<id>::invs = {0};

using modint998244353 = modint<998244353>;
using modint1000000007 = modint<1000000007>;

namespace internal {

template <class T>
struct is_modint : public std::false_type {};
template <int id>
struct is_modint<modint<id>> : public std::true_type {};

template <class T, class ENABLE = void>
struct is_static_modint : public std::false_type {};
template <int id>
struct is_static_modint<modint<id>, std::enable_if_t<(id > 0)>> : public std::true_type {};
template <class T>
using is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;

template <class T, class ENABLE = void>
struct is_dynamic_modint : public std::false_type {};
template <int id>
struct is_dynamic_modint<modint<id>, std::enable_if_t<(id <= 0)>> : public std::true_type {};
template <class T>
using is_dynamic_modint_t = std::enable_if_t<is_dynamic_modint<T>::value>;

}  // namespace internal

}  // namespace felix

namespace felix {

namespace internal {

constexpr int primitive_root_constexpr(int m) {
  if (m == 998244353) return 3;
  if (m == 167772161) return 3;
  if (m == 469762049) return 3;
  if (m == 754974721) return 11;
  if (m == 880803841) return 26;
  if (m == 1045430273) return 3;
  if (m == 1051721729) return 6;
  if (m == 1053818881) return 7;
  int divs[20] = {};
  divs[0] = 2;
  int cnt = 1;
  int x = (m - 1) / 2;
  x >>= __builtin_ctz(x);
  for (int i = 3; 1LL * i * i <= x; i += 2) {
    if (x % i == 0) {
      divs[cnt++] = i;
      while (x % i == 0) {
        x /= i;
      }
    }
  }
  if (x > 1) {
    divs[cnt++] = x;
  }
  for (int g = 2;; g++) {
    bool ok = true;
    for (int i = 0; i < cnt; i++) {
      unsigned long long y = safe_mod(g, m), r = 1;
      long long n = (m - 1) / divs[i];
      while (n) {
        if (n & 1) {
          r = r * y % m;
        }
        y = y * y % m;
        n >>= 1;
      }
      if (r == 1) {
        ok = false;
        break;
      }
    }
    if (ok) {
      return g;
    }
  }
  assert(false);
}

template <int mod>
struct NTT_prepare {
  using mint = modint<mod>;

  static constexpr int primitive_root = primitive_root_constexpr(mod);
  static constexpr int level = __builtin_ctz(mod - 1);

  std::array<mint, level + 1> root, iroot;
  std::array<mint, std::max(0, level - 2 + 1)> rate2, irate2;
  std::array<mint, std::max(0, level - 3 + 1)> rate3, irate3;

  constexpr NTT_prepare() {
    root[level] = mint(primitive_root).pow((mod - 1) >> level);
    iroot[level] = root[level].inv();
    for (int i = level - 1; i >= 0; i--) {
      root[i] = root[i + 1] * root[i + 1];
      iroot[i] = iroot[i + 1] * iroot[i + 1];
    }
    {
      mint prod = 1, iprod = 1;
      for (int i = 0; i <= level - 2; i++) {
        rate2[i] = root[i + 2] * prod;
        irate2[i] = iroot[i + 2] * iprod;
        prod *= iroot[i + 2];
        iprod *= root[i + 2];
      }
    }
    {
      mint prod = 1, iprod = 1;
      for (int i = 0; i <= level - 3; i++) {
        rate3[i] = root[i + 3] * prod;
        irate3[i] = iroot[i + 3] * iprod;
        prod *= iroot[i + 3];
        iprod *= root[i + 3];
      }
    }
  }
};

template <int mod>
struct NTT {
  using mint = modint<mod>;

  static NTT_prepare<mod> info;

  static void NTT4(std::vector<mint>& a) {
    int n = (int)a.size();
    int h = __builtin_ctz(n);
    int len = 0;
    while (len < h) {
      if (h - len == 1) {
        int p = 1 << (h - len - 1);
        mint rot = 1;
        for (int s = 0; s < (1 << len); s++) {
          int offset = s << (h - len);
          for (int i = 0; i < p; i++) {
            auto l = a[i + offset];
            auto r = a[i + offset + p] * rot;
            a[i + offset] = l + r;
            a[i + offset + p] = l - r;
          }
          if (s + 1 != (1 << len)) {
            rot *= info.rate2[__builtin_ctz(~(unsigned int)s)];
          }
        }
        len++;
      } else {
        int p = 1 << (h - len - 2);
        mint rot = 1, imag = info.root[2];
        for (int s = 0; s < (1 << len); s++) {
          mint rot2 = rot * rot;
          mint rot3 = rot2 * rot;
          int offset = s << (h - len);
          for (int i = 0; i < p; i++) {
            auto mod2 = 1ULL * mod * mod;
            auto a0 = 1ULL * a[i + offset]();
            auto a1 = 1ULL * a[i + offset + p]() * rot();
            auto a2 = 1ULL * a[i + offset + 2 * p]() * rot2();
            auto a3 = 1ULL * a[i + offset + 3 * p]() * rot3();
            auto a1na3imag = 1ULL * mint(a1 + mod2 - a3)() * imag();
            auto na2 = mod2 - a2;
            a[i + offset] = a0 + a2 + a1 + a3;
            a[i + offset + 1 * p] = a0 + a2 + (2 * mod2 - (a1 + a3));
            a[i + offset + 2 * p] = a0 + na2 + a1na3imag;
            a[i + offset + 3 * p] = a0 + na2 + (mod2 - a1na3imag);
          }
          if (s + 1 != (1 << len)) rot *= info.rate3[__builtin_ctz(~(unsigned int)s)];
        }
        len += 2;
      }
    }
  }

  static void iNTT4(std::vector<mint>& a) {
    int n = (int)a.size();
    int h = __builtin_ctz(n);
    int len = h;
    while (len) {
      if (len == 1) {
        int p = 1 << (h - len);
        mint irot = 1;
        for (int s = 0; s < (1 << (len - 1)); s++) {
          int offset = s << (h - len + 1);
          for (int i = 0; i < p; i++) {
            auto l = a[i + offset];
            auto r = a[i + offset + p];
            a[i + offset] = l + r;
            a[i + offset + p] = 1ULL * (mod + l() - r()) * irot();
          }
          if (s + 1 != (1 << (len - 1))) {
            irot *= info.irate2[__builtin_ctz(~(unsigned int)s)];
          }
        }
        len--;
      } else {
        int p = 1 << (h - len);
        mint irot = 1, iimag = info.iroot[2];
        for (int s = 0; s < (1 << (len - 2)); s++) {
          mint irot2 = irot * irot;
          mint irot3 = irot2 * irot;
          int offset = s << (h - len + 2);
          for (int i = 0; i < p; i++) {
            auto a0 = 1ULL * a[i + offset + 0 * p]();
            auto a1 = 1ULL * a[i + offset + 1 * p]();
            auto a2 = 1ULL * a[i + offset + 2 * p]();
            auto a3 = 1ULL * a[i + offset + 3 * p]();
            auto a2na3iimag = 1ULL * mint((mod + a2 - a3) * iimag())();
            a[i + offset] = a0 + a1 + a2 + a3;
            a[i + offset + 1 * p] = (a0 + (mod - a1) + a2na3iimag) * irot();
            a[i + offset + 2 * p] = (a0 + a1 + (mod - a2) + (mod - a3)) * irot2();
            a[i + offset + 3 * p] = (a0 + (mod - a1) + (mod - a2na3iimag)) * irot3();
          }
          if (s + 1 != (1 << (len - 2))) {
            irot *= info.irate3[__builtin_ctz(~(unsigned int)s)];
          }
        }
        len -= 2;
      }
    }
  }
};

template <int mod>
NTT_prepare<mod> NTT<mod>::info;

template <class mint, internal::is_static_modint_t<mint>* = nullptr>
std::vector<mint> convolution_naive(const std::vector<mint>& a, const std::vector<mint>& b) {
  int n = (int)a.size(), m = (int)b.size();
  assert(n >= m);
  int len = n + m - 1;
  std::vector<mint> ans(len);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      ans[i + j] += a[i] * b[j];
    }
  }
  return ans;
}

template <class mint, internal::is_static_modint_t<mint>* = nullptr>
std::vector<mint> convolution_ntt(std::vector<mint> a, std::vector<mint> b) {
  int n = (int)a.size(), m = (int)b.size();
  int sz = 1 << std::__lg(2 * (n + m - 1) - 1);
  a.resize(sz);
  b.resize(sz);
  NTT<mint::mod()>::NTT4(a);
  NTT<mint::mod()>::NTT4(b);
  for (int i = 0; i < sz; i++) {
    a[i] *= b[i];
  }
  NTT<mint::mod()>::iNTT4(a);
  a.resize(n + m - 1);
  mint iz = mint(sz).inv();
  for (int i = 0; i < n + m - 1; i++) {
    a[i] *= iz;
  }
  return a;
}

}  // namespace internal

template <class mint, internal::is_static_modint_t<mint>* = nullptr>
std::vector<mint> convolution(const std::vector<mint>& a, const std::vector<mint>& b) {
  int n = (int)a.size(), m = (int)b.size();
  if (n == 0 || m == 0) {
    return {};
  }
  int sz = 1 << std::__lg(2 * (n + m - 1) - 1);
  assert((mint::mod() - 1) % sz == 0);
  if (std::min(n, m) < 128) {
    return n >= m ? internal::convolution_naive(a, b) : internal::convolution_naive(b, a);
  }
  return internal::convolution_ntt(a, b);
}

template <int mod, class T, std::enable_if_t<std::is_integral_v<T>>* = nullptr>
std::vector<T> convolution(const std::vector<T>& a, const std::vector<T>& b) {
  using mint = modint<mod>;

  int n = (int)a.size(), m = (int)b.size();
  if (n == 0 || m == 0) {
    return {};
  }
  int sz = 1 << std::__lg(2 * (n + m - 1) - 1);
  assert((mod - 1) % sz == 0);
  std::vector<mint> a2(a.begin(), a.end());
  std::vector<mint> b2(b.begin(), b.end());
  auto c2 = convolution(std::move(a2), std::move(b2));
  std::vector<T> c(n + m - 1);
  for (int i = 0; i < n + m - 1; i++) {
    c[i] = c2[i]();
  }
  return c;
}

template <class T>
std::vector<__uint128_t> convolution_u128(const std::vector<T>& a, const std::vector<T>& b) {
  static constexpr int m0 = 167772161;
  static constexpr int m1 = 469762049;
  static constexpr int m2 = 754974721;
  constexpr int r01 = modint<m1>(m0).inv()();
  constexpr int r02 = modint<m2>(m0).inv()();
  constexpr int r12 = modint<m2>(m1).inv()();
  constexpr int r02r12 = 1LL * (r02)*r12 % m2;
  constexpr long long w1 = m0;
  constexpr long long w2 = 1LL * m0 * m1;

  if (a.empty() || b.empty()) {
    return {};
  }
  std::vector<__uint128_t> ans(a.size() + b.size() - 1);
  if (std::min(a.size(), b.size()) < 128) {
    for (int i = 0; i < (int)a.size(); i++) {
      for (int j = 0; j < (int)b.size(); j++) {
        ans[i + j] += 1LL * a[i] * b[j];
      }
    }
    return ans;
  }
  auto c0 = convolution<m0>(a, b);
  auto c1 = convolution<m1>(a, b);
  auto c2 = convolution<m2>(a, b);
  int n = (int)c0.size();
  for (int i = 0; i < n; i++) {
    long long n1 = c1[i], n2 = c2[i];
    long long x = c0[i];
    long long y = (n1 + m1 - x) * r01 % m1;
    long long z = ((n2 + m2 - x) * r02r12 + (m2 - y) * r12) % m2;
    ans[i] = x + y * w1 + __uint128_t(z) * w2;
  }
  return ans;
}

template <class mint, internal::is_static_modint_t<mint>* = nullptr>
std::vector<mint> convolution_large(const std::vector<mint>& a, const std::vector<mint>& b) {
  static constexpr int max_size = (mint::mod() - 1) & -(mint::mod() - 1);
  static constexpr int half_size = max_size >> 1;
  static constexpr int inv_max_size = internal::inv_gcd(max_size, mint::mod()).second;

  const int n = (int)a.size(), m = (int)b.size();
  if (n == 0 || m == 0) {
    return {};
  }
  if (std::min(n, m) < 128 || n + m - 1 <= max_size) {
    return convolution(a, b);
  }
  const int dn = (n + half_size - 1) / half_size;
  const int dm = (m + half_size - 1) / half_size;
  std::vector<std::vector<mint>> as(dn), bs(dm);
  for (int i = 0; i < dn; ++i) {
    const int offset = half_size * i;
    as[i] = std::vector<mint>(a.begin() + offset, a.begin() + std::min(n, offset + half_size));
    as[i].resize(max_size);
    internal::NTT<mint::mod()>::NTT4(as[i]);
  }
  for (int j = 0; j < dm; ++j) {
    const int offset = half_size * j;
    bs[j] = std::vector<mint>(b.begin() + offset, b.begin() + std::min(m, offset + half_size));
    bs[j].resize(max_size);
    internal::NTT<mint::mod()>::NTT4(bs[j]);
  }
  std::vector<std::vector<mint>> cs(dn + dm - 1, std::vector<mint>(max_size));
  for (int i = 0; i < dn; ++i) {
    for (int j = 0; j < dm; ++j) {
      for (int k = 0; k < max_size; ++k) {
        cs[i + j][k] += as[i][k] * bs[j][k];
      }
    }
  }
  std::vector<mint> c(n + m - 1);
  for (int i = 0; i < dn + dm - 1; ++i) {
    internal::NTT<mint::mod()>::iNTT4(cs[i]);
    const int offset = half_size * i;
    const int jmax = std::min(n + m - 1 - offset, max_size);
    for (int j = 0; j < jmax; ++j) {
      c[offset + j] += cs[i][j] * inv_max_size;
    }
  }
  return c;
}

}  // namespace felix
using namespace std;
using namespace felix;

using mint = modint998244353;

struct Comb {
  vector<mint> f, rf;
  Comb(int n = 2) : f(n, 1), rf(n, 1) { fill(2, n); }
  void fill(int start, int n) {
    f.resize(n), rf.resize(n);
    for (int i = start; i < n; i++) f[i] = f[i - 1] * i;
    rf[n - 1] = 1 / f[n - 1];
    for (int i = n - 2; i >= start; i--) rf[i] = rf[i + 1] * (i + 1);
  }
  mint binom(int n, int r) {
    if (n < 0 || r < 0 || n < r) return 0;
    if (f.size() <= n) fill(int(f.size()), n + 1);
    return f[n] * rf[n - r] * rf[r];
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, a0, x, y, m, k;
  cin >> n >> a0 >> x >> y >> m >> k;
  vector<mint> a(n, a0);
  for (int i = 1; i < n; i++) {
    a[i] = (a[i - 1]() * x + y) % m;
  }
  Comb comb(n);
  vector<mint> c(n);
  for (int i = 0; i < n; i++) c[i] = comb.binom(i + 1, k);
  auto B = convolution_large(a, c);
  long long res = 0;
  for (int i = 0; i < n; i++) {
    res ^= B[i]() * (long long)(i + 1);
  }
  cout << res << "\n";
}

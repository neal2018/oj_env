#include <iostream>
using namespace std;

class Mother {
public:
  virtual void f() { cout << "Mother\n"; }
  int mother_data;
};

class Father {
public:
  virtual void f() { cout << "Father\n"; }
  int father_data;
};

class Child : public Mother, public Father {
public:
  virtual void f() { cout << "Child\n"; }
  int child_data;
};

int main() {
  auto p = new Child();
  p->f();
  auto q = static_cast<Mother*>(p);
  q->f();
  auto t = Child();
  static_cast<Mother>(t).f();
}

#include <stdlib.h>
#include <stdio.h>
void why_exec_me() { printf("hello world\n"); }
typedef void (*pfn)();
pfn aa[2] = {nullptr, &why_exec_me};

struct Base0
{
};
struct Base1 : virtual public Base0
{
};
struct Base2 : virtual public Base0
{
  virtual ~Base2() {}
  void func1() { b1 = &aa[0]; }
  pfn *b1;
};
struct Derive : public Base1, public Base2
{
  virtual void test() {}
  void *pad;
};
int main()
{
  void (Derive::*pfn1)() = &Base2::func1;
  Derive *p = new Derive[2];
  (p[0].*pfn1)(); 
  p[1].test();
  delete [] p;
  return 0;
}
//代码在msc上编译运行后，为什么会打印hello world
//欢迎c++程序员来挑战
//分析出原因，答对有100块奖励

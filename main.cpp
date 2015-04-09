
#include <iostream>


class Test {
public:

  Test() {
    a = 0;
    b = 0;
  }

  Test(int ia):
  a(ia) {}

  explicit Test(int ia, int ib):
  a(ia), b(ib) {}

  void show() const {
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
  }

private:

  int a, b;
};


void func01(const Test& test) {
  test.show();
}

void func02(Test& test) {
  test.show();
}

void func03(Test test) {
  test.show();
}

int main() {
  Test test00(10, 20);
  test00.show();

  // test01 = Test(10)
  Test test01 = 10;
  test01.show();

  // 本来ならエラーを吐いてほしいところだけど
  // 暗黙的にfunst01(Test(1))がされている
  func01(1);

  // 仮引数が参照の関数に数字いれるとエラー吐く
  // func02(2); // err

  // ただの数字とTest(2)の違いってパッケージされてるかどうか？
  // Testって型でパッケージしてれば通るっPOI
  // ここで引数に２をもつTestを作成して参照を渡してるのかな？
  func02(Test(2)); // ok

  // ここで引数に３をもつTestを作成してそれを関数の方でまた作成してるのかな
  func03(3); // ok

  
  // 結局なにがしたかったんだ。ω。


  // explisitを付ければ他のコンストラクタを暗黙的に呼ばれなくするものなのかな？
  // 付けてないコンストラクタは明示的になら呼び出せるPOI？

  // これは明示的にコンストラクタ呼んでるのか？
  Test test02; // ok
  test02.show();

  // もうよくわからん

  return 0;
}
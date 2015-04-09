
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

  // �{���Ȃ�G���[��f���Ăق����Ƃ��낾����
  // �ÖٓI��funst01(Test(1))������Ă���
  func01(1);

  // ���������Q�Ƃ̊֐��ɐ��������ƃG���[�f��
  // func02(2); // err

  // �����̐�����Test(2)�̈Ⴂ���ăp�b�P�[�W����Ă邩�ǂ����H
  // Test���Č^�Ńp�b�P�[�W���Ă�Βʂ��POI
  // �����ň����ɂQ������Test���쐬���ĎQ�Ƃ�n���Ă�̂��ȁH
  func02(Test(2)); // ok

  // �����ň����ɂR������Test���쐬���Ă�����֐��̕��ł܂��쐬���Ă�̂���
  func03(3); // ok

  
  // ���ǂȂɂ������������񂾁B�ցB


  // explisit��t����Α��̃R���X�g���N�^���ÖٓI�ɌĂ΂�Ȃ�������̂Ȃ̂��ȁH
  // �t���ĂȂ��R���X�g���N�^�͖����I�ɂȂ�Ăяo����POI�H

  // ����͖����I�ɃR���X�g���N�^�Ă�ł�̂��H
  Test test02; // ok
  test02.show();

  // �����悭�킩���

  return 0;
}
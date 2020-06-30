class Test {
  public:
      void deleteThis() {
          delete const_cast<Test*>(this);
      }
};

int main() {
    Test test;
    test.deleteThis();
}

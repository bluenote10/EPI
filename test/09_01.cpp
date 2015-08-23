#include <iostream>
#include <vector>

using namespace std;


template<typename T>
class Stack {

private:
  vector<T> data;
  T curMax;
  vector<T> previousMax;

public:

  Stack();
  ~Stack();
  
  void push(T x);
  T pop();
  T max() const;
};


template<typename T>
Stack<T>::Stack() {
  cout << "Constructor" << endl;
}
template<typename T>
Stack<T>::~Stack() {
  cout << "Destructor" << endl;
}


template<typename T>
void Stack<T>::push(T x) {
  if (x > curMax || data.size()==0) {
    curMax = x;
    previousMax.push_back(x);
  }
  data.push_back(x);
}

template<typename T>
T Stack<T>::pop() {
  if (data.size() <= 0) {
    // TODO
  }
  T x = data.back();
  data.pop_back();
  previousMax.pop_back();
  curMax = previousMax.back();
  return x;
}

template<typename T>
T Stack<T>::max() const {
  if (data.size() <= 0) {
    // TODO
    cout << "should error" << endl;
  }
  return curMax;
}

int main(int argc, char** args) {

  Stack<int> stack;

  stack.push(1);
  cout << stack.max() << endl;
  stack.push(2);
  cout << stack.max() << endl;
  stack.push(3);
  cout << stack.max() << endl;

  cout << stack.pop() << endl;
  cout << stack.max() << endl;
  cout << stack.pop() << endl;
  cout << stack.max() << endl;
  cout << stack.pop() << endl;
  cout << stack.max() << endl;
  
  return 0;
}

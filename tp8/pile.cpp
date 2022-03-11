#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>
#include <stack>

int main(int, char **) {
  std::stack<int> is;
  std::stack<double, std::vector<double> > ds;

  for (int i = 0; i < 5; ++i)
    is.push(i);

  while (!is.empty()) {
     std::cout << is.top() << std::endl;
     ds.push((double)is.top()*is.top());
     is.pop();
  }

  while(!ds.empty()) {
      std::cout << ds.top() << std::endl;
      ds.pop();
  }

  return 0;
}
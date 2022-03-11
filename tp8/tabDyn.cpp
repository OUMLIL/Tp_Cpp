#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>

int main (int, char **) {
  std::vector<int> v;  
  int input;
  
  while (std::cin >> input)
    v.push_back (input);  
 
  std::sort(v.begin(), v.end());

  std::copy (v.begin(), v.end(), 
    std::ostream_iterator<int> (std::cout, "\n"));

  for(auto const & c : v) {
    std::cout << c << std::endl;
  }
  
  return 0;
}
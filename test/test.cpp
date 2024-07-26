#include "../include/ArrayDec.h"
#include <utility>

//example usage of array

void debug(std::pair<int, int> p) {
  std::cout << "{" << p.first << ", " << p.second << "}";
}

int main(int argc, char* argv[]) {
  Array<std::pair<int, int>, 5> m ( std::pair<int,int>(1,2), std::pair<int,int>(3,4), std::pair<int,int>(5,6) );

  Array<int,5> m1 (1,2,3,4,5); 
  m1.printArray();

  m.printArray(&debug);

  auto [f, s] = m[0];
  std::cout << "f : " << f << " and s : " << s << std::endl;

  return 0;
}


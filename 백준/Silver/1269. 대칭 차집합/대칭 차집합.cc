#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int A_size, B_size;

  std::cin >> A_size >> B_size;
  std::vector<int> A(A_size);
  std::vector<int> B(B_size);

  for (auto &element : A)
    std::cin >> element;
  for (auto &element : B)
    std::cin >> element;

  std::sort(A.begin(), A.end()); 
  std::sort(B.begin(), B.end()); 
  std::vector<int> symmetric(A_size + B_size);
  auto iter = std::set_symmetric_difference(A.begin(), A.end(), B.begin(),
                                            B.end(), symmetric.begin());
  std::cout << iter - symmetric.begin() << '\n';

  return 0;
}
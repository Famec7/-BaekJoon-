#include <iostream>

int main() {
  int arr[5];
  int average = 0;

  for (int i = 0; i < 5; i++) {
    std::cin >> arr[i];
    average += arr[i];
  }

  average /= 5;

  for (int i = 0; i < 4; i++) {
    for (int j = i; j < 5; j++) {
      if (arr[i] < arr[j])
        std::swap(arr[i], arr[j]);
    }
  }

  std::cout << average << '\n' << arr[2] << '\n';

  return 0;
}
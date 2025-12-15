// 2. The array analyzer
#include <iostream>

int findMax(int *numbers, int size) {
  int max_num = numbers[0];
  for (int i = 1; i < size; i++) {
    if (numbers[i] > max_num) {
      max_num = numbers[i];
    }
  }
  return max_num;
}

int main() {
  int numbers[5] = {12, 5, 28, 4, 19};
  int size = 5;
  std::cout << findMax(numbers, size);

  return 0;
}

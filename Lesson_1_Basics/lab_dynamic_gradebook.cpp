// Lab: Dynamic Gradebook
#include <iostream>

double getAverage(int *arr, int size) {
  double sum = 0;
  for (int i = 0; i < size; i++) {
    sum += arr[i];
  }

  return sum / size;
}

int getHighest(int *arr, int size) {
  int highest = arr[0];
  for (int i = 1; i < size; i++) {
    if (highest < arr[i]) {
      highest = arr[i];
    }
  }
  return highest;
}

int getLowest(int *arr, int size) {

  int lowest = arr[0];
  for (int i = 1; i < size; i++) {
    if (lowest > arr[i]) {
      lowest = arr[i];
    }
  }
  return lowest;
}

int main() {
  int size;
  int *scores;
  std::cout << "How many scores do you want to enter? ";
  std::cin >> size;
  scores = new int[size];
  for (int i = 0; i < size; i++) {
    std::cout << "Please enter score #" << i + 1 << ": ";
    std::cin >> scores[i];
  }
  std::cout << "Average: " << getAverage(scores, size) << std::endl;
  std::cout << "Highest score: " << getHighest(scores, size) << std::endl;
  std::cout << "Lowest score: " << getLowest(scores, size) << std::endl;
  delete[] scores;
  return 0;
}

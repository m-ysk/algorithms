#include <stdlib.h>

#include <chrono>
#include <iostream>
using namespace std;

void primitive_bubble_sort(int n, int data[]) {
  bool swapped = true;

  while (swapped) {
    swapped = false;

    for (int i = 0; i < n - 1; ++i) {
      if (data[i] > data[i + 1]) {
        int tmp = data[i];
        data[i] = data[i + 1];
        data[i + 1] = tmp;
        swapped = true;
      }
    }
  }
}

void improved_bubble_sort(int n, int data[]) {
  for (int i = 0; i < n; ++i) {
    bool swapped = false;

    for (int j = 0; j < n - i - 1; ++j) {
      if (data[j] > data[j + 1]) {
        int tmp = data[j];
        data[j] = data[j + 1];
        data[j + 1] = tmp;
        swapped = true;
      }
    }

    if (!swapped) break;
  }
}

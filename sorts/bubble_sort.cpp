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

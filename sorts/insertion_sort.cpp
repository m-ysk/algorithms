#include <iostream>
using namespace std;

void insertion_sort(int n, int data[]) {
  // 2つ目の要素から順に見ていく
  for (int i = 1; i < n; ++i) {
    // 注目している要素が直前の要素より小さい場合、
    // 大小関係の逆転がなくなるまで前に送っていく
    for (int j = i; j >= 1; --j) {
      if (data[j] < data[j - 1]) {
        int tmp = data[j];
        data[j] = data[j - 1];
        data[j - 1] = tmp;
      } else {
        break;
      }
    }
  }
}

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

int main() {
  int N = 10;
  int data[] = {5, 3, 9, 6, 7, 1, 0, 8, 4, 2};

  insertion_sort(N, data);

  for (int i = 0; i < N; ++i) {
    cout << data[i];

    if (i == N - 1) {
      cout << endl;
    } else {
      cout << " ";
    }
  }
}

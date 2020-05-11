int select_pivot(int left, int right, int data[]) {
  if (right - left <= 0) return -1;

  int val1 = data[left];
  int val2;
  bool selected = false;
  for (int i = left + 1; i <= right; ++i) {
    if (data[i] != val1) {
      val2 = data[i];
      selected = true;
      break;
    }
  }
  if (!selected) return -1;

  if (val1 > val2) return val1;

  return val2;
}

void quick_sort(int left, int right, int data[]) {
  if (right - left <= 0) return;

  int pivot = select_pivot(left, right, data);
  if (pivot == -1) return;

  int i = left;
  int j = right;

  while (true) {
    while (data[i] < pivot) ++i;
    while (j >= left && pivot <= data[j]) --j;
    if (i >= j) break;
    int tmp = data[i];
    data[i] = data[j];
    data[j] = tmp;
    ++i;
    --j;
  }

  quick_sort(left, i - 1, data);
  quick_sort(i, right, data);
}

int select_pivot(int left, int right, int data[]) {
  int val1 = data[left];
  int val2;
  bool selected = false;

  for (int i = left; i < right; ++i) {
    int cur = data[i];
    if (cur != val1) {
      val2 = cur;
      selected = true;
      break;
    }
  }

  // return -1 when all elements are same value
  if (!selected) return -1;

  if (val1 > val2) {
    return val1;
  }

  return val2;
}

void quick_sort(int left, int right, int data[]) {
  if (right - left <= 1) return;

  int pivot = select_pivot(left, right, data);
  if (pivot == -1) return;

  int left_idx = left;
  int right_idx = right - 1;
  while (true) {
    int left_val;
    bool should_break = true;
    for (int i = left_idx; i <= right_idx; ++i) {
      int cur = data[i];
      if (cur >= pivot) {
        left_val = cur;
        left_idx = i;
        should_break = false;
        break;
      }

      if (i == right_idx) {
        left_idx = i;
      }
    }
    if (should_break) break;

    int right_val;
    should_break = true;
    for (int i = right_idx; i >= left_idx; --i) {
      int cur = data[i];
      if (cur < pivot) {
        right_val = cur;
        right_idx = i;
        should_break = false;
        break;
      }

      if (i == left_idx) {
        right_idx = i;
      }
    }
    if (should_break) break;

    data[right_idx] = left_val;
    data[left_idx] = right_val;
  }

  quick_sort(left, right_idx, data);
  quick_sort(right_idx, right, data);
}
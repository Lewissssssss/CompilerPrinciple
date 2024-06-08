// Input: 5 -123 -45 0 123 456 123
// Output: 3

int main() {
  int num, arr[10], key;
  int i, res;
  int left, right;
  num = getint();
  if (num > 10) {
    num = 10;
  }

  i = 0;
  while (i < num) {
    arr[i] = getint();
    i = i + 1;
  }

  key = getint();

  left = 0;
  right = num - 1;
  while (left < right) {
    i = (left + right) / 2;
    if (arr[i] == key) {
      putint(i);
      return 0;
    } else {
      if (arr[i] > key) {
        right = i - 1;
      } else {
        left = i + 1;
      }
    }
  }

  return 0;
}

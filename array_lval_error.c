// Semantic Error at Line 4: Array type is not assignable
int main() {
  int a[10][10],b[10];
  a[2] = b;
  putint(a[2][2]);
  return 0;
}

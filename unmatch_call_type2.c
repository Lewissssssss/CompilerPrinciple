// Semantic Error at Line 9: No matching function for call to 'f'

int f (int i, int a[]) {
    return i;
}

int main () {
    int t[10][10];
    int a = f(1,t);
    return 0;
}
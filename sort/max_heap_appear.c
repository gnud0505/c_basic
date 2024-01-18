#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define HLEFT(i) (((i) << 1) + 1)
#define HRIGHT(i) (((i) << 1) + 2)

typedef struct{
  char str[20];
  long num;
}StrNum;


// Hàm so sánh không phân biệt chữ hoa chữ thường
int caseInsensitiveCompare(const char *str1, const char *str2) {
    while (*str1 && *str2) {
        char c1 = tolower(*str1);
        char c2 = tolower(*str2);

        if (c1 != c2) {
            return c1 - c2;
        }

        str1++;
        str2++;
    }

    return *str1 - *str2;
}

void SWAP(StrNum *a, StrNum *b){
  StrNum _tmp;
  _tmp = *a;
  *a = *b;
  *b = _tmp;
}

void heap_shift_down(long i, long n, StrNum *strnum) {
  for (;;) {
    long lc = HLEFT(i), rc = HRIGHT(i), root = i;
    if (lc < n && strnum[root].num < strnum[lc].num  ) {
      root = lc;
    }
    if (rc < n && strnum[root].num < strnum[rc].num) {
      root = rc;
    }

    if (lc < n && strnum[root].num == strnum[lc].num && caseInsensitiveCompare(strnum[root].str, strnum[lc].str) > 0 ) {
      root = lc;
    }
    if (rc < n && strnum[root].num == strnum[rc].num && caseInsensitiveCompare(strnum[root].str, strnum[rc].str) > 0) {
      root = rc;
    }
    if (root == i) {
      break;
    }
    SWAP(&strnum[i], &strnum[root]);
    i = root;
  }
}
void heap_make(long n, StrNum *strnum) {
  for (long i = n / 2; i >= 0; --i) {
    heap_shift_down(i, n, strnum);
  }
}
int main() {
  long n;
  int k;
  scanf("%d %ld", &k, &n);
  StrNum *strnum = (StrNum *)malloc(n * sizeof(StrNum));
  for(long i=0; i<n; i++){
    scanf("%s %ld", strnum[i].str, &strnum[i].num);
  }
  heap_make(n, strnum);
  for(int i=0; i<k; i++){
    printf("%s %ld\n", strnum[0].str, strnum[0].num);
    SWAP(&strnum[0], &strnum[n - i -1]);
    heap_shift_down(0, n-i-1, strnum);
  }
  
  free(strnum);
}
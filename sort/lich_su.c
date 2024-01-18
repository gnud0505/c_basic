#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define HLEFT(i) (((i) << 1) + 1)
#define HRIGHT(i) (((i) << 1) + 2)

typedef struct{
  char date[11];
  char time[9];
  char loai[4];
  char nd[256];
}Web;



int compare(Web* a, Web* b) {
    // So sánh theo mức độ Loại thông báo giảm dần
    int typeComparison = strcmp(a->loai, b->loai);
    if (typeComparison != 0) {
      if (strcmp(a->loai, "WARN") == 0 && strcmp(b->loai, "ERRO") == 0) return 1;
      if (strcmp(a->loai, "INFO") == 0 && strcmp(b->loai, "ERRO") == 0) return 1;
      if (strcmp(a->loai, "INFO") == 0 && strcmp(b->loai, "WARN") == 0) return 1;
      return -1;
    }
    // So sánh theo thời điểm tăng dần
    int dateComparison = strcmp(a->date, b->date);
    if (dateComparison != 0) {
        return dateComparison;
    }

    // So sánh theo thời điểm tăng dần
    int timeComparison = strcmp(a->time, b->time);
    if (timeComparison != 0) {
        return timeComparison;
    }

    // So sánh theo nội dung tăng dần
    return strcmp(a->nd, b->nd);
}

void SWAP(Web *a, Web *b){
  Web _tmp;
  _tmp = *a;
  *a = *b;
  *b = _tmp;
}

void heap_shift_down(long i, long n, Web *web) {
  for (;;) {
    long lc = HLEFT(i), rc = HRIGHT(i), root = i;
    if (lc < n && compare(&web[root], &web[lc]) >0  ) {
      root = lc;
    }
    if (rc < n && compare(&web[root], &web[rc]) >0) {
      root = rc;
    }

    if (root == i) {
      break;
    }
    SWAP(&web[i], &web[root]);
    i = root;
  }
}
void heap_make(long n, Web *web) {
  for (long i = n / 2; i >= 0; --i) {
    heap_shift_down(i, n, web);
  }
}
int main() {
  Web *web = (Web *)malloc(10000 * sizeof(Web));
  int i=0;
  while (i < 10000) {
        scanf("%s", web[i].date);
        scanf("%s", web[i].time);
        scanf("%s", web[i].loai);
        fflush(stdin);
        fgets(web[i].nd, 256*sizeof(char), stdin);
        web[i].nd[strlen(web[i].nd) - 1] = '\0'; // Loại bỏ ký tự '\n'
        // Đọc ký tự '\n' còn lại sau mỗi dòng
        i++;
  }
  int n = i;
  heap_make(n, web);
  for(int i=0; i<n; i++){
    printf("%s %s %s %s\n",web[0].date, web[0].time, web[0].loai, web[0].nd);
    SWAP(&web[0], &web[n - i -1]);
    heap_shift_down(0, n-i-1, web);
  }
  
  free(web);
}
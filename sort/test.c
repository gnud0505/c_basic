#include <stdio.h>
#include <stdlib.h>

#define MAX_LINES 100
#define MAX_LENGTH 100

int main() {
    int n;
    scanf("%d", &n);
    char *a[n][110];
    int i=0;
    while(getchar() != NULL){
        int j=0;
        while (getchar() != '\n')
        {
            scanf("%s", a[i][j]);
            j++;
        }
        i++;
    }

    return 0;
}

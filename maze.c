#include "cgen.h"
#include <stdio.h>
#include <stdlib.h>

struct point{
    int r,c;
};

struct point *point_create(int r, int c){
    struct point *p = malloc(sizeof(struct point));
    p->r = r;
    p->c = c;
}

void point_free(void *v){
    free(v);
}


int main(){
    int n, m, r, c;
    scanf("%d %d %d %d", &n, &m, &r, &c);
    struct queue *q = qcreate(m*n);
    int maze[n][m];
    int visited[n][m];
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            scanf("%d", &maze[i][j]);
            visited[i][j]=0;
        }
    }
    qenque(q, GVOID(point_create(r,c)));
    visited[r][c]=1;
    int step=0;
    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    int sol=-1;
    while(!qempty(q)){
        struct point *p = qpeek(q)->v;
        for(int i=0; i<4; i++){
            r = p->r + dr[i];
            c = p->c + dc[i];
            if(visited[r][c] == 0 && maze[r][c] == 0 ){
                visited[r][c]=1;
                step++;
                if(r < 1 || r > n || c < 1 || c > n){
                    printf("%d", step);
                    sol=1;
                    break;
                }else{
                    qdeque(q);
                    qenque(q, GVOID(point_create(r, c)));
                }
            }
        }
        if(sol == 1){
            qfree(q);
            break;
        }
    }

    return 0;
}
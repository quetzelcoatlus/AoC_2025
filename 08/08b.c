#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BIG_N 1024

struct Distance{
    int i;
    int j;
    long int dist;
};

int comp(const void *a, const void *b){
    const struct Distance *aa = a;
    const struct Distance *bb = b;

    if (aa->dist < bb->dist) return -1;
    if (aa->dist > bb->dist) return 1;
    return 0;
}

int main(int argc, char* argv[]){
    FILE* f = fopen(argc > 1 ? argv[1] : "input", "r");
    long int tab[BIG_N][3];
    struct Distance *dists = malloc(sizeof(struct Distance) * BIG_N * BIG_N);
    int **circuts = malloc(sizeof(int *) * BIG_N);
    for(int i=0; i<BIG_N; i++){
        circuts[i]=malloc(sizeof(int)*BIG_N);
        for(int j=0;j<BIG_N;j++) circuts[i][j]=-1;
    }
    int n=0, d=0, c=0;

    while(fscanf(f,"%ld,%ld,%ld\n",&tab[n][0], &tab[n][1], &tab[n][2]) == 3){
        for(int i=0; i<n; i++){
            dists[d].i = i;
            dists[d].j = n;
            dists[d].dist = (tab[i][0]-tab[n][0])*(tab[i][0]-tab[n][0])+
                            (tab[i][1]-tab[n][1])*(tab[i][1]-tab[n][1])+
                            (tab[i][2]-tab[n][2])*(tab[i][2]-tab[n][2]);
            d++;
        }

        n++;
    }

    qsort(dists, d, sizeof(struct Distance), comp);

    int count=0;
    for(int i=0; i<d; i++){
        int x=-1,y=-1;
        for(int j=0;j<c;j++){
            int k=0;
            while(circuts[j][k] != -1){
                if(circuts[j][k] == dists[i].i) x=j;
                if(circuts[j][k] == dists[i].j) y=j;
                k++;
            }
        }
        if(x == -1 && y == -1){
            circuts[c][0]=dists[i].i;
            circuts[c++][1]=dists[i].j;
            count+=2;
        } else if(x != -1 && y == -1){
            int k=0;
            while(circuts[x][k] != -1) k++;
            circuts[x][k] = dists[i].j;
            count++;
        } else if(x == -1 && y != -1){
            int k=0;
            while(circuts[y][k] != -1) k++;
            circuts[y][k] = dists[i].i;
            count++;
        } else if(x != y){
            int k=0,l=0;
            while(circuts[x][k] != -1) k++;
            while(circuts[y][l] != -1){
                circuts[x][k++] = circuts[y][l];
                circuts[y][l++] = -1;
            }
        }
        if(count == n){
            printf("%ld\n", tab[dists[i].i][0]*tab[dists[i].j][0]);
            break;
        }
    }

    free(dists);
    for(int j=0;j<BIG_N;j++) free(circuts[j]);
    free(circuts);

    return 0;
}

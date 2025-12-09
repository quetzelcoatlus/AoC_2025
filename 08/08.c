#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BIG_N 1024
#define CONNECTIONS 1000

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

    //return  aa->dist - bb->dist; /* <-- REASON OF FAILURE */
}

int comp2(const void *a, const void *b){
    return (*(int *)b - *(int *)a);
}

int main(int argc, char* argv[]){
    FILE* f = fopen(argc > 1 ? argv[1] : "input", "r");
    long int tab[BIG_N][3], count[BIG_N];
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

    for(int i=0; i<CONNECTIONS; i++){
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
        } else if(x != -1 && y == -1){
            int k=0;
            while(circuts[x][k] != -1) k++;
            circuts[x][k] = dists[i].j;
        } else if(x == -1 && y != -1){
            int k=0;
            while(circuts[y][k] != -1) k++;
            circuts[y][k] = dists[i].i;
        } else if(x != y){
            int k=0,l=0;
            while(circuts[x][k] != -1) k++;
            while(circuts[y][l] != -1){
                circuts[x][k++] = circuts[y][l];
                circuts[y][l++] = -1;
            }
        }
    }

    for(int i=0;i<c;i++){
        int k=0;
        while(circuts[i][k] != -1) k++;
        count[i]=k;
    }

    qsort(count, c, sizeof(count[0]), comp2);

    printf("%ld\n",(long int)count[0]*count[1]*count[2]);

    free(dists);
    for(int j=0;j<BIG_N;j++) free(circuts[j]);
    free(circuts);

    return 0;
}

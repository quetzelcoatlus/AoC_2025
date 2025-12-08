#include <stdio.h>
#include <string.h>

#define BIG_N 256

int main(int argc, char* argv[]){
     FILE* f = fopen(argc > 1 ? argv[1] : "input", "r");
     char tab[BIG_N][BIG_N];
     int n=0,m, sum=0;

     while(fscanf(f,"%s\n",(char*)&tab[n]) == 1) n++;
     m=strlen(tab[0]);

     for(int i=0;i<n;i++){
        for(int j=0; j<m; j++){
            if(tab[i][j] == 'S') tab[i+1][j] = '|';
            if(tab[i][j] == '.' && tab[i-1][j] == '|') tab[i][j] = '|';
            if(tab[i][j] == '^' && tab[i-1][j] == '|'){
                sum++;
                tab[i][j-1]=tab[i][j+1]='|';
            }
        }
     }

     printf("%d\n",sum);

     return 0;
}

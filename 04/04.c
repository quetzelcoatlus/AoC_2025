#include <stdio.h>
#include <string.h>

#define MAX_SIZE 256
char tab[MAX_SIZE][MAX_SIZE];

int main(int argc, char* argv[]){
     FILE* f = fopen(argc > 1 ? argv[1] : "input", "r");
     int w,h=1,sum=0;

     while(fscanf(f,"%s\n",&tab[h][1]) == 1){
         w=strlen(&tab[h][1]);
         for(int i=1;i<=w; i++)
            tab[h][i] = tab[h][i] == '@' ? 1 : 0;

         h++;
     }

     for(int i=1;i<h;i++){
         for(int j=1; j<=w; j++){
             if(tab[i][j]){
                 int count=0;
                 for(int a=-1;a<=1;a++)
                     for(int b=-1;b<=1;b++)
                         if(a || b)
                             count += tab[i+a][j+b];

                 if(count < 4)
                     sum++;
             }
         }
     }

     printf("%d\n",sum);

     return 0;
}

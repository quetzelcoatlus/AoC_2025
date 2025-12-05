#include <stdio.h>

int main(int argc, char* argv[]){
     FILE* f = fopen(argc > 1 ? argv[1] : "input", "r");
     long int fresh[256][2], id;
     int n=0, sum=0;

     while(fscanf(f,"%ld-%ld\n",&fresh[n][0],&fresh[n][1]) == 2) n++;

     id = fresh[n][0];

     do {
         for(int i=0; i<n; i++){
             if(id >= fresh[i][0] && id <= fresh[i][1]){
                 sum++;
                 break;
             }
         }
     } while(fscanf(f,"%ld\n",&id) == 1);

     printf("%d\n",sum);

     return 0;
}

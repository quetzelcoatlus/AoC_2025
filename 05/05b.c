#include <stdio.h>

int main(int argc, char* argv[]){
     FILE* f = fopen(argc > 1 ? argv[1] : "input", "r");
     long int fresh[256][2], n=0, sum=0;

     while(fscanf(f,"%ld-%ld\n",&fresh[n][0],&fresh[n][1]) == 2) n++;

     for(int i=0; i<n; i++){
         for(int j=0; j<n; j++){
             if(j == i) continue;
             if(fresh[i][0] >= fresh[j][0] && fresh[i][0] <= fresh[j][1]){
                 fresh[j][1] = fresh[i][1] > fresh[j][1] ? fresh[i][1] : fresh[j][1];
                 fresh[i][0] = -1, fresh[i][1] = -2;
                 break;
             }
             if(fresh[i][1] >= fresh[j][0] && fresh[i][1] <= fresh[j][1]){
                 fresh[j][0] = fresh[i][0] < fresh[j][0] ? fresh[i][0] : fresh[j][0];
                 fresh[i][0] = -1, fresh[i][1] = -2;
                 break;
             }
         }
         sum += fresh[i][1]-fresh[i][0]+1;
     }

     printf("%ld\n",sum);

     return 0;
}

#include <stdio.h>

int main(int argc, char* argv[]){
     FILE* f = fopen(argc > 1 ? argv[1] : "input", "r");
     int d, r=50, count=0, zero;
     char c;

     while(fscanf(f,"%c%d\n",&c,&d) == 2){
         while(d>=100) { count++; d-=100; }
         zero = r == 0 ? 1 : 0;
         r += c == 'R' ? d : -d;
         if(r==0 && !zero) count++;
         if(r<0){ if(!zero) count++; r+=100; }
         if(r>=100){ count++; r-=100; }
     }
     printf("%d\n", count);

     return 0;
}

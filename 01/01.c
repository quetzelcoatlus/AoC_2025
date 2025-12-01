#include <stdio.h>

int mymod(int a, int b){
    a%=b;
    return a>=0 ? a : a+b;
}

int main(int argc, char* argv[]){
     FILE* f = fopen(argc > 1 ? argv[1] : "input", "r");
     int d, tab[100]= {0}, r=50;
     char c;

     while(fscanf(f,"%c%d\n",&c,&d) == 2){
         r = mymod(r + (c == 'R' ? d : -d), 100);
         tab[r]++;
     }
     printf("%d\n", tab[0]);

     return 0;
}

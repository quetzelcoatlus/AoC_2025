#include <stdio.h>
#include <string.h>

int check_invalid(long int n){
    char str[32];
    sprintf(str, "%ld", n);
    int len = strlen(str);
    if(len % 2) return 0;

    return !strncmp(str, str+len/2, len/2);
}

int main(int argc, char* argv[]){
     FILE* f = fopen(argc > 1 ? argv[1] : "input", "r");
     long int a, b, sum=0;

     while(fscanf(f,"%ld-%ld,",&a,&b) == 2)
         for(long int i=a; i<=b; i++)
             if(check_invalid(i))
                 sum+=i;

     printf("%ld\n",sum);

     return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BIG_N 10000
#define SMALL_N 10

int main(int argc, char* argv[]){
    FILE* f = fopen(argc > 1 ? argv[1] : "input", "r");
    char *str=NULL, tab[SMALL_N][BIG_N];
    size_t size = 0;
    int n=0;
    long int sum=0;

    while(getline(&str, &size, f) != -1) strcpy(tab[n++],str);

    int last = strlen(tab[n-1]);
    for(int i=last-2; i>=0; i--){
        if(tab[n-1][i] == '*' || tab[n-1][i] == '+'){
            long int tmp = tab[n-1][i] == '*' ? 1 : 0;
            for(int j=last-2; j>=i; j--){
                char buf[n];
                for(int k=0; k<n-1; k++) buf[k]=tab[k][j];
                buf[n-1]=0;

                int number = atoi(buf);
                tmp = tab[n-1][i] == '*' ? tmp * number : tmp + number;
            }
            sum += tmp;
            last = i;
        }
    }

    printf("%ld\n",sum);

    return 0;
}

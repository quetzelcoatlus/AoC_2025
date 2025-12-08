#include <stdio.h>

#define BIG_N 10000
#define SMALL_N 10

int main(int argc, char* argv[]){
    FILE* f = fopen(argc > 1 ? argv[1] : "input", "r");
    char *str = NULL, *tmp;
    size_t size = 0;
    int n=0, i=0, nums[SMALL_N][BIG_N];
    long int sum=0;

    while(getline(&str, &size, f) != -1){
        tmp=str;
        while(*tmp == ' ') tmp++;
        if(*tmp == '*' || *tmp == '+') break;
        while(sscanf(tmp,"%d",&nums[n][i]) > 0){
           i++;
           while(*tmp >='0' && *tmp <= '9') tmp++;
           while(*tmp == ' ') tmp++;
        }
        n++;
        i=0;
    }

    while(*tmp){
        if(*tmp == '*'){
            long int mul=1;
            for(int j=0;j<n; j++){
                mul *= nums[j][i];
            }
            sum += mul;
            i++;
        } else if(*tmp == '+'){
            long int add=0;
            for(int j=0;j<n; j++){
                add += nums[j][i];
            }
            sum += add;
            i++;
        }
        tmp++;
    }

    printf("%ld\n",sum);

    return 0;
}

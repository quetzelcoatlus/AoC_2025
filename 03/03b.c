#include <stdio.h>
#include <string.h>

#define BATTERIES 12

int main(int argc, char* argv[]){
     FILE* f = fopen(argc > 1 ? argv[1] : "input", "r");
     char buf[256];
     long int sum=0;

     while(fscanf(f,"%s\n",buf) == 1){
        long int joltage=0;
        int pos=-1, len=strlen(buf);
        for(int i=BATTERIES-1; i>=0; i--){
            long int max=0;
            for(int j=pos+1;j<len-i;j++){
                int val=buf[j]-'0';
                if(val>max){
                    max=val;
                    pos=j;
                }
            }
            joltage*=10;
            joltage+=max;
        }
        sum+=joltage;
     }

     printf("%ld\n",sum);

     return 0;
}

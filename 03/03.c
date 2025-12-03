#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]){
     FILE* f = fopen(argc > 1 ? argv[1] : "input", "r");
     char buf[256];
     int sum=0,m1,m2,i1,len;

     while(fscanf(f,"%s\n",buf) == 1){
         m1=m2=0;
         len=strlen(buf);
         for(int i=0; i<len; i++){
            int val=buf[i]-'0';
            if(val>m1){
                m1=val;
                i1=i;
            }
         }
         if(i1==len-1){
             for(int i=0; i<len-1; i++){
                int val=buf[i]-'0';
                if(val>m2)
                    m2=val;
             }
             sum+=m2*10+m1;
         } else {
             for(int i=i1+1; i<len; i++){
                int val=buf[i]-'0';
                if(val>m2)
                    m2=val;
             }
             sum+=m1*10+m2;
         }
     }

     printf("%d\n",sum);

     return 0;
}

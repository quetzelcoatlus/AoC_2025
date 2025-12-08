#include <stdio.h>
#include <string.h>
#include <search.h>

#define BIG_N 256
char tab[BIG_N][BIG_N];
int n,m;

#define SMALL_N 16
char keys[BIG_N*BIG_N][SMALL_N];
long int values[BIG_N*BIG_N], h=0;

long int count_timelines(int i, int j){
    if(i == n-1) return 1;

    char key[SMALL_N];
    sprintf(key,"%d-%d",i,j);
    ENTRY entry = {.key = key}, *found_entry;
    if((found_entry=hsearch(entry, FIND)) != NULL)
        return *( (long int *) found_entry->data);

    long int result;
    if(tab[i+1][j] == '|') result = count_timelines(i+1, j);
    if(tab[i+1][j] == '^') result = count_timelines(i+1,j-1) + count_timelines(i+1,j+1);

    strcpy(keys[h], key);
    values[h] = result;
    entry.key = keys[h];
    entry.data = &values[h];
    hsearch(entry, ENTER);
    h++;

    return result;
}

int main(int argc, char* argv[]){
    FILE* f = fopen(argc > 1 ? argv[1] : "input", "r");
    int s;

    hcreate(BIG_N*BIG_N);

    while(fscanf(f,"%s\n",(char*)&tab[n]) == 1) n++;
    m=strlen(tab[0]);

    for(int i=0;i<n;i++){
       for(int j=0; j<m; j++){
           if(tab[i][j] == 'S'){ tab[i+1][j] = '|'; s=j; }
           if(tab[i][j] == '.' && tab[i-1][j] == '|') tab[i][j] = '|';
           if(tab[i][j] == '^' && tab[i-1][j] == '|') tab[i][j-1]=tab[i][j+1]='|';
       }
    }

    printf("%ld\n",count_timelines(1,s));

    hdestroy();

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
int main(void)
{
    srand(time(NULL));
    int random_variable = rand();
    printf("Random value on [0,%d]: %d\n", RAND_MAX, random_variable);
    int x = 0;
 
    for (int n=0; n != 20; ++n) {
        x = rand();
        printf("%d ",  x); 
    }
}
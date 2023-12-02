#define RESET       "\033[0m"
#define BOLDRED     "\033[1m\033[31m"
#define BOLDGREEN   "\033[1m\033[32m"
#define TOTAL       100000000
#include <stdio.h>
#include <time.h>
int odd_and_divisible_7(int n);
int odd_and_divisible_7_nested(int n);

int main() {
    clock_t start, end;
    while(1) 
    {
        // Test unnested
        start = clock();
        for(int i = 0; i < TOTAL; i++) {
            odd_and_divisible_7(i);
        }
        end = clock();
        double unnested_time = ((double) (end - start)) / CLOCKS_PER_SEC;

        // Test nested
        start = clock();
        for(int i = 0; i < TOTAL; i++) {
            odd_and_divisible_7_nested(i);
        }
        end = clock();
        double nested_time = ((double) (end - start)) / CLOCKS_PER_SEC;


        if(unnested_time > nested_time)
        {
            printf(BOLDGREEN);
            printf("Nested was faster\n");
        }
        else
        {
            printf(BOLDRED);
            printf("Nested was slower\n");
        }
        printf(RESET);
        printf("Nested Time: %f\n", nested_time);
        printf("Unnested Time: %f\n", unnested_time);
    }
    return 0;
}

int odd_and_divisible_7(int n) {
    if(n % 2 && !(n % 7))
    {
        return 1;
    }
    return 0;
}

int odd_and_divisible_7_nested(int n) 
{
    if(n % 2) 
    {
        if(!(n % 7))
        {
            return 1;
        }
    }
    return 0;
}
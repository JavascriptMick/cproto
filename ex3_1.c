#include <stdio.h>
#include <time.h>

int binsearch(int x, int v[], int n, int i);
int binsearchFast(int x, int v[], int n, int i);

int main()
{
    //setup variables
    int r, i;
    int v[50];
    for(i=0; i<50; ++i)
        v[i] = i * 2;

    //setup timer
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    //----- work --------
    for(i = 0; i < 10000; ++i)
        r = binsearch(77, v, 50, i);
    //----- work --------

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Slow: %f\n", cpu_time_used);

    start = clock();
    //----- work --------
    for(i = 0; i < 10000; ++i)
        r = binsearchFast(77, v, 50, i);
    //----- work --------

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Fast: %f\n", cpu_time_used);
}

int binsearch(int x, int v[], int n, int i)
{
    int low, high, mid, c;
    low = c = 0;
    high = n - 1;
    while (low <= high)
    {
        c++;
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else{ /* foundmatch */
            if(i==0)
                printf("slow count: %d\n", c);
            return mid;
        }
    }
    if(i==0)
        printf("slow count: %d\n", c);
    return -1; /*nomatch*/
}

int binsearchFast(int x, int v[], int n, int i)
{
    int low, high, mid, c;
    low = c = 0;
    high = n - 1;
    while (low <= high)
    {
        c++;
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    if(i==0)
        printf("fast count: %d\n", c);

    if(x == v[mid])
        return mid;
    else
        return -1; /*nomatch*/
}
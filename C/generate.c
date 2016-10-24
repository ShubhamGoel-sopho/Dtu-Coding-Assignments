/**
 * generate.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Generates pseudorandom numbers in [0,LIMIT), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */
 
#define _XOPEN_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// constant
#define LIMIT 65536

int main(int argc, string argv[])
{
    // if no of command line arguments are less than 2 and greater then 3...
    if (argc != 2 && argc != 3)
    {
        printf("Usage: generate n [s]\n");
        return 1;
    }

    // atoi function actually converts the string in to the integer...
    int n = atoi(argv[1]);

    // if some optional command line provided then call the srand48 (initialization or seeding function to drand48)
    if (argc == 3)
    {
        srand48((long int) atoi(argv[2]));
    }
    else
    {
        srand48((long int) time(NULL));
    }

    // The drand48() functions return nonnegative double-precision floating-point values uniformly distributed between [0.0, 1.0).and
    //we loop over n times(argv[1] passed by user)and multiply random no by limit macro and type casted in to integer

    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));
    }

    // success
    return 0;
}
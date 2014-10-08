#include <stdio.h>
// #include "../include/public_interface.hpp"
// #include "../utils/util.h"
#include "public_interface.hpp"
#include "util.h"

// ensure that we can call c functions in other subdirectories
// TODO SELF: this is breaking right now
void printStuff() {
	int utilValue = util_func();
	printf("Called printStuff in cpp file; util func value = %d.\n", utilValue);	// this breaks it
	// printf("Called printStuff in cpp file without invoking utils func\n");
}

void inplace(double *invec, int n)
{
    int i;

    for (i=0; i<n; i++)
    {
        invec[i] = 2*invec[i];
    }
}

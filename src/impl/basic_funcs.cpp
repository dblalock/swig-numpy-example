#include <stdio.h>
#include "public_interface.hpp"
#include "util.h"

// ensure that we can call c functions in other subdirectories
void printStuff() {
	int utilValue = util_func();
	printf("Called printStuff in cpp file; util func value = %d.\n", utilValue);	// this breaks it
	// printf("Called printStuff in cpp file without invoking utils func\n");
}

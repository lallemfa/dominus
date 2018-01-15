#include <stdlib.h>
#include <stdio.h>

int main (int argc, char* argv[])
{
    // Will contain the parameters
    int pin, value;

    char path[25];
    FILE* fd;

    // Check correct use and update parameters
    if (argc != 3)
    {
        printf("Needed 2 arguments but %d given.\nUse this way -> ./gpio_set Pin Value\n", argc-1);
        return EXIT_FAILURE;
    } else {
        pin     = atoi(argv[1]);
        value   = (atoi(argv[2]) != 0) ? 1 : 0;                
    }

    sprintf(path, "/sys/class/gpio/gpio%d/value", pin);

    if((fd = fopen(path, "r+")) == 0)
    {
        printf("GPIO%d not existing yet. Creating it...\n", pin);
        sprintf(path, "/sys/class/gpio/gpio%d/value", pin);
        if((fd = fopen(path, "a+")) == 0) {
            
        }
        printf("Created !! (Maybe...)\n")
    }

    return EXIT_SUCCESS;  
}

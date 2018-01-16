#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main (int argc, char* argv[])
{
    char rootPath[100];
    char valuePath[100];
    char directionPath[100];

    int valueFile, exportFile, directionFile;

    // Check correct use and update parameters
    if (argc != 3)
    {
        printf("Needed 2 arguments but %d given.\nUse this way -> ./gpio_set Pin Value\n", argc-1);
        return EXIT_FAILURE;
    }

    sprintf(rootPath, "/sys/class/gpio/gpio%s", argv[1]);
    sprintf(valuePath, "%s/value", rootPath);

    if ((valueFile = open(valuePath, O_WRONLY)) < 0)
    {
        if (errno == ENOENT) // GPIO not initialized yet
        {
            if ((exportFile = open("/sys/class/gpio/export", O_WRONLY)) < 0)
            {
                perror("Export failure");
                return EXIT_FAILURE;
            } 

            // Open GPIO by giving the number to export
            write(exportFile, atoi(argv[1]), strlen(argv[1]));
            close(exportFile);

            // Set direction to output
            
            sprintf(directionPath, "%s/direction", rootPath);
            printf("%s\n", directionPath);

            if ((directionFile = open(directionPath, O_WRONLY)) < 0)
            {
                perror("Direction failure");
                return EXIT_FAILURE;
            }

            char* direction = "out";
            write(directionFile, direction, strlen(direction));
            close(directionFile);
        
            if ((valueFile = open(valuePath, O_WRONLY)) < 0)
            {
                perror("Value failure");
                return EXIT_FAILURE;
            }

        } else {
            return EXIT_FAILURE;
        }
    }

    // Write new value to pin
    write(valueFile, argv[2], strlen(argv[2]));
    close(valueFile);

    return EXIT_SUCCESS;  
}

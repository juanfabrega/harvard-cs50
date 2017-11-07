#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        return 0;
        printf("%s", argv[1]);
    }

    else if (strlen(argv[1]) > 4)
    {
        printf("Hash must not exceed 4 characters");
        return 1;
    }

    else
    {
        printf("Please enter at least 1, but no more than 1 command line arguments.\n");
        return 1;
    }
}
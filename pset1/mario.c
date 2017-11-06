#include <cs50.h>
#include <stdio.h>

// Function prototype declarations
void floorbuilder(int total, char toPrint);

int main(void)
{
    char space = ' ';
    char hash = '#';
    int floors;
    
    // Ask user for positive integer between 1 and 23.
    do
    {
        printf("Enter an integer from 0 to 23: ");
        floors = get_int();
    }
    while (floors > 23 || floors < 0);

    
    // loop necessary functions based on number of floors
    for (int i = 0; i < floors; i++) 
    {
        floorbuilder((floors - (i + 1)), space);
        floorbuilder((i + 1), hash);   
        printf("  ");
        floorbuilder((i + 1), hash);    
        printf("\n");
    }
}

// Builds pyramid floors. Takes character to be printed and amount to print.
void floorbuilder(int total, char toPrint)
{
    for (int i = 0; i < total; i++)
    {
        printf("%c", toPrint);
    }
}

#include <cs50.h>
#include <stdio.h>

// this program will take an integer as input from the user.
// user unput corresponds to number of minutes per shower.
// program calculates amount of water used based on length.
// uses a total of 12 water bottles per minute.
int main(void)
{
    printf("Enter length of shower in minutes: ");
    int shower = get_int();
    int bottles = shower * 12;
    printf("Every time you shower, you're using %i bottles of water \n", bottles);
}
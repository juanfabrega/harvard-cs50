#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    // get user input string
    char *name = get_string();

    // iterate through string characters
    for (int i = 0; i < strlen(name); i++)
    {
        // Get first initial if first char is NOT a space.
        if (i == 0 && name[i] != ' ')
        {
            // transform lowercase initials to uppercase
            if (name[i] > 90)
            {
                name[i] -= 32;
            }
            printf("%c", name[i]);
        }

        // find spaces in rest of string
        else if (name[i] != ' ')
        {
            // if char comes after space, consider it an initial (print)
            if (name[i - 1] == ' ')
            {
                // transform lowercase initials to uppercase
                if (name[i] > 90)
                {
                    name[i] -= 32;
                }
                printf("%c", name[i]);
            }
        }
    }
    printf("\n");
}
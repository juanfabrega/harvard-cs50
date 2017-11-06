#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdbool.h>

// this program will encrypt a text input using Caesar's cipher.
// The cipher is based on shifting alphabetical characters by a predetermined offset
// the program takes a positive integer as command line argument which corresponds to the character offset.
// the user is then prompted to enter a string input to be encrypted with the key value.
// before exiting the program will output encrypted text.

char *makeCipherText(char *plainText, int offset);

int main(int argc, char *argv[])
{
    // only continue program if user enters 1, but no more CLI arguments.
    // the IF statement checks for 2 arguments since prorgram name is default 1st arg.
    if (argc == 2)
    {
        // convert argument to int (default is string for CL arguments)
        int offset = atoi(argv[1]);

        // prompt the user for string input
        printf("plaintext: ");
        char *plainText = get_string();

        // print encrypted output
        printf("ciphertext: ");
        printf("%s\n", makeCipherText(plainText, offset));
        return 0;
    }

    // if user enters no CLI arguments, or more than 1 CLI argument. Print error and exit.
    else
    {
        printf("Enter at least 1, but no more than 1 command line argument.\n");
        return 1;
    }
}

// function to generate encrypted text
// takes 2 arguments, plaintext, and offset value of the key.
char *makeCipherText(char *plainText, int offset)
{
    char *cipherText = plainText;

    // since offset values above 26 will only loop back to the start of the alphabet
    // we want only the reminder of the offset divided by 26.
    offset = offset % 26;

    // iterate through all characters in plainText input to map them to cipherText.
    for (int i = 0; i < strlen(plainText); i++)
    {

        // these booleans will be used to eval if we're dealing with an alpha character
        // also if that character is in the uppercase ascii range or lowercase
        bool isUppercase = plainText[i] > 64 && plainText[i] < 91;
        bool isLowercase = plainText[i] > 96 && plainText[i] < 123;

        // if it is not an alpha character, just keep this char the same.
        if (!isUppercase && !isLowercase)
        {
            cipherText[i] = plainText[i];
        }

        // if uppercase, use the relevant ascii range
        else if (isUppercase)
        {

            // ensure we loop back to beginning and don't go past ascii range
            if ((90 - plainText[i]) < offset)
            {
                cipherText[i] = 64 + (offset - (90 - plainText[i]));
            }
            else
            {
                cipherText[i] = plainText[i] + offset;
            }
        }

        // if lowercase, use relevant ascii range
        else if (isLowercase)
        {

            // ensure we loop back to beginning and don't go past ascii range
            if ((122 - plainText[i]) < offset)
            {
                cipherText[i] = 96 + (offset - (122 - plainText[i]));
            }
            else
            {
                cipherText[i] = plainText[i] + offset;
            }
        }
    }

    return cipherText;
}

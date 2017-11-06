#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdbool.h>

char *makeCipherText(char *plainText, int offset);

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        int offset = atoi(argv[1]);
        printf("plaintext: ");
        char *plainText = get_string();

        printf("ciphertext: ");

        printf("%s\n", makeCipherText(plainText, offset));
        return 0;
    }

    else
    {
        printf("Enter at least 1, but no more than 1 command line argument.\n");
        return 1;
    }
}

char *makeCipherText(char *plainText, int offset)
{
    char *cipherText = plainText;
    offset = offset % 26;
    
    for (int i = 0; i < strlen(plainText); i++)
    {
        bool isUppercase = plainText[i] > 64 && plainText[i] < 91;
        bool isLowercase = plainText[i] > 96 && plainText[i] < 123;
        
        if (!isUppercase && !isLowercase)
        {
            cipherText[i] = plainText[i];
        }

        else if (isUppercase)
        {
            if ((90 - plainText[i]) < offset)
            {
                cipherText[i] = 64 + (offset - (90 - plainText[i]));
            }
            else
            {
                cipherText[i] = plainText[i] + offset;
            }
        }

        else if (isLowercase)
        {
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

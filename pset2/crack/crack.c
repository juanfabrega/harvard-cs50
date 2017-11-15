#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <crypt.h>

// this program will take in 1 command line argument in the form of a hash
// and print out the corresponding password that generated that hash.
// it only cracks 4-character passwords with alpha characters (upper and lowercase)
// contained all to the main function since didn't find too much efficiency in modularizing the code.

int main(int argc, char **argv)
{
    //ensure user entered at least one CL argument, but no more.
    if (argc == 2)

    {
        // necessary input for crypt function.
        char *salt = "50";

        //we will use this alphabet array to loop through all possible word combinations.
        char *alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

        char password_1[2];
        char password_2[3];
        char password_3[4];
        char password_4[5];

        // first for loop checks for 1-char passwords
        for (int a_1 = 0; a_1 < strlen(alphabet); a_1++)
        {

            password_1[0] = alphabet[a_1];

            if (strcmp(crypt(password_1, salt), argv[1]) == 0)
            {
                printf("%s\n", password_1);
                return 0;   //exit program if password found.
            }
        }

        // second for loop (2 deep) checks 2-char passwords
        for (int a_2 = 0; a_2 < strlen(alphabet); a_2++)
        {
            for (int b_2 = 0; b_2 < strlen(alphabet); b_2++)
            {
                password_2[0] = alphabet[a_2];
                password_2[1] = alphabet[b_2];

                if (strcmp(crypt(password_2, salt), argv[1]) == 0)
                {
                    printf("%s\n", password_2);
                    return 0;   //exit program if password found.
                }
            }
        }

        //third for loop (3-deep) checks 3-char passwords
        for (int a_3 = 0; a_3 < strlen(alphabet); a_3++)
        {
            for (int b_3 = 0; b_3 < strlen(alphabet); b_3++)
            {
                for (int c_3 = 0; c_3 < strlen(alphabet); c_3++)
                {
                    password_3[0] = alphabet[a_3];
                    password_3[1] = alphabet[b_3];
                    password_3[2] = alphabet[c_3];

                    if (strcmp(crypt(password_3, salt), argv[1]) == 0)
                    {
                        printf("%s\n", password_3);
                        return 0;
                    }
                }
            }
        }

        // fourth loop (4-deep) checks 4-char passwords.
        for (int a_4 = 0; a_4 < strlen(alphabet); a_4++)
        {
            for (int b_4 = 0; b_4 < strlen(alphabet); b_4++)
            {
                for (int c_4 = 0; c_4 < strlen(alphabet); c_4++)
                {
                    for (int d_4 = 0; d_4 < strlen(alphabet); d_4++)
                    {
                        password_4[0] = alphabet[a_4];
                        password_4[1] = alphabet[b_4];
                        password_4[2] = alphabet[c_4];
                        password_4[3] = alphabet[d_4];

                        // compare current hypothesis with the input hash
                        if (strcmp(crypt(password_4, salt), argv[1]) == 0)
                        {
                            printf("%s\n", password_4);
                            return 0;   //exit program if password found.
                        }
                    }
                }
            }
        }

        //exit and return with 1 if password not found.
        printf("Password not found!\n");
        return 1;

    }   // end argument check statement.

    // return 1 if command line arguments are incorrect.
    else
    {
        printf("Please enter at least 1, but no more than 1 command line arguments.\n");
        return 1;
    }
}
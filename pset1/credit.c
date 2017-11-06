#include <cs50.h>
#include <stdio.h>
#include <math.h>

// This program will take a numerical input from user
// and verify if said number is a valid credit card
// We'll be using Luhn's algorithm to confirm number validity.
// This does not confirm if the credit card actually exists.

int findCardLength(long long cardNumber);
int isRightLength(int cardLength);
int getLuhnSum(long long cardNumber);
int whichCard(long long cardNumber);

int main (void)
{
    printf("Enter a credit card number: ");
    long long cardNumber = get_long_long();

    // verify if our checksum ends with 0
    if (getLuhnSum(cardNumber) % 10 == 0)
    {
        whichCard(cardNumber);
    }

    else
    {
        printf("INVALID\n");
    }
    return 0;
}

// find the length of digits in card entered.
// this method uses the absolute value of the entered number
// and calculates the base10 logarithm to get a the number of digits
// we add 1 to the results, since base10log will round down.
int findCardLength(long long cardNumber)
{
    return (cardNumber == 0 ? 1 : floor(log10(llabs(cardNumber))) + 1);
}

// verify if card digits length matches one of 3 valid options.
int isRightLength(int cardLength)
{
    if (cardLength == 13 || cardLength == 15 || cardLength == 16)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Uses Luhn's algorithm to get the checksum of a card number.
int getLuhnSum(long long cardNumber)
{

    long long tempCard = cardNumber;
    int sumEvenDigits = 0;
    int sumOddDigits = 0;
    int totalSum = 0;

    // iterate backward through card
    for (int i = 1; i <= findCardLength(cardNumber) + 1; i++)
    {
        //get last digit via modulo and store sum in relevant variable.
        if (i % 2 == 0)
        {
            //if digit times 2 is larger than 10, sum each digit rather than multiply by two.
            if (((tempCard % 10) * 2) > 9)
            {
                sumEvenDigits += ((tempCard % 10) * 2) % 10;
                sumEvenDigits += floor(((tempCard % 10) * 2) / 10);
            }
            else
            {
                sumEvenDigits += (tempCard % 10) * 2; //even index digit times 2 (Luhn)
            }
        }
        else
        {
            sumOddDigits += tempCard % 10;
        }

        //divide card number so next iteration will get new last number.
        tempCard /= 10;
    }

    totalSum = sumOddDigits + sumEvenDigits;

    return totalSum;

}

// determine which type of card was entered based on the
// first two digits
int whichCard(long long cardNumber)
{

    int length = findCardLength(cardNumber);

    // to get the first two digits we have to divide the card number by 10 to the power of X
    // where X is the card length - 1 for the first digit and length - 2 for the second.
    long long denominatorFirst = powl(10, length - 1);
    long long denominatorSecond = powl(10, length - 2);

    int firstDigit = floor(cardNumber / denominatorFirst);
    //to get the second digit we get the first two and shave off the first with modulo 10.
    int secondDigit = (int)floor(cardNumber / denominatorSecond) % 10;

    // logic to get card type
    if (firstDigit == 4)
    {
        printf("VISA\n");
    }
    else if (firstDigit == 5)
    {
        if (secondDigit == 1 || secondDigit == 2 || secondDigit == 3 || secondDigit == 4 || secondDigit == 5)
        {
            printf("MASTERCARD\n");
        }
    }
    else if (firstDigit == 3 && secondDigit == 7)
    {
        printf("AMEX\n");
    }
    else
    {
        printf("INVALID\n");
    }
    return 0;
}


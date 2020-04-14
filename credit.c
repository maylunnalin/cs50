#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    //Prompt for input.
    long long cc_number;
    do
    {
        cc_number = get_long_long("Credit card number: ");
    }
    while (cc_number < 0);
    
    //Count length.
    int cc_length = 0;
    long long check_length = cc_number;
    {
        while (check_length > 0)
        {
            check_length = check_length / 10;
            cc_length++;
        }
    }

    //Check cc_length = 13, 15, 16
    if (cc_length != 13 && cc_length != 15 && cc_length != 16)
    {
        printf("INVALID\n");
    }

    //Check Luhn's Algorithm.
    //Digit odd: Sum of every other digit, starting with last digit.
    int digit1 = (cc_number % 10);
    int digit3 = (cc_number % 1000) / 100;
    int digit5 = (cc_number % 100000) / 10000;
    int digit7 = (cc_number % 10000000) / 1000000;
    int digit9 = (cc_number % 1000000000) / 100000000;
    int digit11 = (cc_number % 100000000000) / 10000000000;
    int digit13 = (cc_number % 10000000000000) / 1000000000000;
    int digit15 = (cc_number % 1000000000000000) / 100000000000000;
    int digitodd = digit1 + digit3 + digit5 + digit7 + digit9 + digit11 + digit13 + digit15;
    //Digit even: Sum of digits of (product of every other digit times 2, starting from second-to-last digit).
    int digit2 = 2 * ((cc_number % 100) / 10);
    int digit4 = 2 * ((cc_number % 10000) / 1000);
    int digit6 = 2 * ((cc_number % 1000000) / 100000);
    int digit8 = 2 * ((cc_number % 100000000) / 10000000);
    int digit10 = 2 * ((cc_number % 10000000000) / 1000000000);
    int digit12 = 2 * ((cc_number % 1000000000000) / 100000000000);
    int digit14 = 2 * ((cc_number % 100000000000000) / 10000000000000);
    int digit16 = 2 * ((cc_number % 10000000000000000) / 1000000000000000);
    int digiteven = (digit2 % 10) + ((digit2 % 100) / 10);
    digiteven = digiteven + (digit4 % 10) + ((digit4 % 100) / 10);
    digiteven = digiteven + (digit6 % 10) + ((digit6 % 100) / 10);
    digiteven = digiteven + (digit8 % 10) + ((digit8 % 100) / 10);
    digiteven = digiteven + (digit10 % 10) + ((digit10 % 100) / 10);
    digiteven = digiteven + (digit12 % 10) + ((digit12 % 100) / 10);
    digiteven = digiteven + (digit14 % 10) + ((digit14 % 100) / 10);
    digiteven = digiteven + (digit16 % 10) + ((digit16 % 100) / 10);
    //Checksum: Add both sums together.
    int digitsum = digiteven + digitodd; 
    //Check Luhn's Algorithm: digitsum must be divisible by 10.
    if (digitsum % 10 != 0)
    {
        printf("INVALID\n");
    }
    else
    {
        //Check AMEX, digits 15, starts with 34 37.
        if (cc_length == 15)
        {
            long long AMEX = cc_number / 10000000000000;
            if (AMEX == 34 || AMEX == 37)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        //Check MASTERCARD, digits 16, starts with 51 52 53 54 55.
        //Check VISA, digits 16, starts with 4.
        if (cc_length == 16)
        {
            long long MASTERVISA = cc_number / 100000000000000;
            if (MASTERVISA > 50 && MASTERVISA < 56)
            {
                printf("MASTERCARD\n");
            }
            else if (MASTERVISA > 39 && MASTERVISA < 50)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }

        //Check VISA, digits 13, starts with 4.
        if (cc_length == 13)
        {
            long long VISA = cc_number / 1000000000000;
            if (VISA == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }    
    }
}

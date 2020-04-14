#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    //Prompt user for an amount of change.
    float dollars;
    do
    {
        dollars = get_float("Change owed: ");
    }
    while (dollars <= 0);
    // convert float to int.
    int cents = round(dollars * 100);
    //Use the largest coins possible, keeping track of coins used.
    int quarters, dimes, nickels, pennies, a, b;
    //Keep track of how many coins used.
    quarters = cents / 25;
    //Keep track of remaining change owed.
    a = cents % 25;
    //Keep track of how many coins used.
    dimes = a / 10;
    //Keep track of remaining change owed.
    b = a % 10;
    //Keep track of how many coins used.
    nickels = b / 5;
    //Keep track of remaining change owed.
    pennies = b % 5;
    //Print the number of coins.
    int coins;
    coins = quarters + dimes + nickels + pennies; 
    printf("Coins used: %i\n", coins);
}

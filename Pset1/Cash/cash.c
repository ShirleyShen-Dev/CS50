#include <stdio.h>
#include <math.h>

int main(void)
{
    // Ask for change from user;
    float change;
    do
    {
       printf("Change you need:");
       scanf("%f", &change);
    }
    
    // Convert dollar input to cents
    while (change < 0);
    int c = round(change*100);

    // Find whole coins
    int quarters = c / 25;
    c = c - quarters * 25;
    
    int dimes = c / 10;
    c = c - dimes * 10;
    
    int nickles = c / 5;
    c = c - nickles * 5;
    
    int pennies = c;
    int coins = quarters + dimes + nickles + pennies;
    printf("Change received: %i coins.\n", coins);

}

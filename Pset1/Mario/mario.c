#include <stdio.h>

int main(void)
{
    int h;
    // Ensure input is acceptable integer value
    do
    {
        printf("How tall is mario's obstacle:");
        scanf("%d", &h);
    }
    while (h < 1 || h > 8);
    for (int i = 0; i < h; i++)
    {
        // Build empty space
        for (int j = h - 1; j > i ; j--)
        {
            printf(" ");
        }
        
        // Build left side of pyramid
        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }
        
        // Build gap
        if (i >= 0)
        {
            printf("  ");
        }
        
        // Buidl right side of pyramid
        for (int l = 0; l < i + 1; l++)
        {
            printf("#");
        }
        if (i >= 0)
        {
            printf("\n");
        }

    }
}

#include <cs50.h>
#include <stdio.h>


void bricks(int n);

int main(void)
{
    int n;

    // Ask user for a width between 1 and 8
    do
    {
        n = get_int("What is the bottom width? ");
    }
    while (n < 1 || n > 8);
    
    // Calls brick function
    bricks(n);
}

void bricks(int n)
{
    //Calculates number of empty space
    int k = n - 1;

    // Starts building the tower
    for (int i = 0; i < n; i++)
    {

        // Empty Spaces
        for (int y = 0; y < k; y++)
        {
            printf(" ");
        }

        // Hashes
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        
        // Empty Space
        printf("  ");
        
        // Hashes
        for (int y = 0; y < i + 1; y++)
        {
            printf("#");
        }

        // New line and reduce empty space on the next line
        printf("\n");
        k--;
    }

}

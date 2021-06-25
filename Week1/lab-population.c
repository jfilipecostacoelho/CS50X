#include <cs50.h>
#include <stdio.h>

int main(void)
{
 
    int startsize;
    int endsize;
    int year = 0;
    
    do
    {
        // Ask for initial Llamas population
        startsize = get_int("What is the starting population of Llamas?\n");
    }
    while (startsize < 9);
    
    do
    {
        // Ask for ending Llamas population
        endsize = get_int("What is the ending population of Llamas?\n");
    }
    while (startsize > endsize);
    
    while (startsize < endsize)
    {
        // Calculates the years needed
        startsize = startsize + (startsize / 3) - (startsize / 4);
        year++;
    };
    
    
 
    
    // Show answer
    printf("Years: %i \n", year);
}

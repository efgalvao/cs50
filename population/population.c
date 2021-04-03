#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Get the starting population
    int start_size;
    do
    {
        start_size = get_int("Start size: ");
    }
    while (start_size < 9);

    // Get the final population
    int end_size;
    do
    {
        end_size = get_int("End size: ");
    }
    while (end_size < start_size);


    // Calculate the amount of years
    int size = start_size;
    int years = 0;
    while (size < end_size)
    {
        size = size + (size / 3) - (size / 4);
        years++;
    }

    // Give the amount of years to the user
    printf("Years: %i", years);
}
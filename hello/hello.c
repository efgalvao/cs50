#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Ge the name of the user
    string name = get_string("What is your name?");

    //Print the name of the user
    printf("hello, %s\n", name);
}
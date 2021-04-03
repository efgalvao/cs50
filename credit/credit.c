#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//GET CARD LENGTH
int get_card_len(long value)
{
    int l = 1;
    while (value > 9)
    {
        l++;
        value /= 10;
    }
    return l;
}


//SUM OF DIGITS
int sum_digits(int number)
{
    int t, sum = 0, remainder;

    t = number;

    while (t != 0)
    {
        remainder = t % 10;
        sum = sum + remainder;
        t = t / 10;
    }

    return sum;
}

// VALIDATION FUNCTION
int validator(long card)
{
    // Get the card length
    int card_len = get_card_len(card);
    char card_s[card_len];
    snprintf(card_s, card_len + 1, "%ld", card);

    // Do step 1 of the verification
    int multi;
    int sum = 0;
    for (int i = card_len - 2; i >= 0; i -= 2)
    {
        multi = (card_s[i] - '0') * 2;
        if (multi > 9)
        {
            int aux = sum_digits(multi);
            multi = aux;
        }
        sum += multi;
    }

    // Step 2 of verification
    int sum_aux;
    int sum2 = 0;
    for (int i = card_len - 1; i >= 0; i -= 2)
    {
        sum_aux = card_s[i] - '0';
        sum2 += sum_aux;
    }
    int total = sum + sum2;

    if ((total % 10) == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int main(void)
{
    // Ask user to input the card number
    long card;
    card = get_long("Number: \n");

    // Get the card length
    int len = get_card_len(card);

    // Transform card number into string
    char card_s[len];
    snprintf(card_s, len + 1, "%ld", card);
    int s1 = card_s[0];
    int s2 = card_s[1];

    // Call the Luhn validation function
    int validation = validator(card);

    if (validation == 0 && card_s[0] == '4' && (len == 16 || len == 13))
    {
        printf("VISA\n");
    }

    else if (len == 15 && validation == 0 && (s1 == '3' && (s2 == '4' || s2 == '7')))
    {
        printf("AMEX\n");
    }

    else if (len == 16 && validation == 0 && (s1 == '5' && (s2 == '1' || s2 == '2' || s2 == '3' || s2 == '4' || s2 == '5')))
    {
        printf("MASTERCARD\n");
    }

    else
    {
        printf("INVALID\n");
    }
}
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    /* American Express: 15 Digits, starts with 34, 37
    MasterCard: 16 d, 51, 52, 53, 54, 55
    Visa: 13 || 16 d, starts with 4 */

    long num = get_long("Number: ");

    int sum = 0;
    long cnum = num;
    bool altDigit = false;
    while (cnum > 0)
    {
        if (altDigit)
        {
            long ldm = (cnum % 10) * 2;
            while (ldm > 0)
            {
                int total = 0;
                total += ldm % 10;
                sum += total;
                ldm /= 10;
            }
            altDigit = false;
        }
        else
        {
            sum += cnum % 10;
            altDigit = true;
        }
        cnum /= 10;
    }


    int ct = 0;
    cnum = num;
    while (cnum > 0)
    {
        cnum /= 10;
        ct++;
    }

    int c = 1;
    int fn, fnn;
    cnum = num;
    while (cnum > 0)
    {
        if (c == ct - 1)
        {
            fnn = cnum % 10;
            int t = cnum / 10;
            fnn += t * 10;
        }
        else if (c == ct)
        {
            fn = cnum;
        }
        c++;
        cnum /= 10;
    }

    if (sum % 10 != 0)
    {
        printf("INVALID\n");
    }
    else
    {
        if (ct == 15 && (fnn == 37 || fnn == 37))
        {
            printf("AMEX\n");
        }
        else if (ct == 16 && (fnn == 51 || fnn == 52 || fnn == 53 || fnn == 54 || fnn == 55))
        {
            printf("MASTERCARD\n");
        }
        else if ((ct == 13 || ct == 16) && fn == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }

}
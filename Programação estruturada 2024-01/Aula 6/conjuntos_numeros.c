#include <stdio.h>

int main()
{
    int v[] = {0, 2, 3, 5, 7}, v1[] = {1, 2, 7, 10, 15}, v2[5], tamv2 = 0, i, j;

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if ((v[i] != 0) && (v[i] == v1[j]))
            {
                v2[tamv2] = v[i];
                tamv2 = tamv2 + 1;
                break;
            }
        }
    }

    for (i = 0; i < tamv2; i++)
    {
        printf("%i ", v2[i]);
    }
    return 0;
}

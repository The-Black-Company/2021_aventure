#include "inc.h"

char *adv_strcat(const char *s1,
                 const char *s2)
{
    char *output;
    size_t i;
    size_t len;
    size_t lens1;

    lens1 = adv_strlen(s1);
    len = lens1 + adv_strlen(s2) + 1;
    output = malloc(sizeof(char) * len);
    for (i = 0; i < len; i = i + 1)
    {
        if (i < lens1)
            output[i] = s1[i];
        else
            output[i] = s2[i - lens1];
    }
    return (output);
}
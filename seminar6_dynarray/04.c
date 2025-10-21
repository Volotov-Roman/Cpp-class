#include <stdio.h>

int main() 
{
#if (defined(COUNT) == 0)
    printf("No count!\n");
#elif (COUNT > 100)
    printf("Count is too large!\n");
#elif (defined(REVERSE))
    for (int i = COUNT; i>0; i--)
        printf("%i ", i);
#else
    for (int i = 1; i<=COUNT; i++)
        printf("%i ", i);
#endif
}
#include <stdio.h>
#include <stdlib.h>

main()
{
    char students[10][12];
    float gpa[10] = { -1 };
    
    for(int i = 0; i < 10; i++)
        scanf(" %s %f", &students[i], &gpa[i]);
    
    for(int i = 0; i < 10; i++)
        if(gpa[i] > 3.0f)
            printf("%s \n", students[i]);
}

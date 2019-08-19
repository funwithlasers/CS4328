#include <stdio.h>
#include <string.h>

main()
{
    char names[10][12];
    int size = 0;
    //get input
    for(int i = 0; i < 10; i++)
    {
        if(scanf("%s", &names[i]) != EOF)
            size++;
    }
    //sort
    for(int i = 0; i < size; i++)
    {
        int min_i = i;
    
        for(int j = i + 1; j < size; j++)
            if(strcmp(names[j], names[min_i]) < 0)
                min_i = j;
        
        if(min_i != i)
        {
            //swap
            char temp[12];
            strcpy(temp, names[i]);
            strcpy(names[i], names[min_i]);
            strcpy(names[min_i], temp);
        }
    }
    //print
    for(int i = 0; i < size; i++)
        printf("%s \n", names[i]);
}

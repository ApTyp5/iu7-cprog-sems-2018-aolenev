#include "strIU7ng.h"

char* find_substrIU7ng(strIU7ng source, strIU7ng search)
{
    char *p1, *p2, *p3, *p4;
    
    int i = 0, j = 0;

    if (search.head == NULL || source.head == NULL)
    {
        return NULL;
    }
    if (search.len == 0 || source.len == 0)
    {
        return NULL;
    }
    if (search.len > source.len)
    {
        return NULL;
    }
    
    p1 = source.head;
    p2 = search.head;

    for (i = 0; i < source.len; i++)
    {
        if (*p1 == *p2)
        {
            p3 = p1;
            p4 = p1;
            
            for (j = 0; j < search.len; j++)
            {
                if (*p3 == *p2)
                {
                    p3++;
                    p2++;
                } 
                else
                    break;
            }
            
            p2 = search.head;
            
            if (j == search.len)
            {
                return p4;
            
            }
        }
        
        p1++; 
    }
    return NULL;
}


        

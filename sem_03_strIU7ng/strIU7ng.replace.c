#include <stdlib.h>
#include "strIU7ng.h"

strIU7ng replace(strIU7ng source, strIU7ng search, strIU7ng replace)
{
    char *find = NULL;
    char *beg = NULL;
    char *end = NULL;
    int n;
    int l;
    char *new = NULL;

    if (strcmp(search.head, replace.head) == 0)
        return source;
    
    if (source.len < 0 || source.head == NULL)
        return source;
    
    if (search.len < 0 || search.head == NULL)
        return source;
    
    if (replace.len < 0 || replace.head == NULL)
        return source;
    
    find = find_substrIU7ng(source, search);
    
    while (find != NULL)
    {
        beg = malloc((source.head - find) * sizeof(char));
        
        for (int i = 0; i < source.head - find; i++)
        {
            beg[i] = source.head[i];
        }
        
        n = source.len - (source.head - find) - search.len;
        end = malloc(n * sizeof(char));
        
        if (!end)
        {
            free(beg);
            return source;
        }
        
        for (int i = 0; i < n; i++)
        {
            end[i] = (find + search.len)[i];
        }
        
        l = source.len + (replace.len - search.len);
        
        new = malloc((l + 1) * sizeof(char));
        
        if (!new)
        {
            free(end);
            free(beg);
            return source;
        }
        
        for (int i = 0; i < source.head - find; i++)
        {
            new[i] = beg[i];
        }
        
        for (int i = 0; i < replace.len; i++)
        {
            new[i + source.head - find] = replace.head[i];
        }
        
        for (int i = 0; i < n; i++)
        {
            new[i + source.head - find + replace.len] = end[i];
        }
        
        new[l] = '\0';
        
        source = strIU7ng_create(new);
        
        find = find_substrIU7ng(source, search);
        
        free(new);
        free(end);
        free(beg);
    }
    
    return source;
}
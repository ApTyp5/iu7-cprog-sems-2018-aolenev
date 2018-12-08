#include <stdlib.h>
#include <stdio.h>
#include "weather.h"
wether_data *parse(FILE* data)
{ 
    wether_data* elem;
    elem = (weather_data *)malloc(sizeof(weather_data));
    if( elem == NULL)
    {
        return NULL;
    }

    if (fscanf(data, "%d %d %d %d %d", &(elem->year), &(elem->month), &(elem->day), \
    &(elem->tmax_day, &(elem->tmax_night) != 5)
    {
        return NULL;
    }

    return elem;
}
#include <stdlib.h>
#include <stdio.h>
#include "weather.h"
weather_data *parse(FILE* data)
{ 
    weather_data* elem;
    elem = (weather_data *)malloc(sizeof(weather_data));
    if( elem == NULL)
    {
        return NULL;
    }

    if (fscanf(data, "%d %d %d %d %d", &(elem->year), &(elem->month), &(elem->day), \
    &(elem->tmax_day), &(elem->tmax_night)) != 5)
    {
        return NULL;
    }

    return elem;
}
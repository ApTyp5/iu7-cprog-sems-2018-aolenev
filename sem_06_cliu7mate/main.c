#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "list.h"
#include "weather.h"

#define CITIES_COUNT 3

int main()
{
    struct berkly_head *my_awesome_city = malloc(sizeof(my_awesome_city));
    assert(my_awesome_city != NULL);

    weather_data *my_awesome_weather = NULL;
    char *files[] = {
        "EKB.csv",
        "SPB.csv",
        "STC.csv",
    };

    FILE *file = NULL;
    for (int i = 0; i < CITIES_COUNT; i++)
    {
        file = fopen(files[i], "r");
        assert(file != NULL);

        INIT_LIST_HEAD(my_awesome_city);

        while ((my_awesome_weather = parse(file)) != NULL)
        {
            struct berkly_head *new_awesome_node = malloc(sizeof(new_awesome_node));
            assert(new_awesome_node);
            push_back(new_awesome_node, my_awesome_city);

            my_awesome_weather->node = new_awesome_node;
            my_awesome_weather->city = files[i];
        }

        assert(fclose(file) != EOF);
    }

    //do some activity with list...

    // TODO:free list
    struct berkly_head *iterator = my_awesome_city;
    struct berkly_head *saver = NULL;
    weather_data *member = NULL;

    list_for_each_safe(iterator, saver, my_awesome_city)
    {
        member = list_entry(iterator, weather_data, node);
        free(member);
    }

    return 0;
}

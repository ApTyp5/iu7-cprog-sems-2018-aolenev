typedef struct 
 {
    char* city;
    int year;
    int day;
    int month;
    int tmax_day;
    int tmax_night;
    struct berkly_head *node;
 } weather_data; 
weather_data *parse(FILE* data);


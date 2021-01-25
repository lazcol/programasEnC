#include <stdlib.h>
#include <stdio.h>

global const char* line[]= "{ "cod": "200", "message": 0, "cnt": 1, "list": [{ "dt": 1595462400, "main": { "temp": 15.02, "feels_like": 15.02, "temp_min": 14.87, "temp_max": 15.02, "pressure": 1011, "sea_level": 1012, "grnd_level": 1007, "humidity": 94, "temp_kf": 0.15 }, "weather": [{ "id": 500, "main": "Rain", "description": "light rain", "icon": "10n" }], "clouds": { "all": 95 }, "wind": { "speed": 1.83, "deg": 300 }, "visibility": 10000, "pop": 0.27, "rain": { "3h": 0.15 }, "sys": { "pod": "n" }, "dt_txt": "2020-07-23 00:00:00" }], "city": { "id": 3435910, "name": "Buenos Aires", "coord": { "lat": -34.6132, "lon": -58.3772 }, "country": "AR", "population": 1000000, "timezone": -10800, "sunrise": 1595415243, "sunset": 1595451933 } }";

int main()
{
    int i;
    for (i=0;i<100;i++)
        printf("%s",line[i]);
    return 0;
}
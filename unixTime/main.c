#include "utcTimeParse.h"

//open weather map api key 
char apiKey[]= "860540b295153b4d5daec5e11b5311e0"; 
//the city you want the weather for 
char location[]= "buenos aires,AR"; 
int status = WL_IDLE_STATUS; 
char server[] = "api.openweathermap.org";     

void getWeather(void);

void loop() 
{ 
 getWeather(); 
 delay(5000); 
} 
void getWeather() { 
 printf("\nStarting connection to server..."); 
 // if you get a connection, report back via serial: 
 if (client.connect(server, 80)) { 
   printf("connected to server"); 
   // Make a HTTP request: 
   client.print("GET /data/2.5/forecast?"); 
   client.print("q="+location); 
   client.print("&appid="+apiKey); 
   client.print("&cnt=0"); 
   client.println("&units=metric"); 
   client.println("Host: api.openweathermap.org"); 
   client.println("Connection: close"); 
   client.println(); 
 } else { 
   Serial.println("unable to connect"); 
 } 
 delay(1000); 
 String line = ""; 
 while (client.connected()) { 
   line = client.readStringUntil('\n'); 
   //Serial.println(line); 
   Serial.println("parsing Values"); 
   //create a json buffer where to store the json data 
   StaticJsonBuffer<5000> jsonBuffer; 
   JsonObject& root = jsonBuffer.parseObject(line); 
   if (!root.success()) { 
     //Serial.println("parseObject() failed"); 
     //Serial.println(line); 
     return; 
   } 
 //get the data from the json tree 
// String nextWeatherTime0 = root["list"][0]["dt_txt"]; 
// String nextWeather0 = root["list"][0]["weather"][0]["main"]; 
 String message = root["message"]; 
 String temp = root["list"][0]["main"][0]["temp"]; 
  // Print values. 
 Serial.println(message); 
 Serial.println(temp); 
 } 
} 
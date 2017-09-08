/*
 * 
 * Libaries
 * 
 */

#include <SNTPtime.h>
#define DEBUG_ON

/*
 * 
 * Constants
 * 
 */

int relay_1 = D1;
int relay_2 = D2;


SNTPtime NTPch("at.pool.ntp.org");   // Choose server pool as required
char *ssid      = "1234";               // Set you WiFi SSID
char *password  = "5678";               // Set you WiFi password


/*
   The structure contains following fields:
   struct strDateTime
   {
   byte hour;
   byte minute;
   byte second;
   int year;
   byte month;
   byte day;
   byte dayofWeek;
   boolean valid;
   };
 */
strDateTime dateTime;

void setup() {
        Serial.begin(115200);
        Serial.println();
        Serial.println("Booted");
        Serial.println("Connecting to Wi-Fi");

        WiFi.mode(WIFI_STA);
        WiFi.begin (ssid, password);
        while (WiFi.status() != WL_CONNECTED) {
                Serial.print(".");
                delay(500);
        }
        Serial.println();
        Serial.println("WiFi connected");

        while (!NTPch.setSNTPtime()) Serial.print("."); // set internal clock
        Serial.println();
        Serial.println("Time set");
}

void loop() {

        // first parameter: Time zone; second parameter: 1 for European summer time; 2 for US daylight saving time (not implemented yet)
        dateTime = NTPch.getTime(1.0, 1); // get time from internal clock
        NTPch.printDateTime(dateTime);
       

        byte actualHour = dateTime.hour;
        byte actualMinute = dateTime.minute;
        byte actualsecond = dateTime.second;
        int actualyear = dateTime.year;
        byte actualMonth = dateTime.month;
        byte actualday = dateTime.day;
        byte actualdayofWeek = dateTime.dayofWeek;
        delay(5000);
}

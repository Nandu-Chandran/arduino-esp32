#include <DHT.h>
#include <LiquidCrystal.h>
#define DHTPIN 8

// Set DHT type, uncomment whatever type you're using!
#define DHTTYPE DHT11   // DHT 11 
// Initialize DHT sensor for normal 16mhz Arduino:
DHT dht = DHT(DHTPIN, DHTTYPE);
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int screenWidth = 16;
int screenHeight = 2;
String a,b;
String line2 = "High Humidity. Lower fan speed";
// line2 = static
//String line2 = " Whizzzkid Inc. ";
String data;
// just some reference flags
int stringStart, stringStop = 0;
int scrollCursor = screenWidth;



void setup() {
  dht.begin();
  lcd.begin(screenWidth,screenHeight);
}

void loop() {
  
  delay(1000);
  float h = dht.readHumidity();
  // Read the temperature as Celsius:
  float t = dht.readTemperature();
  // Read the temperature as Fahrenheit:
  float f = dht.readTemperature(true);
  
  // Check if any reads failed and exit early (to try again):
  if (isnan(h) || isnan(t) || isnan(f)) {
    lcd.print("Failed to read from DHT sensor!");
    return;
  }
  
  lcd.clear();
  lcd.setCursor(0,0);
  data=(String)"T:"+t+" H:"+h+"%";
  //lcd.print(data);
  if(h<30){
    
    lcd.setCursor(0,1);
    lcd.print("Low Humidity");
  }
  else if(h>30&&h<60){
    lcd.setCursor(0,1);
    lcd.print("Comfortable Humidity");
  }
  else if(h>60){
    lcd.setCursor(0,1);
    //lcd.print("High Humidity. Lower fan speed");
    scroll();
  }
  else;
}

void scroll() {
  lcd.setCursor(scrollCursor, 0);
  lcd.print(line2.substring(stringStart,stringStop));
  lcd.setCursor(0, 1);
  lcd.print(data);
  delay(1000);
  lcd.clear();
  if(stringStart == 0 && scrollCursor > 0){
    scrollCursor--;
    stringStop++;
  } else if (stringStart == stringStop){
    stringStart = stringStop = 0;
    scrollCursor = screenWidth;
  } else if (stringStop == line2.length() && scrollCursor == 0) {
    stringStart++;
  } else {
    stringStart++;
    stringStop++;
  }
}

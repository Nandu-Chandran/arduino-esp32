// it's a 16x2 LCD so...
int screenWidth = 16;
int screenHeight = 2;

// the two lines
// line1 = scrolling
String line1 = "This is a line scrolling tutorial by whizzzkid!";
// line2 = static
String line2 = " Whizzzkid Inc. ";

// just some reference flags
int stringStart, stringStop = 0;
int scrollCursor = screenWidth;


void loop() {
  lcd.setCursor(scrollCursor, 0);
  lcd.print(line1.substring(stringStart,stringStop));
  lcd.setCursor(0, 1);
  lcd.print(line2);
  delay(300);
  lcd.clear();
  if(stringStart == 0 && scrollCursor > 0){
    scrollCursor--;
    stringStop++;
  } else if (stringStart == stringStop){
    stringStart = stringStop = 0;
    scrollCursor = screenWidth;
  } else if (stringStop == line1.length() && scrollCursor == 0) {
    stringStart++;
  } else {
    stringStart++;
    stringStop++;
  }
}

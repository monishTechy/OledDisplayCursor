
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
 int curx=64,cury=32;

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for SSD1306 display connected using software SPI (default case):
#define OLED_MOSI   9
#define OLED_CLK   10
#define OLED_DC    11
#define OLED_CS    12
#define OLED_RESET 13
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT,OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

void setup()   {                
  // On my display, I had to used 0x3C as the address, something to do with the RESET not being
  // connected to the Arduino. THe 0x3D address below is the address used in the original
  // Adafruit OLED example 
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3D);  // initialize with the I2C addr 0x3D (for the 128x64)
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(7,INPUT);//BUTTON
  display.clearDisplay(); // Make sure the display is cleared
  display.setTextSize(2);
  display.setCursor(23,8);
  display.setTextColor(WHITE);
  display.print("WELCOME");
  display.setCursor(0,33);
  display.setTextSize(1);
  
  display.print("   Please Subscribe! ");
  display.display();
  delay(4000);
  display.clearDisplay();
}
int x,y,b;


void loop() { 
  display.clearDisplay(); // Make sure the display is cleared
  

 x=analogRead(A0);
 y=analogRead(A1);
 Serial.print(curx);
 Serial.print("  ");
 Serial.print(cury);
 Serial.print("  ");
 Serial.println(b);


b=digitalRead(7);
display.clearDisplay();
 display.setTextColor(WHITE);
 display.setTextSize(2);
 if(x==0){
 curx-=1;}
 if(x==1023)
 {curx+=1;
  }
  if(y==0)
  cury-=1;
  if(y==1023)
  cury+=1;
 
 display.setCursor(curx,cury);
 
 display.print("+");
 
 display.display();
  
  
}

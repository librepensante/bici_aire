#include <SPI.h>
#include <Adafruit_GFX.h>
#include <TFT_ILI9163C.h>
//#include <TrueRandom.h>


/*
SCK -> 13 (cannot change this)
SDA -> 11 (cannot change this)
A0(DC) -> 9 (you can change but not all pins are usable, see library)
CS -> 10 (you can change but not all pins are usable, see library)
RESET -> 8 (any pin, you can also avoid, check library .h)
 */
#define __CS 10
#define __DC 9
#define __RST 8


TFT_ILI9163C display = TFT_ILI9163C(__CS, __DC, __RST);
void setup(void) {
  display.begin();
    pinMode(6, OUTPUT);
     analogWrite(6,180);
    
}
int data;
int color;
void loop() {
  data=analogRead(A0);
  int co2=map(data, 0, 1023, 10, 1000);
  if (co2<20){
     color=0x265F; //blue
   }else if(co2>20&&data<50){
     color=0x640;//green
   }else if(co2>50&&data<70){
     color = 0xDFEE; //lime
   }else if(co2>70&&data<100){
     color = 0xFFE7; //YELLOW
   }else if(co2>100&&data<200){
     color = 0xFE21; //ORANGE
   }else if(co2>200&&data<800){
     color = 0xF841; //RED
   }else if(co2>800){
    color =0x5000;
   }
  display.setCursor(5,10);   
  display.clearScreen(color);   
  display.setTextSize(1);
   display.println("CO(2) en el ambiente:");  
     display.setCursor(5,40);  
   display.setTextSize(3);
   display.print(co2);
    display.setTextSize(2);
  display.println(" ppm");
   delay(1000);
  
}

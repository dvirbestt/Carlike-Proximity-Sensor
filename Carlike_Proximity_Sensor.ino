
int latchPin = 11;      // (11) ST_CP [RCK] on 74HC595
int clockPin = 9;      // (9) SH_CP [SCK] on 74HC595
int dataPin = 12;     // (12) DS [S1] on 74HC595
byte leds = 0;


void updateShiftRegister()
{
   digitalWrite(latchPin, LOW);
   shiftOut(dataPin, clockPin, LSBFIRST, leds);
   digitalWrite(latchPin, HIGH);
}

void setup() 
{
  //Enable 74HC595 pins
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
}

void loop() 
{
  //Sends An UltraSonic Pulse

  bitSet(leds, 0);
  updateShiftRegister();

  //Finish The Pulse and starts to listen
  leds = 0;
  updateShiftRegister();
  int dis = (pulseIn(3,HIGH)/2 /29);

  //Enable Red And Buzzer When distance is fewer then 10cm
  if(dis < 10){
    bitSet(leds,5);
    updateShiftRegister();
  }

  //Enable Green When distance is fewer then 20cm
  if(dis < 20){
    bitSet(leds,6);
    updateShiftRegister();
  }

  //Enable Blue When distance is fewer then 40cm
  if(dis < 40){
    bitSet(leds,7);
    updateShiftRegister();
  }

  delay(100);
  

}

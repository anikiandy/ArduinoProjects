    #include <FastLED.h>
    #define NUM_LEDS 150
    #define DATA_PIN 8
    CRGB leds[NUM_LEDS];
    //variables for colors
    int pink[3] = {105,255,150};
    int purple[3] = {149,255,150};
    int green[3] = {1,255,190};
    int grellow[3] = {70, 255,190};
    int iceBlue[3] = { 200, 200, 150};
    int teal[3] = {215, 200,150};
    int off[3] = {0,0,0};
void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  Serial.begin(9600);

}

void loop() {
  //generate random color array
  int rando [3] = {random(1,255), random(1,255), 240};
//spoolUp(pink);//magenta
//spoolUp(purple);
Serial.print("Spoolup");
//spoolUp(teal, NUM_LEDS);
Serial.print("randcolor");
colors();
randomSpool(5, NUM_LEDS);
pingPong(2, purple,teal);
pingPong(2,pink,off);
ampUp(rando, 20);


}

void spoolUp (int colors[3], int spoolToo)//spool up will fill the pixel array one pixel at a time
{
  for (int i = 0 ; i < spoolToo; i++)
{
  leds[i] = CHSV(colors[0],colors[1],colors[2]);//magenta
  FastLED.show();
 
}
}

void spoolDown(int colors[3], int startFrom)
{
  for (int i = startFrom; i > 0; i--)
  {
    leds[i] = CHSV(colors[0], colors[1], colors[2]);
    FastLED.show();
    
  }
}

void ampUp(int color[3], int amplitude)
{
  if (amplitude <= NUM_LEDS)
  {
    spoolUp(color, amplitude);
    spoolDown(off ,amplitude);
    ampUp(color, amplitude + 20);
  }
  
}
void randomSpool(int n, int spoolToo)
{
  for (int i = 0; i < n; i++)
  {
    int randomColor[3]= {random(1,190), random(100,255),150};
    spoolUp(randomColor, NUM_LEDS);
  }
}

void rand3num(int c1[3], int c2[3], int c3[3],int cyc)
{
  int color;
  for (int cycles = 0; cycles < cyc; cycles++)
  {
    Serial.print("im here");
    for(int i = 0; i < NUM_LEDS; i++)
    {
      Serial.print("hi");
      color = random(1,4);
      if (color == 1) leds[i] = CHSV(c1[0], c1[1], c1[2]);
      else if (color == 2 ) leds[i]= CHSV(c2[0], c2[1], c2[2]);
      else leds[i] = CHSV (c3[0], c3[1], c3[2]);
      
    }
    FastLED.show();
    delay(10);
  }
}
void pingPong(int balls, int color[3],int fillColor[3])
{
  for (int cycle = 0 ; cycle < balls; cycle++)
  {
    for (int i = 0; i < NUM_LEDS; i++)//ping out
    {
      leds[i] = CHSV(color[0], color[1], 200);
      if (i>=1) leds[i-1] = CHSV(color[0],color[1],150);
       if (i >=2) leds[i-2] = CHSV(color[0], color[1],100);
       if (i >= 3) leds[i-3] = CHSV(color[0], color[1],50);
       if (i>=4) leds[i -4] = CHSV(color[0], color[1], 25);
       if (i>=5) leds[i-5] = CHSV(fillColor[0],fillColor[1],fillColor[2]);
      FastLED.show();
      delay(10);
      
    }//end the ping out
    for (int i = NUM_LEDS; i > 0; i--)//ping out
    {
      leds[i] = CHSV(color[0], color[1], 150);
      if (i<=NUM_LEDS -1) leds[i+1] = CHSV(color[0],color[1],150);
       if (i <=NUM_LEDS-2) leds[i+2] = CHSV(color[0], color[1],100);
       if (i <= NUM_LEDS-3) leds[i+3] = CHSV(color[0], color[1],50);
       if (i<=NUM_LEDS - 4) leds[i +4] = CHSV(color[0], color[1], 25);
       if (i<=NUM_LEDS-5) leds[i+5] = CHSV(fillColor[0],fillColor[1],fillColor[2]);
      FastLED.show();
      delay(10);
      
    }//end the ping in
  }//end ping pong cycle count
}//end pingpong function

void colors()
{
  for (int n = 0 ; n <10 ; n++){
  for (int i = 0; i< NUM_LEDS; i++)
  {
    leds[i] = CHSV(rand()%255, rand()%255, 150);
  }
  FastLED.show();
  delay(100);
  }
  
}

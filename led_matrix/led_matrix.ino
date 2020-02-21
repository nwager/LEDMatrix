#include <FastLED.h>

// possible ideas:

// result = pgm_read_byte(&gamma8[input]);
const uint8_t PROGMEM gamma8[] = {
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1,
    1,  1,  1,  1,  1,  1,  1,  1,  1,  2,  2,  2,  2,  2,  2,  2,
    2,  3,  3,  3,  3,  3,  3,  3,  4,  4,  4,  4,  4,  5,  5,  5,
    5,  6,  6,  6,  6,  7,  7,  7,  7,  8,  8,  8,  9,  9,  9, 10,
   10, 10, 11, 11, 11, 12, 12, 13, 13, 13, 14, 14, 15, 15, 16, 16,
   17, 17, 18, 18, 19, 19, 20, 20, 21, 21, 22, 22, 23, 24, 24, 25,
   25, 26, 27, 27, 28, 29, 29, 30, 31, 32, 32, 33, 34, 35, 35, 36,
   37, 38, 39, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 50,
   51, 52, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 66, 67, 68,
   69, 70, 72, 73, 74, 75, 77, 78, 79, 81, 82, 83, 85, 86, 87, 89,
   90, 92, 93, 95, 96, 98, 99,101,102,104,105,107,109,110,112,114,
  115,117,119,120,122,124,126,127,129,131,133,135,137,138,140,142,
  144,146,148,150,152,154,156,158,160,162,164,167,169,171,173,175,
  177,180,182,184,186,189,191,193,196,198,200,203,205,208,210,213,
  215,218,220,223,225,228,231,233,236,239,241,244,247,249,252,255 };

const int LED_PIN = 4;
const int NUM_LEDS = 64;

CRGB led[NUM_LEDS];

const uint32_t heart_data[2][64] = {
{
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0xff6500ff, 0xff6500ff, 0x00000000, 0x00000000, 0xff6500ff, 0xff6500ff, 0x00000000, 
0xff6500ff, 0xff00e1ff, 0xff00e1ff, 0xff6500ff, 0xff6500ff, 0xff00e1ff, 0xff00e1ff, 0xff6500ff, 
0xff6500ff, 0xff00e1ff, 0xff00e1ff, 0xff00e1ff, 0xff00e1ff, 0xff00e1ff, 0xff00e1ff, 0xff6500ff, 
0x00000000, 0xff6500ff, 0xff00e1ff, 0xff00e1ff, 0xff00e1ff, 0xff00e1ff, 0xff6500ff, 0x00000000, 
0x00000000, 0x00000000, 0xff6500ff, 0xff00e1ff, 0xff00e1ff, 0xff6500ff, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0xff6500ff, 0xff6500ff, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
},
{
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xff6500ff, 0x00000000, 0x00000000, 0xff6500ff, 0x00000000, 0x00000000, 
0x00000000, 0xff6500ff, 0xff6500ff, 0xff6500ff, 0xff6500ff, 0xff6500ff, 0xff6500ff, 0x00000000, 
0x00000000, 0xff6500ff, 0xff00b3e1, 0xff00b3e1, 0xff00b3e1, 0xff00b3e1, 0xff6500ff, 0x00000000, 
0x00000000, 0xff6500ff, 0xff6500ff, 0xff00b3e1, 0xff00b3e1, 0xff6500ff, 0xff6500ff, 0x00000000, 
0x00000000, 0x00000000, 0xff6500ff, 0xff6500ff, 0xff6500ff, 0xff6500ff, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0xff6500ff, 0xff6500ff, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
},
};

static const uint32_t junimo_data[1][64] = {
{
0xffbb8a00, 0xffbb8a00, 0xffbb8a00, 0xffbb8a00, 0xff000000, 0xffbb8a00, 0xffbb8a00, 0xffbb8a00, 
0xffbb8a00, 0xffbb8a00, 0xff2f8e69, 0xff2f8e69, 0xff000000, 0xff2f8e69, 0xffbb8a00, 0xffbb8a00, 
0xffbb8a00, 0xff2f8e69, 0xff50bd92, 0xff50bd92, 0xff000000, 0xff50bd92, 0xff2f8e69, 0xffbb8a00, 
0xff2f8e69, 0xff50bd92, 0xff50bd92, 0xff50bd92, 0xff50bd92, 0xff50bd92, 0xff50bd92, 0xff2f8e69, 
0xff2f8e69, 0xff50bd92, 0xff000000, 0xff50bd92, 0xff50bd92, 0xff000000, 0xff50bd92, 0xff50bd92, 
0xff50bd92, 0xffcb90ff, 0xffcb90ff, 0xff50bd92, 0xff50bd92, 0xffcb90ff, 0xffcb90ff, 0xff50bd92, 
0xffbb8a00, 0xff2f8e69, 0xff50bd92, 0xff50bd92, 0xff50bd92, 0xff50bd92, 0xff2f8e69, 0xffbb8a00, 
0xffbb8a00, 0xffbb8a00, 0xff000000, 0xffbb8a00, 0xffbb8a00, 0xff000000, 0xffbb8a00, 0xffbb8a00
}
};

// frames of heart piskel
uint8_t* heart0 = (uint8_t*) heart_data[0];
uint8_t* heart1 = (uint8_t*) heart_data[1];

// other piskel
uint8_t* junimo = (uint8_t*) junimo_data[0];

// ema brightness control
const int POT_PIN = 4;
uint8_t sensorValue = 0;    //initialization of sensor variable, equivalent to EMA Y
float EMA_a = 0.1;          //initialization of EMA alpha
uint8_t EMA_S = 0;          //initialization of EMA S

// noise stuff; see FastLed docs
// https://github.com/FastLED/FastLED/blob/master/examples/Noise/Noise.ino
uint8_t noise [8][8];

// The 32bit version of our coordinates
static uint16_t noisex;
static uint16_t noisey;
static uint16_t noisez;
// uint16_t speed = 1; // almost looks like a painting, moves very slowly
uint16_t noisespeed = 2; // a nice starting speed, mixes well with a scale of 100

// uint16_t speed = 33;
// uint16_t speed = 100; // wicked fast!
// uint16_t scale = 1; // mostly just solid colors
// uint16_t scale = 4011; // very zoomed out and shimmery
uint16_t scale = 4011;
// end of noise stuff


// pickup pins
const int dbridge = 12;     // bridge pickup
const int dmiddle = 11;     // middle pickup
const int dneck = 10;       // neck pickup

int pupState = 1; // pickup switch position 1-5, changed by checkPup

void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(led, NUM_LEDS);
  FastLED.clear();
  FastLED.show();

  EMA_S = map(analogRead(POT_PIN), 0, 1023, 0, 255);  //set EMA S for t=1

  // Initialize our coordinates to some random values
  noisex = random16();
  noisey = random16();
  noisez = random16();

  pinMode(dbridge, INPUT);
  pinMode(dmiddle, INPUT);
  pinMode(dneck, INPUT);
  
  Serial.begin(9600);
  
}

void loop() {
  sensorValue = map(analogRead(POT_PIN), 0, 1023, 0, 255);    //read the sensor value using ADC
  EMA_S = (EMA_a*sensorValue) + ((1-EMA_a)*EMA_S);            //run the EMA
  checkPup();

  if (pupState == 1) {
    drawHeart();
  } else if (pupState == 2) {
    drawFrame(junimo);
  } else if (pupState == 3) {
    gradient();
  } else if (pupState == 4) {
    pulse(CRGB(246, 196, 46), 40);
  } else {  // pupState == 5
    showNoise();
  }
}

void drawHeart() {
  static uint32_t oldTime = millis();
  static boolean toggle = true;
  if (millis() - oldTime > 1000) {
    oldTime = millis();
    toggle = !toggle;
  }
  if (toggle) {
      drawFrame(heart0);
  } else {
    drawFrame(heart1);
  }
}

void drawFrame(uint8_t* frame) {
  int offset = 0;
  for (int y = 0; y < 8; y++) { // 8 is number of rows
    for (int x = 0; x < 8; x++) { // 8 is number of columns
      int pixel = y * 8 + x; // 8 is image width

      uint8_t r = frame[offset + 0];
      uint8_t g = frame[offset + 1];
      uint8_t b = frame[offset + 2];

       // change brightness using gamma table
       r = setColor((uint8_t) (r * (EMA_S / 255.0)));
       g = setColor((uint8_t) (g * (EMA_S / 255.0)));
       b = setColor((uint8_t) (b * (EMA_S / 255.0)));
      
      offset += 4;

      led[pixel] = CRGB(r, g, b);
    }
  }
  FastLED.show();
}

void gradient() {
  for (int y = 0; y < 8; y++) {
    for (int x = 0; x < 8; x++) {
      int pixel = y * 8 + x; // 8 is image width
      led[pixel] = CHSV((uint8_t) (millis() / 25.0 + 2 * y + x), 255, setColor(255));
    }
  }
  FastLED.show();
}

void pulse(CRGB color, float frequency) {
  float wave = sin8(millis() / 1000.0 * frequency) * 2 / 3 + 85;
  for (int i = 0; i < NUM_LEDS; i++) {
    led[i].r = setColor((uint8_t) (color.r * wave / 255));
    led[i].g = setColor((uint8_t) (color.g * wave / 255));
    led[i].b = setColor((uint8_t) (color.b * wave / 255));
  }
  FastLED.show();
}

// used by showNoise
void fillnoise8() {
  for(int i = 0; i < 8; i++) {
    int ioffset = scale * i;
    for(int j = 0; j < 8; j++) {
      int joffset = scale * j;
      noise[i][j] = inoise8(noisex + ioffset, noisey + joffset, noisez);
    }
  }
  noisez += noisespeed;
}

void showNoise() {
  static uint8_t ihue = 0;
  fillnoise8();
  for(int y = 0; y < 8; y++) {
    for(int x = 0; x < 8; x++) {
      int pixel = y * 8 + x;
      // We use the value at the (x,y) coordinate in the noise
      // array for our brightness, and the flipped value from (y,x)
      // for our pixel's hue.
      //led[pixel] = CHSV(noise[x][y], 255, noise[x][y]);

      // You can also explore other ways to constrain the hue used, like below
      led[pixel] = CHSV(ihue + (noise[y][x]>>2), 255, noise[x][y]);
    }
  }
  ihue += 1;
  FastLED.setBrightness(EMA_S);
  FastLED.show();
}

uint8_t setColor(uint8_t input) {
  uint8_t color = (uint8_t) ((float) input * EMA_S / 255.0);
  return pgm_read_byte(&gamma8[color]);
}


void checkPup() {
  bool drneck = digitalRead(dneck);
  bool drmiddle = digitalRead(dmiddle);
  bool drbridge = digitalRead(dbridge);
  if (drneck == HIGH && drmiddle == LOW) {
    pupState = 5;
  } else if (drneck == HIGH && drmiddle == HIGH) {
    pupState = 4;
  } else if (drmiddle == HIGH && drbridge == LOW) {
    pupState = 3;
  } else if (drmiddle == HIGH && drbridge == HIGH) {
    pupState = 2;
  } else { // if (drmiddle == LOW && drbridge == HIGH)
    pupState = 1;
  }
}

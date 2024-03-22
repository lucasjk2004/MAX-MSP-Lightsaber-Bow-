#include <Adafruit_NeoPixel.h>

#define LED_COUNT 60
#define LED_PIN 2

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

int r, g, b;
String myString;

void setup() {
  Serial.begin(9600);
  pixels.begin();
}

void loop() {
  if (Serial.available()) {
    char received = Serial.read();
    myString += received;
    
    if (received == 'B') {
      int commaIndex = myString.indexOf(',');
      int secondCommaIndex = myString.indexOf(',', commaIndex + 1);
      
      if (commaIndex != -1 && secondCommaIndex != -1) {
        String firstValue = myString.substring(0, commaIndex);
        String secondValue = myString.substring(commaIndex + 1, secondCommaIndex);
        String thirdValue = myString.substring(secondCommaIndex + 1); 
        
        r = firstValue.toInt();
        g = secondValue.toInt();
        b = thirdValue.toInt();
        
        // Ensure values are within the valid range (0-255)
        r = constrain(r, 0, 255);
        g = constrain(g, 0, 255);
        b = constrain(b, 0, 255);
        
        Serial.print("Received RGB values: ");
        Serial.print(r);
        Serial.print(", ");
        Serial.print(g);
        Serial.print(", ");
        Serial.println(b);
        
        myString = "";
      } else {
        Serial.println("Error: Invalid input format");
      }
    }
  }
  
  for (int i = 0; i < LED_COUNT; i++) {
    pixels.setPixelColor(i, pixels.Color(r, g, b));
  }
  
  pixels.show();
}

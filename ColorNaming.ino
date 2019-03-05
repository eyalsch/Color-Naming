#include "ColorNaming.h"

void setup() {
  Serial.begin(9600);
  Serial.println(NameColor(180, 0, 0));
}

void loop() {
}

char *NameColor(byte R, byte G, byte B) {
  double MinDist = 3.0*256.0;
  int tempColor = 0;
  double CurrDist;

  for (int i = 0; i < NoColors; i++) {
    CurrDist = sqrt(pow(R - ColorCodeData[i].R, 2) + pow(G - ColorCodeData[i].G, 2) + pow(B - ColorCodeData[i].B, 2));
    Serial.print(i);
    Serial.print("\t");
    Serial.print(ColorCodeData[i].Name);
    Serial.print("\t");
    Serial.println(CurrDist);
    if (CurrDist < MinDist) {
      MinDist = CurrDist;
      tempColor = i;
    }
  }
  Serial.println(tempColor);
  return ColorCodeData[tempColor].Name;
}



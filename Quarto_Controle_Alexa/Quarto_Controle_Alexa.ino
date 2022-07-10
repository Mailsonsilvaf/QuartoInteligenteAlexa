#include "arduino_secrets.h"
#include "thingProperties.h"

//Objetos Alexa
const int ledVermelho = D7;
const int ledVerde = D6;
const int ledAzul = D5;
const int luzDia = D3;
const int luzSpot = D4;

// Controle remoto
#include <IRremoteESP8266.h>
#include <IRrecv.h>
IRrecv receptor(D4);
decode_results resultado;

//RECEPTOR IR
#define ligar 0xF7C03F
#define desligar 0xF740BF
#define brilhomenos 0xF7807F
#define brilhomais 0xF700FF
#define vermelho 0xF720DF
#define verde 0xF7A05F
#define azul 0xF7609F
#define branco 0xF7E01F
#define flash 0xF7D02F
#define strobe 0xF7F00F
#define smooth 0xF7E817
#define laranja mais 0xF710EF
#define laranja menos 0xF730CF
#define verde 0xF7906F
#define azulclaro 0xF7B04F
#define azulmais 0xF750AF
#define roxo 0xF7708F
#define spotmais 0xF708F7
#define spotmenos 0xF728D7
#define spoton 0xF7A857
#define spotoff 0xF76897


void setup() {

  Serial.begin(9600);

  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAzul, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(luzDia, OUTPUT);
  pinMode(luzSpot, OUTPUT);

  receptor.enableIRIn();

  delay(1500);

  initProperties(); // Defined in thingProperties.h

  ArduinoCloud.begin(ArduinoIoTPreferredConnection);// Connect to Arduino IoT Cloud

  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();

}

void loop() {

  ArduinoCloud.update(); //recebe os dados iot cloud

  //Recebe os dados do controle remoto
  if (receptor.decode(&resultado))
  {
    switch (resultado.value) {
      case ligar: digitalWrite(D8, HIGH); break;
      case desligar: digitalWrite(D8, LOW); break;
      //case vermelho : digitalWrite(Vermelho, HIGH); break;
      //case azul : digitalWrite(Azul, HIGH); break;
    }
    receptor.resume();

  }
}



void onLuzChange()  {
  

}


void onSpotChange()  {
  if (spot) {
    digitalWrite(luzSpot, HIGH);
  }
  else {
    digitalWrite(luzSpot, LOW);
  }
}

void onVermelhoChange()  {
  
  if (vermelho) {
    digitalWrite(ledVermelho, HIGH);
  }
  else {
    digitalWrite(ledVermelho, LOW);
  }
}

void onVerdeChange()  {

  if (verde) {
    digitalWrite(ledVerde, HIGH);
  }
  else {
    digitalWrite(ledVerde, LOW);
  }
}

void onAzulChange()  {
  
  if (azul) {
    digitalWrite(ledAzul, HIGH);
  }
  else {
    digitalWrite(ledAzul, LOW);
  }
}
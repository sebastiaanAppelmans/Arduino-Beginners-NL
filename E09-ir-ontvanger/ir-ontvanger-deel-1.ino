/*
 * Bas on Tech - IR ontvanger
 * Deze les is onderdeel van de lessen op https://arduino-lessen.nl
 *  
 * (c) Copyright 2018 - Bas van Dijk / Bas on Tech
 * Deze code en inhoud van de lessen mag zonder schriftelijke toestemming 
 * niet voor commerciele doeleinden worden gebruikt
 * 
 * YouTube:    https://www.youtube.com/c/BasOnTechNL
 * Facebook:   https://www.facebook.com/BasOnTechChannel
 * Instagram:  https://www.instagram.com/BasOnTech
 * Twitter:    https://twitter.com/BasOnTech
 * 
 * ---------------------------------------------------------------------------
 *  
 * Originele code van:
 * http://arcfn.com door Ken Shirriff
 *
 */

// Importeer de IR-remote bibliotheek
#include <IRremote.h>

int IrReceiverPin = 12;                 // stel de variable "IrReceiverPin" in op pin 12
IRrecv irrecv(IrReceiverPin);           // maak een nieuwe instantie van "irrecv" en sla deze op in de variabele "IRrecv"
decode_results results;                 // definieer de variable "results" om de ontvangen knop-code in op te slaan

void setup()
{
    Serial.begin(9600);                 // Stel de seriële monitor in

    pinMode(LED_BUILTIN, OUTPUT);       // Initialiseer digitale pin LED_BUILTIN als een uitvoer

    // Mocht de IR-remote bibliotheek vastlopen dan kunnen we dit aan de getoonde tekst zien
    Serial.println("IR-ontvanger wordt gestart...");

    irrecv.enableIRIn();                // start de IR-ontvanger

    Serial.println("IR-ontvanger actief");

    digitalWrite(LED_BUILTIN, LOW);     // Zet de ingebouwde LED uit
}


void loop() {

    // Als de IR-ontvanger een signaal heeft ontvangen
    if (irrecv.decode(&results)) {

        // Print de ontvangen waarde als hexadecimaal        
        Serial.println(results.value, HEX);

        // Laat de IR-ontvanger luisteren naar nieuwe signalen
        irrecv.resume();

        // Bepaal welke knop is ingedrukt
        switch (results.value) {
            case 0xFF42BD:  // knop *
                digitalWrite(LED_BUILTIN, HIGH);   // Zet LED aan
                break;

            case 0xFF52AD:  // knop #
                digitalWrite(LED_BUILTIN, LOW);    // Zet LED uit
                break;        
        }

    }
  
    delay(100);      // pauzeer 100ms
}
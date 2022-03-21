/*
  Titre      : clacier4x4 Arduino
  Auteur     : Cedric Yonta
  Date       : 21/03/2022
  Description: actionner une LED parmi avec un clavier 4x4 Arduino
  Version    : 0.0.1
  Sources : https://www.aranacorp.com/fr/utilisation-dun-clavier-numerique-4x4-avec-arduino/
*/




#include <Arduino.h>
#include "WIFIConnector_MKR1000.h"
#include "MQTTConnector.h"



//Libraries


#include <Keypad.h>//https://github.com/Chris--A/Keypad
//Constants
#define ROWS 4
#define COLS 4
//Parameters
const char kp4x4Keys[ROWS][COLS]  = {{'1', '2', '3', 'A'}, {'4', '5', '6', 'B'}, {'7', '8', '9', 'C'}, {'*', '0', '#', 'D'}};
byte rowKp4x4Pin [4] = {12, 9, 7, 6};
byte colKp4x4Pin [4] = {5, 4, 3, 2};



// constante de verification des entrees
const char GREENLED = 'A'; 
const char REDLED = 'B'; 
const char BLUELED = 'C';
const char YELLOWLED = 'D';

const char CONFIRMINTENSITE = '#'; 
const char CONFIRMLED = '*'; 


// variables
int compteur = 0;
int  intensiteled;
int ledpin = 17 ;
int valeurIntensite;

void readKp4x4();


Keypad kp4x4  = Keypad(makeKeymap(kp4x4Keys), rowKp4x4Pin, colKp4x4Pin, ROWS, COLS);
void setup() {
 
 
wifiConnect();                  //Branchement au réseau WIFI
  MQTTConnect();
 Serial.begin(9600);
 
}
void loop() {
 
  


 char val = kp4x4.getKey();


 if (val) {
         Serial.println(val);
         compteur = compteur+1;
         Serial.println(compteur);
    }
    
   switch (compteur)
    {
       case 1: // selection de la LED
              if (val == REDLED)
              {
                 ledpin = 0;
                
              }else if (val == GREENLED)
              {
                 ledpin = 10;
                
              }else if (val == BLUELED)
              {
                 ledpin = 8 ;
               
              }else if (val == YELLOWLED)
              {
                 ledpin = 1;
                
              }else
              {
                
              }
              

        break;
        case 2: // confirmation deu choix de la LED
               if (val == CONFIRMLED )
              {
                 Serial.println("led selectionné");
              } 
             
        break;
      case 3:   // entree de l'intensite de la LED
                if (val == '0'|| val == '1'||val == '2'||val == '3'||val == '4'||val == '5'||val == '6'||val == '7'||val == '8'||val == '9'  )
              {
                valeurIntensite = int (val) - '0' ;
               intensiteled = int (val) - '0'; 
               intensiteled = map(intensiteled, 0, 9, 0, 255 );
              } 
              
              
        
        break;
      case 4: // confirmation de l'intenite , actionnement de la LED et envois sur le serveur THingsboards
              if (val == CONFIRMINTENSITE )
                  {
                        Serial.println(" intensité selectionné");
                        pinMode(ledpin,OUTPUT);
                        analogWrite(ledpin,intensiteled);

                                      if (ledpin == 0)
                                  {
                                    appendPayload("redLED", valeurIntensite); 
                                    sendPayload(); 
                                  }
                                  else if (ledpin == 10)
                                  {
                                  appendPayload("greenLED", valeurIntensite);
                                  sendPayload(); 
                                  } else if (ledpin == 8)
                                  {
                                  appendPayload("blueLED", valeurIntensite);  
                                    sendPayload();
                                  } else if (ledpin == 1)
                                  {
                                    appendPayload("yellowLED", valeurIntensite);  
                                    sendPayload();
                                  }
                                  else
                                  {
                                    
                                  }
                       
                  } 
      break;

      case 5:
               if (val)
               { 
                  if (val == '0')
                  {
                    analogWrite(ledpin,0);
                    compteur = 0 ;
                    Serial.println(" Vous pouvez effectuer de nouveau l'operation");
                  }
                  
                 
               }
               
            
      break;
      default: 
      
        delay(500);
      break;
   
   
      
}

}
  




    

 





    

 

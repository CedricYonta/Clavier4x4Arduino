#include <Arduino.h>

//Libraries
#include <Keypad.h>//https://github.com/Chris--A/Keypad
//Constants
#define ROWS 4
#define COLS 4
//Parameters
const char kp4x4Keys[ROWS][COLS]  = {{'1', '2', '3', 'A'}, {'4', '5', '6', 'B'}, {'7', '8', '9', 'C'}, {'*', '0', '#', 'D'}};
byte rowKp4x4Pin [4] = {12, 9, 7, 6};
byte colKp4x4Pin [4] = {5, 4, 3, 2};

//int greenLed = 0 ;
//int redLed = 1 ;
int ledpin;

const char GREENLED = 'A'; 
const char REDLED = 'B'; 
const char BLUELED = 'C';
const char YELLOWLED = 'D';

const char CONFIRMINTENSITE = '#'; 
const char CONFIRMLED = '*'; 


int i =0;
 char t[4];
int compteur = 0;
void readKp4x4();

//Variables
Keypad kp4x4  = Keypad(makeKeymap(kp4x4Keys), rowKp4x4Pin, colKp4x4Pin, ROWS, COLS);
void setup() {
 //Init Serial USB
 

 Serial.begin(9600);
 //Serial.println(F("Initialize System"));

 /*pinMode(greenLed, OUTPUT);
 pinMode(redLed, OUTPUT);
 digitalWrite(greenLed,LOW);*/
}
void loop() {
 
 int  intensiteled ;


 char intensite = kp4x4.getKey();


 if (intensite) {
         Serial.println(intensite);
         compteur = compteur+1;
         Serial.println(compteur);
    }
    
   switch (compteur)
    {
       case 1: 
              if (intensite == REDLED)
              {
                 ledpin = 0;
                 pinMode(ledpin,OUTPUT);
              }else if (intensite == GREENLED)
              {
                 ledpin = 10;
                 pinMode(ledpin,OUTPUT);
              }else if (intensite == BLUELED)
              {
                 ledpin = 8 ;
                 pinMode(ledpin,OUTPUT);
              }else if (intensite == YELLOWLED)
              {
                 ledpin = 1;
                 pinMode(ledpin,OUTPUT);
              }else
              {
                
              }
              

        break;
        case 2: 
               if (intensite == CONFIRMLED )
              {
                 Serial.println("led selectionné");
              } 
             
        break;
      case 3:
              intensiteled = map(intensite, 0, 9, 0, 255);
               intensiteled = intensite;
               analogWrite(ledpin,intensite);
        
        break;
      case 4:
              if (intensite == CONFIRMINTENSITE )
                  {
                        Serial.println(" intensité selectionné");
                        digitalWrite(ledpin, intensiteled);
                  } 
      break;
      default: 
      delay(1000);
        //Serial.println("redemarrer le programme pour allumer une led");
    }
    

 /*if (intensite) {
         Serial.println(intensite);
      intensiteled = map(intensite, 0, 255, 0, 9);
        aWrite(greenLed,intensite);
    }*/
    

      


      /*f(key)  // Check for a valid key.
  {
    switch (key)
    {
      case '*':
        digitalWrite(ledpin, LOW);
        break;
      case '#':
        digitalWrite(ledpin, HIGH);
        break;
      default:
        Serial.println(key);
    }
  }*/
 
  /*if (choixled) {
    Serial.println(choixled); 
    if (i < 4 )
    {
      t[i] = choixled;
       Serial.println(t[i]); 
    }
    
  }
 i++;*/

  
    /* Serial.print("valeur ");
     Serial.print(n); 
    Serial.print(" :"); 
     Serial.println(customKey);*/
  

  

   /*char choixled = kp4x4.getKey();
 if (choixled) {
            if (choixled == INDIQGREENLED)
            {
              Serial.println(choixled);
              char confirmled = kp4x4.getKey();
                if (confirmled)
                {
                  if (confirmled == CONFIRMLED)
                  {
                    Serial.println(confirmled);
                    char intensite = kp4x4.getKey();
                    if (intensite)
                    {
                      Serial.println(intensite);
                      char confirmintensite = kp4x4.getKey();
                      if (confirmintensite)
                        {
                          if (confirmintensite == CONFIRMINTENSITE)
                          {
                              Serial.println(confirmintensite);
                              intensite = map(intensite, 0, 255, 0, 9);
                              digitalWrite(greenLed,intensite);
                          }
                          
                          
                        }
                    }
                    


                  }
                  
                  
                  
                    
                }
                
            }
      
    }*/
    

}

   
   

/*void readKp4x4() { /* function readKp4x4 */
 //// Read button states from keypad
 /*char choixled = kp4x4.getKey();
 if (choixled) {
            if (choixled == INDIQGREENLED)
            {
              Serial.println(choixled);
              char confirmled = kp4x4.getKey();
                if (confirmled)
                {
                  if (confirmled == CONFIRMLED)
                  {
                    Serial.println(confirmled);
                    char intensite = kp4x4.getKey();
                    if (intensite)
                    {
                      Serial.println(intensite);
                      char confirmintensite = kp4x4.getKey();
                      if (confirmintensite)
                        {
                          if (confirmintensite == CONFIRMINTENSITE)
                          {
                              Serial.println(confirmintensite);
                              intensite = map(intensite, 0, 255, 0, 9);
                              digitalWrite(greenLed,intensite);
                          }
                          
                          
                        }
                    }
                    


                  }
                  
                  
                  
                    
                }
                
            }
      
    }
    

 }*/

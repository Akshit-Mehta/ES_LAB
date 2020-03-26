 
#include<reg51.h>       //Includes SFR for 8051 which controls ports and other Functionalities 
                        // 8051 has 4 ports P1,P2,P3,P4
                        
#define KEYPAD_PORT  P1 //Keypad connected to Port1
    
#define CONTROL  P2     //Control assigned to Port2

#define DATA P3         //Data assigned to Port3

//control port2
sbit RS=P2^0;           //Register Select = Pin0 of Port2 , (RS =0 means cmd and 1 means Data)
sbit E=P2^1;            //Enable = Pin1 of Port2  (Falling edge triggered or -ve Edge triggered)

#include"delay.h"
#include"lcd.h"
#include"keypad.h"
#include"reg51.h"

void delay1()           //Delay function
{
int i;
for(i=0;i<=30000;i++);
}

void main(void)
{
  unsigned char key;
  init_lcd();                           //lcd init.
  cmd_lcd(0x80);                        //Set curser position
  string_lcd("Key : ");                 //Display string
  P0=0X00;                              //0 means no light  8 bit zero so no i/p goes to led
  while(1)
  {
    key = keyscan();                    //Scans the input character
    cmd_lcd(0xc0);                      //Position cursor to start of 2nd line
    /*
    *
    *   data_lcd(key);                  //Display pressed key on LCD
    *   P0=0X01;                        //01 = Selected 1st LED and light up that LED
	*	delay1();                       //Delay the program 
	*	break;
    *
    */
    switch(key){                        
      case '0':                         
            data_lcd(key);
        	P0=0X01;                    //01 = Selected 1st LED and light up that LED
		    delay1();
		    break;
      case '1':
            data_lcd(key);
        	P0=0X02;                    //02 = Selected 2nd LED and light up that LED
		    delay1();
		    break;				        
      case '2':
            data_lcd(key);
        	P0=0X04;                    //04 = Selected 3rd LED and light up that LED
		    delay1();
		    break;				        
      case '3':
            data_lcd(key);  
        	P0=0X08;                    //08 = Selected 4th LED and light up that LED
		    delay1();
		    break;				      
      case '4':
            data_lcd(key);
        	P0=0X10;                    //10 = Selected 5th LED and light up that LED
		    delay1();
		    break;				       
      case '5':                         //COMPLETE REST OF THE CASES
            data_lcd(key);
        	P0=0X20;                    //20 = Selected 6th LED and light up that LED
		    delay1();
		    break;      
      case '6':
            data_lcd(key);
        	P0=0X40;                    //40 = Selected 7th LED and light up that LED
		    delay1();
		    break;				        
      case '7':
            data_lcd(key);
        	P0=0X80;                    //80 = Selected 8th LED and light up that LED
		    delay1();
		    break;				        
      default:
            data_lcd(key); 
        	break;
  }
 }
}
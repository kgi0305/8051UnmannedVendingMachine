#include "global.h"

#define SEGMENT_TIME 500

enum{
   NOKEY,
   KEY7,
   KEY6,
   KEY5,
   KEY4,
   KEY3,
   KEY2,
   KEY1,
   KEY0
};
bit flag = 0;
BYTE ReadADCValue(BYTE channel){
   BYTE AdcChannel[8] = {0x03,0x07,0x13,0x17,0x0b,0x0f,0x1b,0x1f}; //ADC Channel Command
   BYTE i;
   BYTE value = 0;
   SetFromAdcOut;   //Initial of MicroController input pin
   ResAdcCS;   //ADC Chip Enable
   
   for(i=0;i<5;i++){
      if((AdcChannel[channel] >> i) & 0x01 !=0){
         SetToAdcIn;
      }
      else{
         ResToAdcIn;
      }
      SetAdcClk;
      ResAdcClk;
   }
   ResAdcClk;
   SetAdcClk;
   
   for(i = 0; i < 8; i++)
   {
      value <<= 1;
      ResAdcClk;
      SetAdcClk;
      if(GetFromAdcOut)
         value |=0x01; 
   }
   
   ResAdcClk;
   
   SetAdcCS;
   
   return value;      
}

BYTE GetADCValue(BYTE channel)
{
   WORD Total=0;
   BYTE Count;
   
   for(Count=0;Count<3;Count++)
   {
      Total +=ReadADCValue(channel);
   }
   return (Total/3);
   
}


BYTE GetPortKey(void){
   BYTE value1,value2,KeyNo = 0;
   
   value1 = (P1);
   value2 = GetADCValue(1);
   
   if(!(value1 & 0x80)){
      if(!(flag)) KeyNo = KEY7;
      flag = 1;
   }
   else if(!(value1 & 0x40)){
      if(!(flag)) KeyNo = KEY6;
      flag = 1;
   }
   else if(!(value1 & 0x20)){
      if(!(flag)) KeyNo = KEY5;
      flag = 1;
   }
   else if(!(value1 & 0x10)){
      if(!(flag)) KeyNo = KEY4;
      flag = 1;
   }
   else if(value2 == 117){
      if(!(flag)) KeyNo = KEY3;
      flag = 1;
   }
   else if(value2 == 99){
      if(!(flag)) KeyNo = KEY2;
      flag = 1;
   }
   else if(value2 == 76){
      if(!(flag)) KeyNo = KEY1;
      flag = 1;
   }
   else if(value2 == 44){
      if(!(flag)) KeyNo = KEY0;
      flag = 1;
   }
   else{
      KeyNo = NOKEY;
      flag = 0;
   }
   return KeyNo;
}
BYTE SegDigit = 0;
WORD FndData=0;
BYTE code FND[10] = {   ~(0x01|0x02|0x04|0x08|0x10|0x20),
         ~(0x02|0x04),
         ~(0x01|0x02|0x40|0x10|0x08),
         ~(0x01|0x02|0x40|0x04|0x08),
         ~(0x20|0x40|0x02|0x04),
         ~(0x01|0x20|0x40|0x04|0x08),
         ~(0x20|0x10|0x40|0x04|0x08|0x01),
         ~(0x20|0x01|0x02|0x04),
         ~(0x01|0x02|0x04|0x08|0x10|0x20|0x40),
         ~(0x20|0x01|0x02|0x40|0x04|0x08)
};
char * key_str(BYTE i){
   char * str;
   int  a;
   switch(i){
      case 0:
         str = "";
         break;
      case 1:
         str = "PORK CUTLET 3000";
         if(FndData>= 3000){
         FndData-=3000;
         str = " GET PORK CUTLET";
         }
         else if(FndData<3000 && FndData>50){
         str = "Not enough money";
         }
         break;
      case 2:
         str = "BIBIMBAB    3500";
         if(FndData>= 3500){
         FndData-=3500;
         str = " GET    BIBIMBAB";
         }
         else if(FndData<3500  && FndData>50 ){
         str = "Not enough money";
         }
         break;
      case 3:
         str = "RAMEN       1500 ";
         if(FndData>=1500){
         FndData-=1500;
         str = " GET       RAMEN";
         }
           else if(FndData<1500  && FndData>50 ){
         str = "Not enough money";
         }
         break;
      case 4:
         str = "GIMBAB      1200 ";
         if(FndData>= 1200){
         FndData-=1200;
         str = " GET      GIMBAB";
         }
         else if(FndData<1200  && FndData>50 ){
         str = "Not enough money";
         }
         break;
      case 5:
         str = "";
         a=100;
         FndData +=a;
         break;
      case 6:
         str = "";
       a=500;
         FndData +=a;
         break;
      case 7:
         str = "";
          a=1000;
         FndData +=a;
         break;
       case 8:
         str = "RETURN     MONEY";
         FndData =0;
         break;
      default:
         str = "";
         break;
   }
   return str;
}

void lcd_command_write(BYTE command);

void ShortDelay(BYTE i){
   while(i--);
}

void LongDelay(WORD i){
   while(i--){
      ShortDelay(145);
   }
}

void Initial_CPU(void){
   P0 = 0xff;
   P1 = 0xff;
   P2 = 0xff;
   P3 = 0xff;
   
   LongDelay(40);
   
   lcd_command_write(0x38);
   lcd_command_write(0x08);
   lcd_command_write(0x01);
   lcd_command_write(0x06);
   lcd_command_write(0x0c);
}

void SegmentDisplay(WORD num){
   WORD TempNumber;
   
   BYTE i;
   BYTE Digit = 0x08;
   
   TempNumber = num;
   for(i = 0 ; i < SegDigit;i++){
      TempNumber = TempNumber / 10;
      Digit = Digit >>1;
   }
   SEG_SIGAL = FND[TempNumber % 10];
   SEG_DIGIT = ~Digit;
   
   if(SegDigit++ >= 3)
      SegDigit = 0;
}

void lcd_command_write(BYTE command){
   LCD_WR_COMMAND = command;
   LongDelay(1);
}

void lcd_char_display(BYTE character){
   LCD_WR_DATA = character;
   LongDelay(1);
}

void LcdString(BYTE x,BYTE y, char *str){
   BYTE index;
   BYTE character;
   
   lcd_command_write(0x80+y+0x40*x);
   
   index = 0;
   character = str[index];
   while(character != '\0'){
      lcd_char_display(character);
      index++;
      character = str[index];
   }
}

void main(void){
   WORD FndNextCount = SEGMENT_TIME;
   Initial_CPU();
   LcdString(0,1,"choose  a  food");
   while(1){
      LcdString(1,0,key_str(GetPortKey()));
      SegmentDisplay(FndData);
      }
   } 
/*
 * LCD.c
 *
 * Created: 3/26/2021 1:12:30 PM
 *  Author: Infotech
 */ 
#include "LCD.h"


void LCD_Intit(void)
{
	#if    LCD_MODE   == 8
	
	DIO_SetPinDir(LCD_8BIT_MODE_CMD_PORT,LCD_RS_PIN,DIO_PIN_OUTPUT);
    DIO_SetPinDir(LCD_8BIT_MODE_CMD_PORT,LCD_RW_PIN,DIO_PIN_OUTPUT);
	DIO_SetPinDir(LCD_8BIT_MODE_CMD_PORT,LCD_E_PIN,DIO_PIN_OUTPUT);
	DIO_SetPortDir(LCD_8BIT_MODE_CMD_PORT,DIO_PORT_OUTPUT);
	
	_delay_ms(100);
 LCD_WriteCommand(0x38);
  LCD_WriteCommand(0x0c);
 LCD_WriteCommand(0x01);
 LCD_WriteCommand(0x06);
 LCD_WriteCommand(0x02);
 
 

 
	
	#elif   LCD_MODE  ==4
	
	DIO_SetPinDir(LCD_4BIT_MODE_CMD_PORT,LCD_RS_PIN,DIO_PIN_OUTPUT);
	DIO_SetPinDir(LCD_4BIT_MODE_CMD_PORT,LCD_RW_PIN,DIO_PIN_OUTPUT);
	DIO_SetPinDir(LCD_4BIT_MODE_CMD_PORT,LCD_E_PIN,DIO_PIN_OUTPUT);
	
	DIO_SetPinDir(LCD_4BIT_MODE_DATA_PORT, LCD_D4 , DIO_PIN_OUTPUT);
	DIO_SetPinDir(LCD_4BIT_MODE_DATA_PORT, LCD_D5 , DIO_PIN_OUTPUT);
	DIO_SetPinDir(LCD_4BIT_MODE_DATA_PORT, LCD_D6 , DIO_PIN_OUTPUT);
	DIO_SetPinDir(LCD_4BIT_MODE_DATA_PORT, LCD_D7 , DIO_PIN_OUTPUT);
	
	_delay_ms(100);
		LCD_WriteCommand(0x33);
	LCD_WriteCommand(0x32);
	LCD_WriteCommand(0x28);
	LCD_WriteCommand(0x0c);
	LCD_WriteCommand(0x01);
	LCD_WriteCommand(0x06);
	LCD_WriteCommand(0x02);
	
	#endif
	
}

void LCD_WriteCommand(uint8 cmd)
{
	DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT,LCD_RS_PIN, DIO_PIN_LOW);
	DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT,LCD_RW_PIN, DIO_PIN_LOW);
	DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT,LCD_E_PIN, DIO_PIN_LOW);
	
	 PORTA = ( cmd & 0xf0 ) | (PORTA & 0x0f);

	DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT,LCD_E_PIN, DIO_PIN_HIGH);
	_delay_ms(100);
	DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT,LCD_E_PIN, DIO_PIN_LOW);
	
		 PORTA = ( cmd << 4 ) | (PORTA & 0x0f);
		 
		 DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT,LCD_E_PIN, DIO_PIN_HIGH);
		 _delay_ms(100);
		 DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT,LCD_E_PIN, DIO_PIN_LOW);
		 _delay_ms(5);
		 
}
		
		


void LCD_WriteChar(uint8 data)
{
	DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT,LCD_RS_PIN, DIO_PIN_HIGH);
	DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT,LCD_RW_PIN, DIO_PIN_LOW);
	DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT,LCD_E_PIN, DIO_PIN_LOW);
	
	PORTA = ( data & 0xf0 ) | (PORTA & 0x0f);

	DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT,LCD_E_PIN, DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT,LCD_E_PIN, DIO_PIN_LOW);
	
	PORTA = ( data << 4 ) | (PORTA & 0x0f);
	
	DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT,LCD_E_PIN, DIO_PIN_HIGH);
	_delay_ms(10);
	DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT,LCD_E_PIN, DIO_PIN_LOW);
	_delay_ms(5);
	
}

void LCD_WriteString(uint8* str)
{
	uint8 cnt = 0 ; 
	while(str[cnt] !='\0')
	{
		LCD_WriteChar(str[cnt]);
		cnt++;
	}
}
	
	void LCD_WriteInteger(sint32  num)
	{
		uint8 j=0;
		sint32 num0 = num;
		// detect number of digits for input integer
		while (num0 !=0)
		{
			num0=num0/10;
			j++;
		}
		uint8 digit[j];
		uint8 i=0;
		// convert input integer to individual digits and put them in array
        while(num !=0)
   {
	    digit[i]=num%10;
	    num=num/10;
	    i++;
    }
	    // print ASCII number code + every singel digit 
        while(j>0)
  {
	  LCD_WriteChar(0x30+digit[j-1]);
	  j--;
  }
		
		}

	void LCD_GoToLocation(uint8 row , uint8 col)
	{
		uint8 Loc[2] = {0x80 , 0xc0};
		
		LCD_WriteCommand(Loc[row]+col);
	}
	void LCD_Clear(void)
	{
		LCD_WriteCommand(0X01);
	}



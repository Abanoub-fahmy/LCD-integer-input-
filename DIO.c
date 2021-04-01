/*
 * DIO.c
 *
 * Created: 3/20/2021 10:59:51 AM
 *  Author: Ali
 */ 

#include "DIO.h"




void DIO_SetPortDir(uint8 Port, uint8 Dir)
{
	switch(Port)
	{
		case DIO_PORTA :
		DDRA = Dir;
		break;
		
		case DIO_PORTB :
		DDRB = Dir;
		break;
		
		case DIO_PORTC :
		DDRC = Dir;
		break;
		
		case DIO_PORTD :
		DDRD = Dir;
		break;
		
		default:
		
		break;
		
	}
}

void DIO_SetPinDir(uint8 Port , uint8 Pin , uint8 Dir)
{
	switch (Dir)
	{
		case  DIO_PIN_OUTPUT :
		 
		 switch (Port)
		 {
			 case DIO_PORTA :
			 SET_BIT(DDRA , Pin);
			 break;
			 
			 case DIO_PORTB :
			 SET_BIT(DDRB , Pin);
			 break;
			 
			 case DIO_PORTC :
			 SET_BIT(DDRC , Pin);
			 break;
			 
			 case DIO_PORTD :
			 SET_BIT(DDRD , Pin);
			 break;
			 
			 default :
			 
			 break;
		 }
		
		break;
		
		
		case  DIO_PIN_INPUT :
		
		switch (Port)
		{
			case DIO_PORTA :
			CLR_BIT(DDRA , Pin);
			break;
			
			case DIO_PORTB :
			CLR_BIT(DDRB , Pin);
			break;
			
			case DIO_PORTC :
			CLR_BIT(DDRC , Pin);
			break;
			
			case DIO_PORTD :
			CLR_BIT(DDRD , Pin);
			break;
			
			default :
			
			break;
		}
		
		break;
		
	
		default:
		break;
		
	}
}

void DIO_SetPortValue(uint8 Port, uint8 Vlaue)
{
	switch(Port)
	{
		case DIO_PORTA :
		PORTA = Vlaue;
		break;
		
		case DIO_PORTB :
		PORTB = Vlaue;
		break;
		
		case DIO_PORTC :
		PORTC = Vlaue;
		break;
		
		case DIO_PORTD :
		PORTD = Vlaue;
		break;
		
		default:
		
		break;
		
	}
}



void DIO_SetPinValue(uint8 Port , uint8 Pin , uint8 Value)
{
	
	switch (Value)
	{
		case  DIO_PIN_HIGH :
		
		switch (Port)
		{
			case DIO_PORTA :
			SET_BIT(PORTA , Pin);
			break;
			
			case DIO_PORTB :
			SET_BIT(PORTB , Pin);
			break;
			
			case DIO_PORTC :
			SET_BIT(PORTC , Pin);
			break;
			
			case DIO_PORTD :
			SET_BIT(PORTD , Pin);
			break;
			
			default :
			
			break;
		}
		
		break;
		
		
		case  DIO_PIN_LOW :
		
		switch (Port)
		{
			case DIO_PORTA :
			CLR_BIT(PORTA , Pin);
			break;
			
			case DIO_PORTB :
			CLR_BIT(PORTB , Pin);
			break;
			
			case DIO_PORTC :
			CLR_BIT(PORTC , Pin);
			break;
			
			case DIO_PORTD :
			CLR_BIT(PORTD , Pin);
			break;
			
			default :
			
			break;
		}
		
		break;
		
		
		default:
		break;
		
	}
}

void DIO_ReadPortValue(uint8 Port, uint8* Value)
{
	switch(Port)
	{
		case DIO_PORTA :
		*Value = PINA;
		break;
		
		case DIO_PORTB :
		*Value = PINB;
		break;
		
		case DIO_PORTC :
		*Value = PINC;
		break;
		
		case DIO_PORTD :
		*Value = PIND;
		break;
		
		default:
		
		break;
		
	}
}
void DIO_ReadPinValue(uint8 Port, uint8 Pin ,uint8* Value)
{
	switch (Port)
	{
		case DIO_PORTA :
		*Value = GET_BIT(PINA , Pin);
		break;
		
		case DIO_PORTB :
		*Value = GET_BIT(PINB , Pin);
		break;
		
		case DIO_PORTC :
		*Value = GET_BIT(PINC , Pin);
		break;
		
		case DIO_PORTD :
		*Value = GET_BIT(PIND , Pin);
		break;
		
		default:
		break;
	}
}

void DIO_TogglePort(uint8 Port)
{
	switch(Port)
	{
		case DIO_PORTA :
		PORTA ^= 0xff;
		break;
		
		case DIO_PORTB :
		PORTB ^= 0xff;
		break;
		
		case DIO_PORTC :
		PORTC ^= 0xff;
		break;
		
		case DIO_PORTD :
		PORTD ^= 0xff;
		break;
		
		default:
		
		break;
		
	}
}

void DIO_TogglePin(uint8 Port, uint8 Pin)
{
	switch (Port)
	{
		case DIO_PORTA :
		Toggle_BIT(PORTA , Pin);
		break;
		
		case DIO_PORTB :
		Toggle_BIT(PORTB , Pin);
		break;
		
		case DIO_PORTC :
		Toggle_BIT(PORTC , Pin);
		break;
		
		case DIO_PORTD :
		Toggle_BIT(PORTD , Pin);
		break;
		
		default:
		break;
	}
}

void DIO_SetPullUp(uint8 Port, uint8 Pin)
{
	switch(Port)
	{
		case DIO_PORTA :
		SET_BIT(PORTA , Pin);
		break;
		
		case DIO_PORTB :
		SET_BIT(PORTB , Pin);
		break;
		
		case DIO_PORTC :
		SET_BIT(PORTC , Pin);
		break;
		
		case DIO_PORTD :
		SET_BIT(PORTD , Pin);
		break;
		
		default:
		
		break;
		
	}
}
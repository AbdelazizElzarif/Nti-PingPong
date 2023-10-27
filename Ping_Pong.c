#include "StdTupes.h"
#include "DIO_interface.h"
#include "LCD_Cfg.h"
#include "LCD_Interface.h"
#include "Utils.h"
#include "Ping_Pong.h"
static u8 play1_score=0;
static u8 play2_score=0;
u8 static flag_player=1;
static u8 i;
static u8 k=0,ball_p=0,ham1=0,ham2=0;
static u8 hamada[] = {
	0x00,
	0x0E,
	0x0A,
	0x0E,
	0x04,
	0x0E,
	0x15,
	0x04
};
static u8 ball[] = {
	0x00,
	0x00,
	0x04,
	0x0A,
	0x04,
	0x00,
	0x00,
	0x00
};



void Ping_init(void)
{
	
	LCD_CustomChar(0,hamada);
	LCD_CustomChar(1,ball);
	LCD_GoTo(0,0);
	LCD_WriteChar(0);
	//LCD_WriteChar(1);
	LCD_GoTo(0,19);
	LCD_WriteChar(0);
	LCD_GoTo(3,0);
	LCD_WriteString("p1: ");
	LCD_GoTo(3,5);
	LCD_WriteNum(play1_score);//(3,5);
	LCD_GoTo(3,13);
	LCD_WriteString("p2: ");
	LCD_GoTo(3,16);
	LCD_WriteNum(play2_score);//(3,16)
	LCD_GoTo(0,1);
	
	
}
void Ping_run(void)
{
	
	
	
	//ball_p1=0,ham1=0;
	
	
		if(flag_player==1)
		{
			
			for(i=1;i<18;i++)
			{
				k=KEYPAD_GetKey();
				if(k=='1'&&ball_p!=2)
				{
					//LCD_GoTo(ball_p,i-1);
					//LCD_WriteChar(' ');
					ball_p++;
					
				}
				else if(k=='4'&&ball_p!=0)
				{
					//LCD_GoTo(ball_p,i-1);
					//LCD_WriteChar(' ');
					ball_p--;
				}
				if(k=='-'&&ham2!=2)
				{
					//LCD_GoTo(ball_p,i-1);
					//LCD_WriteChar(' ');
					LCD_GoTo(ham2,19);
					LCD_WriteChar(' ');
					ham2++;
					LCD_GoTo(ham2,19);
					LCD_WriteChar(0);
					
				}
				else if(k=='*'&&ham2!=0)
				{
					LCD_GoTo(ham2,19);
					LCD_WriteChar(' ');
					ham2--;
					LCD_GoTo(ham2,19);
					LCD_WriteChar(0);
				}
				
				LCD_GoTo(ball_p,i);
				LCD_WriteChar(1);
				_delay_ms(150);
				LCD_GoTo(ball_p,i);
				LCD_WriteChar(' ');
				
				
			}
			flag_player=2;
			if(ball_p!=ham2)
			{
				play1_score++;
				LCD_GoTo(3,5);
				LCD_WriteNum(play1_score);
			}
			LCD_GoTo(ball_p,18);
		
		}
		else if(flag_player==2)
		{
			
			for(i=18;i>0;i--)
			{
				
				
				LCD_GoTo(ball_p,i);
				LCD_WriteChar(1);
				_delay_ms(150);
				LCD_GoTo(ball_p,i);
				LCD_WriteChar(' ');
				k=KEYPAD_GetKey();
				if(k=='-'&&ball_p!=2)
				{
					//LCD_GoTo(ball_p,i-1);
					//LCD_WriteChar(' ');
					ball_p++;
					
				}
				else if(k=='*'&&ball_p!=0)
				{
					//LCD_GoTo(ball_p,i-1);
					//LCD_WriteChar(' ');
					ball_p--;
				}
				if(k=='1'&&ham1!=2)
				{
					//LCD_GoTo(ball_p,i-1);
					//LCD_WriteChar(' ');
					LCD_GoTo(ham1,0);
					LCD_WriteChar(' ');
					ham1++;
					LCD_GoTo(ham1,0);
					LCD_WriteChar(0);
					
				}
				else if(k=='4'&&ham1!=0)
				{
					LCD_GoTo(ham1,0);
					LCD_WriteChar(' ');
					ham1--;
					LCD_GoTo(ham1,0);
					LCD_WriteChar(0);
				}
				
				
			}
			flag_player=1;
			if(ball_p!=ham1)
			{
				play2_score++;
				LCD_GoTo(3,16);
				LCD_WriteNum(play2_score);
			}
			LCD_GoTo(ball_p,1);
			
		}
		
		
		
	
	
}

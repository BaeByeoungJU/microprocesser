#include <avr/io.h>
#include <avr/delay.h>

void init(void)
{
	PORTA = 0x00;
	DDRA  = 0xff;
	PORTC = 0x00;
	DDRC  = 0x0f;
}
void count10(int count)
{
	int num10, num1;
	int i;
	for(i=0;i<=count+1;i++)
	{
		if(i>count) i=count;

		num10 = i / 10;
		num1 = i % 10;

		for(int j=0;j<50;j++)
		{
			PORTC = DISP_SEL(1);
			PORTA = SEG_CODE(num1);
			_delay_ms(10);
			PORTC = DISP_SEL(0);
			PORTC = DISP_SEL(2);
			PORTA = SEG_CODE(num10);
			_delay_ms(10);
			PORTC = DISP_SEL(0);
		}
	}
}

void main(void)
{
	init();
	count10(14);
}
	

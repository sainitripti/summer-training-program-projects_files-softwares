#include<reg51.h>
sbit led=P3^2;
sbit led1=P3^3;
unsigned long num;
sbit AD_DATA_PIN = P1^5; // Pin mapping of microcontroller
sbit AD_SCK_PIN = P0^0; // Pin mapping of microcontroller

unsigned long ReadCount(void)
{
	unsigned long Count;
	unsigned char i;
	AD_SCK_PIN=0; 
	Count=0;
	while(AD_DATA_PIN); 
	for (i=0;i<24;i++)
	{
		AD_SCK_PIN=1;
		Count=Count<<1;
		AD_SCK_PIN=0;
		if(AD_DATA_PIN) Count++;
	}
	AD_SCK_PIN=1;
	Count=Count^0x800000;
	AD_SCK_PIN=0;
	return(Count);
}

void main()
{ while(1)
	{
	num=ReadCount();
		led1=~led1;
	if(num<1)
	  led=0;
	  else
	  led=1;
  }
}
	


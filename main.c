 #include <stdlib.h> 
 #include  <avr/io.h> 
 
 
 #define F_CPU 8000000UL 
 #include <util/delay.h> 
 
 
 //grüne LED1
 #define LED1_ON	PORTC |= (1<<PC3);//LED1 gesetzt
 #define LED1_OFF	PORTC &= ~(1<<PC3);//LED1 löscht
 
 
 //Taster einlesen
 #define	TS_gruen	!(PIND&(1<<PD6))	//Grüner Taster
 #define	TS_blau		!(PIND&(1<<PD2))	//Blauer Taster
 #define	TS_rot		!(PIND&(1<<PD5))	//Roter Taster
 
 
int main (void) //Start main
 {
	DDRD = 0x00; // alle Port_D auf Eingang gesetzt 
 	PORTD = 0xFF; // alle Port_D auf HIGH gesetzt 
	
	DDRC = 0xFF; // alle PORT_C auf Ausgang gesetzt
	PORTC = 0x00; //alle PORT_C auf LOW gesetzt	
	
	/*//Variablen Flankentriggerung
	char edge = 0;
	char act*/
		
	while(1)//start Endlos
	{
		if(TS_gruen)
		{
			LED1_ON;
		}
		
		if(TS_blau)
		{
			LED1_OFF;
		}
		
		if(TS_rot)
		{
			LED1_ON;
		}
	}		//ende Endlos
 
 }//ende main
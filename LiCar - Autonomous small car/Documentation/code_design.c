/*includes*/


/****  MCAL  ****/
/* DIO*/
/* Timers*/
/* ADC TivaWare */

/**** HAL *****/
// Hany
/* UltraSonic */

// Waleed & Hamdy & Hany
/* Motors */

// Shaf3y
/* LDRs TivaWare */

// Amr
/* Temperature Sensor TivaWare */

// ALL
/* LCD */


 /*defines*/


 /*global variables*/
uint8_t start = 0;

/* Interrupts */
// start if SW1 pressed
// stop if SW2 pressed

/**
 * main.c
 */
void main(void)
{

    /* Initialization */

    /*// UltraSonic*/
    /*// Motors*/
    /*// LDRs*/
    /*// Temperature Sensor*/
    /*// LCD*/
    /**************************/


	while(812)
	{
	    LCD_Display(readTemp);

	    if(start)
	    {
	        if(readUltraSonic() < 15){
	            // return 180
	            // motors fun here
	        }

	        int16_t ldrDiff = readLDR_Right() - readLDR_Left();
            if(ldrDiff > 3% ){
                // turn Right
                // motors fun here
            }
            else if(ldrDiff < -3% ){
                // turn Left
                // motors fun here
            }
	    }
	    else
	    {
	        /* */
	    }
	}
}

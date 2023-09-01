/*
 * delay.c
 *
 *  Created on: Aug 18, 2023
 *      Author: EUI-Support
 */


void _delay_ms(unsigned int n){
        int i, j;
        for (i=0;i<n;i++)
        for (j=0;j<3180;j++){};
}
void _delay_us(unsigned int n){
        int i, j;
        for (i=0;i<n;i++)
        for (j=0;j<3;j++){};
}


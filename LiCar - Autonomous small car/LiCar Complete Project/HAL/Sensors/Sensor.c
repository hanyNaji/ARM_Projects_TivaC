/*
 * LDR.c
 *
 *  Created on: 31 Aug 2023
 *      Author: Amr Al-Kayal
 */
#include "Sensor.h"

 uint32_t pui32ADC0Value[1];

 void temp_Init(void)
  {
    SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC0);
    /*GPIOE enabled*/
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
    /*PIN3 became ADC0*/
    GPIOPinTypeADC(GPIO_PORTE_BASE, GPIO_PIN_1);

      SysCtlClockSet(SYSCTL_SYSDIV_1| SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);

      SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC0);

      ADCSequenceConfigure(ADC0_BASE, 3, ADC_TRIGGER_PROCESSOR, 0);

      ADCSequenceStepConfigure(ADC0_BASE, 3, 0, ADC_CTL_TS | ADC_CTL_IE | ADC_CTL_END);

      ADCSequenceEnable(ADC0_BASE, 3);

      ADCIntClear(ADC0_BASE, 3);
  }


 uint32_t Temp_Read(void)
{
    uint32_t ui32TempValueC;
    /* Trigger the ADC conversion. */

    ADCProcessorTrigger(ADC0_BASE, 3);

    /* Wait for conversion to be completed. */
    while(!ADCIntStatus(ADC0_BASE, 3, false));

    /* Clear the ADC interrupt flag. */
    ADCIntClear(ADC0_BASE, 3);

    /* Read ADC Value. */
    ADCSequenceDataGet(ADC0_BASE, 3, pui32ADC0Value);

    /* Use non-calibrated conversion provided in the data sheet.  Make */
    /* sure you divide last to avoid dropout. */

    ui32TempValueC = 147.5 - ((75 * 3.3 * pui32ADC0Value[0]) / 4096);

    return ui32TempValueC;
}



 void LDR_Right(void)
 {
    /*to enable clock for portE */
    SysCtlClockSet(SYSCTL_SYSDIV_1|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
    /*****************************************************************************

    Configure ADC0 for a single-ended input and a single sample.  Once the
    sample is ready, an interrupt flag will be set.  Using a polling method,
    the data will be read then displayed on the console via UART0.

    *****************************************************************************/
    /*The ADC0 peripheral must be enabled for use. */
    SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC0);
    /*GPIOE enabled*/
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
    /*PIN3 became ADC0*/
    GPIOPinTypeADC(GPIO_PORTE_BASE, GPIO_PIN_3);
    /*sequence configre 1,processor genrate trigger one sample*/
    ADCSequenceConfigure(ADC0_BASE, 1, ADC_TRIGGER_PROCESSOR, 0);
    /*sample sequencer config Sample channel 0 (ADC_CTL_CH0) in
    single-ended mode (default) and configure the interrupt flag
    (ADC_CTL_IE) to be set when the sample is done.  Tell the ADC logic
    that this is the last conversion on sequence 3 (ADC_CTL_END).*/
    ADCSequenceStepConfigure(ADC0_BASE, 1, 0, ADC_CTL_CH2 | ADC_CTL_IE | ADC_CTL_END);
    /*Since sample sequence 3 is now configured, it must be enabled.*/
    ADCSequenceEnable(ADC0_BASE, 1);
    /*interrupt flag is cleared before we sample.*/
    ADCIntClear(ADC0_BASE, 1);
 }
 void READ_Right(uint32_t * Copy_Parmeter)
 {
    /*Trigger the ADC conversion. */
    ADCProcessorTrigger(ADC0_BASE, 1);

    /*Wait for conversion to be completed.*/
    while(!ADCIntStatus(ADC0_BASE, 1, false))
    {
    }
    /*clear Interput flag*/
    ADCIntClear(ADC0_BASE, 1);
    /*Read ADC*/
    ADCSequenceDataGet(ADC0_BASE, 1, Copy_Parmeter);

 }
 void LDR_Left(void)
 {
    /*to enable clock for portE */
    SysCtlClockSet(SYSCTL_SYSDIV_1|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
    /*****************************************************************************

    Configure ADC0 for a single-ended input and a single sample.  Once the
    sample is ready, an interrupt flag will be set.  Using a polling method,
    the data will be read then displayed on the console via UART0.

    *****************************************************************************/
     /*The ADC0 peripheral must be enabled for use. */
     SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC0);
     /*GPIOE enabled*/
     SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
     /*PIN3 became ADC0*/
     GPIOPinTypeADC(GPIO_PORTE_BASE, GPIO_PIN_2);
     /*sequence configre 2 ,processor genrate trigger one sample*/
     ADCSequenceConfigure(ADC0_BASE, 2, ADC_TRIGGER_PROCESSOR, 0);
     /*sample sequencer config Sample channel 0 (ADC_CTL_CH0) in
      single-ended mode (default) and configure the interrupt flag
      (ADC_CTL_IE) to be set when the sample is done.  Tell the ADC logic
       that this is the last conversion on sequence 3 (ADC_CTL_END).*/
     ADCSequenceStepConfigure(ADC0_BASE, 2, 0, ADC_CTL_CH1 | ADC_CTL_IE | ADC_CTL_END);
     /*Since sample sequence 2 is now configured, it must be enabled.*/
     ADCSequenceEnable(ADC0_BASE, 2);
     /*interrupt flag is cleared before we sample.*/
     ADCIntClear(ADC0_BASE, 2);
 }
 void READ_LEFT(uint32_t * Copy_Parmeter)
 {
    /*Trigger the ADC conversion. */
    ADCProcessorTrigger(ADC0_BASE, 2);

    /*Wait for conversion to be completed.*/
    while(!ADCIntStatus(ADC0_BASE, 2, false))
    {
    }
    /*clear Interput flag*/
    ADCIntClear(ADC0_BASE, 2);
    /*Read ADC*/
    ADCSequenceDataGet(ADC0_BASE, 2, Copy_Parmeter);

 }




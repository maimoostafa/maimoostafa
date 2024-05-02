#include "IO.h"
#include "generalGPIO.h"


void REDLED_Init (void){
SYSCTL_RCGCGPIO_R |= PF_mask ;
while((SYSCTL_PRGPIO_R & PF_mask)==0);
GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY ;
GPIO_PORTF_CR_R |= PF1_mask ;
GPIO_PORTF_AMSEL_R &= ~ PF1_mask ;
GPIO_PORTF_AFSEL_R &= ~ PF1_mask ;
GPIO_PORTF_PCTL_R &= ~ 0x0000FFF0;
GPIO_PORTF_DIR_R |= PF1_mask ;
GPIO_PORTF_DEN_R |= PF1_mask ;
GPIO_PORTF_DATA_R &= ~ PF1_mask ;
}
void SW_Init (void){
GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY ;
GPIO_PORTF_CR_R |= PF0_mask ;
GPIO_PORTF_AMSEL_R &= ~ PF0_mask ;
GPIO_PORTF_AFSEL_R &= ~ PF0_mask ;
GPIO_PORTF_PCTL_R &= ~ 0x000F000F;
GPIO_PORTF_DIR_R &= ~ PF0_mask ;
GPIO_PORTF_DEN_R |= PF0_mask ;
GPIO_PORTF_PUR_R = PF0_mask ;
}
void LEDs_output(unsigned char data){
GPIO_PORTF_DATA_R &= ~ PF1_mask ;
GPIO_PORTF_DATA_R |= data ;
}
unsigned char SW_input(void){
return GPIO_PORTF_DATA_R & PF0_mask;
}
int main(){
REDLED_Init();
SW_Init();
while(1){
if (SW_input()==0x10){ 
LEDs_output(0x02); // red led
 }}}

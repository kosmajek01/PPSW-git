#include "led.h"
#include "timer_interrupts.h"
#include "keyboard.h"

//nowy komentarz
// czy zadziala
void Automat (void){
	enum LedState {LED_RIGHT, LED_LEFT, STOP};

	static enum LedState eLedState = STOP;
	
		switch (eLedState){
			
			case STOP:
			if (eKeyboardRead()== BUTTON_0){
				  eLedState = LED_LEFT;
			}

			else if (eKeyboardRead() == BUTTON_2){
				  eLedState = LED_RIGHT;
			}
			//git test
			else {
				eLedState = STOP;
			}
			break;
			
			
			case LED_RIGHT:
			
				if (eKeyboardRead()==BUTTON_1){
					eLedState = STOP;
				}				
				else {
					LedStepRight();
					eLedState = LED_RIGHT;

				}
			break;
				
				case LED_LEFT:
			
				if (eKeyboardRead()==BUTTON_1){
					eLedState = STOP;
				}				
				else {
					LedStepLeft();
					eLedState = LED_LEFT;

				}
			break;

		}
}


int main ()
{
	unsigned int iMainLoopCtr;
	LedInit();
	KeyboardInit();
	Timer0Interrupts_Init(20000,&Automat);

	while(1){
	 	iMainLoopCtr++;
	 	iMainLoopCtr++;
	 	iMainLoopCtr++;
	 	iMainLoopCtr++;
	 	iMainLoopCtr++;
	}
}

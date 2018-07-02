#include <stdint.h>
#include "GPIO.h"
#include "UART.h"
#include "GPIO_Cfg.h"
#include "UART_Cfg.h"
#include "M4MemMap.h"
#include "PiMngr.h"
#include "BTN.h"


uint8_t StateX;

int main(void)
    {

    uint16_t counter = 0;
    GPIO_Init();
    BTN_Init();
    UART_Init();
    //EN_INT(5);
    EN_INT(61);
    State = Unpressed;
    while(1)
    {
        // In the first loop iteration, the state = unpressed
        // so we'll get the button state and see if it's pressed
        // if it's pressed, a led will be on and the state = initial
        //
        if(State == Unpressed)
        {
            /* Application must clear this flag after using the word, not me*/
            //RecognitionDone = 0;
            BTN_GetBtnState(0, &StateX);
            if(StateX == BTN_JPRSD)
            {
                GPIO_Write(18, 0xFF);
                for(counter = 0; counter< 50000; counter++);
                GPIO_Write(18, 0x00);
                State = Initial;

            }
        }
        if(State != Unpressed)
        {
        PiMngr_GetStatus();
        PiMngr_StartRecognition();
        PiMngr_RequestData();
        }
    }
    return 0;
}


#ifndef PIMNGR_H_
#define PIMNGR_H_

typedef enum {Unpressed = 1, Initial , ReadytoRecognize, ReadytoReceive, BusytoRecognize, BusytoReceive, ReceptionDone, Done, InitialInProg, ReadytoRecognizeInProg, ReceptionInProg, Doneeee} PiStates;
typedef enum {Navigation = 1, Music, Play, Stop, Next, Previous, Call, Answer, Reject, Finish, Engine, Daniel, Mark, Jessica, Error} Word;

uint8_t ID;
uint8_t DataLen;
uint8_t Data[18];

extern uint8_t RxBuff[20];
extern uint8_t RxBuff_Word[20];
extern PiStates State;
extern uint8_t RecognitionDone;

void PiMngr_GetStatus(void);
void PiMngr_StartRecognition(void);
void PiMngr_RequestData(void);

void PiMngr_Callback_Func(void);

void PiMngr_TxDone(void);
void PiMngr_RxDone(void);

#endif /* PIMNGR_H_ */

#include <IRremote.hpp>
#include "Car_motors.h"

#define SCL_Pin    A5  //Set clock pin to A5
#define SDA_Pin    A4  //Set data pin to A4
#define SERVO_Pin  A3  

enum
{
  IRrecv_Pin = 3, 
};

const uint32_t SIG_RIGHT =  0x43;
const uint32_t SIG_LEFT =   0x44;
const uint32_t SIG_DIRECT = 0x46;
const uint32_t SIG_STOP =   0x15;

unsigned char bitmapArrowright[] = {  0x00,   0x00,   0x00,   0x00,   0x00, 0x00,   0x18,   0x24,   0x42,   0x81,   0x00,   0x00, 0x00,   0x00,   0x00,   0x00  };
unsigned char bitmapArrowleft[] = {  0x00,   0x00,   0x00,   0x00,   0x00,   0x00,   0x81,   0x42,   0x24,   0x18,   0x00,   0x00,  0x00, 0x00,   0x00, 0x00  };
unsigned char smile[] = { 0x00, 0x00, 0x1c, 0x02, 0x02, 0x02, 0x5c, 0x40, 0x40, 0x5c, 0x02, 0x02, 0x02, 0x1c, 0x00, 0x00 };

uint32_t res;

car_motors motors(5, 2, 4, 6); 

Display display(8, 16, SCL_Pin, SDA_Pin);

float way[3];

void setup (){
  IrReceiver.begin(IRrecv_Pin, ENABLE_LED_FEEDBACK); // Start the receiver
  Serial.begin(9600);         //скорость передачи данных
}

void loop ()
{  
  if( IrReceiver.decode())        //если получили сигнал
  {         
    IrReceiver.printIRResultShort(&Serial); // Print "old" raw data
    res = IrReceiver.decodedIRData.command;
    Serial.println(res, HEX); // Print "old" raw data
    Serial.println(SIG_DIRECT, HEX); // Print "old" raw data
    if (res == SIG_LEFT){                //left
      motors.move_leftly();
      display.matrix_display(bitmapArrowleft);
    }
    if (res == SIG_RIGHT){               //right 
      motors.move_rightly();
      display.matrix_display(bitmapArrowright);
    }
    if (res == SIG_DIRECT){               //directly 
      motors.move_directly();
      display.matrix_display(smile);
    }
    if (res == SIG_STOP){               //stop
      motors.stop();
      display.matrix_display(smile);
    }
    IrReceiver.resume();                  //получаем опять сигнал
  }
} 

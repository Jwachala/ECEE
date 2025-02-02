#include "ZedBoard.h"

// Physical base address of GPIO

//const unsigned gpio_address = 0x400d0000;

// Length of memory-mapped IO window

/*const unsigned gpio_size = 0xff;

const int gpio_led1_offset = 0x12C;  // Offset for LED1

const int gpio_led2_offset = 0x130;  // Offset for LED2

const int gpio_led3_offset = 0x134;  // Offset for LED3

const int gpio_led4_offset = 0x138;  // Offset for LED4

const int gpio_led5_offset = 0x13C;  // Offset for LED5

const int gpio_led6_offset = 0x140;  // Offset for LED6

const int gpio_led7_offset = 0x144;  // Offset for LED7

const int gpio_led8_offset = 0x148;  // Offset for LED8

const int gpio_sw1_offset = 0x14C;   // Offset for Switch 1

const int gpio_sw2_offset = 0x150;   // Offset for Switch 2

const int gpio_sw3_offset = 0x154;   // Offset for Switch 3

const int gpio_sw4_offset = 0x158;   // Offset for Switch 4

const int gpio_sw5_offset = 0x15C;   // Offset for Switch 5

const int gpio_sw6_offset = 0x160;   // Offset for Switch 6

const int gpio_sw7_offset = 0x164;   // Offset for Switch 7

const int gpio_sw8_offset = 0x168;   // Offset for Switch 8

const int gpio_pbtnl_offset = 0x16C; // Offset for left push button

const int gpio_pbtnr_offset = 0x170; // Offset for right push button

const int gpio_pbtnu_offset = 0x174; // Offset for up push button

const int gpio_pbtnd_offset = 0x178; // Offset for down push button

const int gpio_pbtnc_offset = 0x17C; // Offset for center push button*/


/**

 * Show lower 8 bits of integer value on LEDs

 *

 * @param ptr Base address of I/O

 * @param value Value to show on LEDs

 */

void SetLedNumber(int value,ZedBoard &board) {

    board.RegisterWrite( gpio_led1_offset, value % 2);

    board.RegisterWrite( gpio_led2_offset, (value / 2) % 2);

    board.RegisterWrite( gpio_led3_offset, (value / 4) % 2);

    board.RegisterWrite( gpio_led4_offset, (value / 8) % 2);

    board.RegisterWrite( gpio_led5_offset, (value / 16) % 2);

    board.RegisterWrite( gpio_led6_offset, (value / 32) % 2);

    board.RegisterWrite( gpio_led7_offset, (value / 64) % 2);

    board.RegisterWrite( gpio_led8_offset, (value / 128) % 2);

}
/**
*
*/
int PushButtonGet(ZedBoard &board){
    //0 = none pressed
    //1 = left
    //2 = right
    //3 = up
    //4 = down
    //5 = center
    for(int i = 0; i < 5; i++){
        int val = board.RegisterRead(gpio_pbtnl_offset+4*i);
        if(val ==1){
            return i+1;
        }
        
    }
    return 0;
}

int main() {

    // Initialize

    //int fd;
    ZedBoard board;
    //char *ptr = Initialize(&fd);

    // Check error

    /*if (ptr == MAP_FAILED) {

        perror("Mapping I/O memory failed - Did you run with 'sudo'?\n");

        return -1;

    }*/
    int count = 0;
    int lastState = 7;
    while(true){
        usleep(1000);
        if(count > 255){
                 count = 255;
        }
        if(count < 0){
                 count = 0;
        }
        SetLedNumber(count, board);
        int state = PushButtonGet(board);
        if(lastState == 7){
            state = 5;
            }
        if(state!=lastState){
        
        switch(state){
            case 1:{
                if(count>127){
                count-=128;
                }
                count*=2;
                break; 
            }
            case 2:{
                count/=2;
                break; 
            }
            case 3:{
                 count++;
                 break; 
            }
            case 4:{
                count--;
                break; 
            }
            case 5:{
            count = 0;
                 for(int i = 0; i < 8; i++){
                     int val = board.RegisterRead( gpio_sw1_offset+4*i);
                     count+= val*std::pow(2,i);
                 }
                 break; 
            }
        }
        lastState = state;
        }
    }
    /*int value;

    std::cout << "Enter a value less than 256: ";

    std::cin >> value;

    // Show the value on the Zedboard LEDs

    SetLedNumber( value);
*/
    // Done

    //Finalize( fd);
    
    return 0;

}
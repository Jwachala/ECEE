#include "ZedBoard.h"


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
    int timeCount = 0;
    int lastState = 7;
    int mult = 0;
    while(true){
        usleep(1000);
        if(mult > 0 || mult < 0){
          timeCount++;  
          if(timeCount%(1000/abs(mult)) == 0){
          if(mult >0){
            count++;
          }else{
              count--;
          }
            SetLedNumber(count, board);
          }
        }
        
        
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
                
                if(mult > 0){
                    mult*=-1;
                }
                break; 
            }
            case 2:{
                if(mult < 0){
                    mult*=-1;
                }
                break; 
            }
            case 3:{
                 mult++;
                 break;
            }
            case 4:{
                mult--;
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
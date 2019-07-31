#include <stdio.h>

int main(){
//    for(float x = 16000000; x < 17000010; x++){
//        printf("%f\n", x);
//    }

    float floats[] = {16777216, 16777217, 16777218};
    for(int i = 0; i < sizeof(floats) / sizeof(float); i++){
        printf("%f\n", floats[i]);
    }

    return 0;
}

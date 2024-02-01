#include <stdio.h>
#include <unistd.h>
#include <pigpio.h>

#define led 18

int main() {
    if (gpioInitialise() < 0) {
        fprintf(stderr, "pigpio initialisation failed\n");
        return 1;
    }

    gpioSetPWMrange(led, 100);

    while (1) {
        for (int i = 0; i < 100; i++) {
            gpioPWM(led, i);
            usleep(100000);
        }

        for (int i = 100; i >= 0; i--) {
            gpioPWM(led, i);
            usleep(100000);
        }
    }
}

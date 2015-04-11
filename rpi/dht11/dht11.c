#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <fcntl.h>
#include <assert.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <unistd.h>
#include <bcm2835.h>

int readDHT(int pin, unsigned int *data)
{
    int i = 0, j = 0;
    int counter = 0;
    int laststate = HIGH;

    // Set GPIO pin to output
    bcm2835_gpio_fsel(pin, BCM2835_GPIO_FSEL_OUTP);

    bcm2835_gpio_write(pin, HIGH);
    usleep(500000); // 500ms
    bcm2835_gpio_write(pin, LOW);
    usleep(20000);  // 20ms

    // Set GPIO pin to input
    bcm2835_gpio_fsel(pin, BCM2835_GPIO_FSEL_INPT);

    // wait for pin to drop?
    while (bcm2835_gpio_lev(pin) == 1) {
        usleep(1);
    }

    // reading data
    for (i = 0; i < 100; i++) {
        counter = 0;
        while (bcm2835_gpio_lev(pin) == laststate) {
            counter++;
            //nanosleep(1);		// overclocking might change this?
            if (counter == 1000)
                break;
        }
        if (counter == 1000) break;
        laststate = bcm2835_gpio_lev(pin);

        if ((i>3) && (i%2 == 0)) {
            // shove each bit into the storage bytes
            data[j/8] <<= 1;
            if (counter > 200)
                data[j/8] |= 1;
            j++;
        }
    }

    printf("Data (%d): 0x%x 0x%x 0x%x 0x%x 0x%x\n", j, data[0], data[1], data[2], data[3], data[4]);
    if ((j >= 39) && (data[4] == ((data[0] + data[1] + data[2] + data[3]) & 0xFF)) ) {
        printf("Temp = %d *C, Hum = %d \%\n", data[2], data[0]);
    }

    return 0;
}

int main(int argc, char **argv)
{
    uint8_t counter = 0;
    uint32_t data[100];

	if (!bcm2835_init())  
		return 1;  

	while (counter++ < 10) {
        memset(data, 100, 100 * sizeof(uint32_t));
        readDHT(4, data); // RPI PIN #7
	}

	bcm2835_close();  
	return 0;  
}

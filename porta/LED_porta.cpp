#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <bcm2835.h>

using namespace std;

// Blinks on RPi Plug P1 pin 11 (which is GPIO pin 17)
#define PIN RPI_GPIO_P1_11

int main()
{
    // If you call this, it will not actually access the GPIO
    // Use for testing
	//  bcm2835_set_debug(1);
	// cout<<"entrou"; debugs;

    if (!bcm2835_init())
    {
		return 1;

		cout<<"erro";
	}

    // Set the pin to be an output
    bcm2835_gpio_fsel(PIN, BCM2835_GPIO_FSEL_OUTP);

	int i = 0;
	
    // Blink
    while (i < 1)
    {
	// Turn it on
	bcm2835_gpio_write(PIN, HIGH);
	
	cout<<"OPEN_THE_DOOR";
	
	// wait a bit
	bcm2835_delay(500);
	
	// turn it off
	bcm2835_gpio_write(PIN, LOW);
	
	// wait a bit
	bcm2835_delay(500);
	i++;
    }
    bcm2835_close();
    return 0;
}


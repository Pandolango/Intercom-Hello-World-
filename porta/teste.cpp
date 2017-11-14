#include <stdio.h>
#include <unistd.h>
#include <sys/io.h>

#define LPT1 0x0378
#define HIGH 255
#define LOW 0

int main()
{
    if (ioperm(LPT1,1,1) == -1)
    {
        printf("PORTE CHIUSE, ESCO!\n");
        return -1;
    }
    printf("PORTE APERTE SU %d\n", LPT1);
    while (1)
    {
        outb(HIGH, LPT1); // seta valor alto no pino da saída analógica
        sleep(5);
        outb(LOW, LPT1); // seta valor baixo no pino de saída analógica
        sleep(5);
    }
    return 0;
}

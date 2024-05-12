#include "mbed.h"
#include "TEA5767.h"
#include "TextLCD.h"

#define address 0xC0 // Indirizzo modulo radio FM TEA5767

TEA5767 radio(D14, D15, address); // SDA, SCL e indirizzo
TextLCD screen(D12, D11, D5, D4, D3, D2); // RS, E e pin da D4 a D7
DigitalIn freqDown(D7); // Bottone per abbassare la frequenza
DigitalIn freqUp(D8); // Bottone per alzare la frequenza

int main () {
    float freqMin = 87.5, freqMax = 107.5, frequenza = freqMin, incremento = 0.25;
    radio.SetBand('e'); // Imposta la banda di frequenze europea
    radio.SetFrequency(frequenza, 'h'); // Imposta la frequenza
    screen.printf("Frequenza\n%.2f Hz\n", frequenza);
    while (true) {
        if (freqUp == 0) {
            frequenza += float(incremento); // Aumenta la frequenza
            if (frequenza > freqMax) // Contollo sulla frequeza massima
                frequenza = freqMin;
            radio.SetFrequency(frequenza, 'h');
            screen.printf("Frequenza\n%.2f Hz\n", frequenza);
            wait_us(20000); // Asetta 0.2 s
        }
        else if (freqDown == 0) {
            frequenza -= float(incremento); // Abbassa la frequenza
            if (frequenza < freqMin) // Controllo sulla frequenza minima
                frequenza = freqMax;
            radio.SetFrequency(frequenza, 'h');
            screen.printf("Frequenza\n%.2f Hz\n", frequenza);
            wait_us(200000); // Asetta 0.2 s
        }
    }
}

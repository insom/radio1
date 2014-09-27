#include <VirtualWire.h>

void setup() {
    Serial.begin(9600);
    pinMode(13, OUTPUT);
    pinMode(9, OUTPUT);
    vw_set_ptt_inverted(true);
    vw_setup(2000);
    vw_set_rx_pin(11);
    vw_rx_start();
}

void loop() {
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;
    int i;

    if(vw_have_message()) {
        digitalWrite(9, true);
        if(vw_get_message(buf, &buflen)) {
            digitalWrite(13, true);
            for(i = 0; i < buflen; i++) {
                Serial.print(buf[i], HEX);
            }
            Serial.println("");
            digitalWrite(13, false);
        }
        digitalWrite(9, false);
    }
}

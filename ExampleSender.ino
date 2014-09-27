#include <VirtualWire.h>

void setup() {
    vw_set_ptt_inverted(false);
    vw_set_ptt_pin(13);
    vw_set_tx_pin(11);
    vw_setup(2000);
}

void loop() {
    const char *msg = "hello";
    vw_send((uint8_t *)msg, strlen(msg));
    vw_wait_tx();
    delay(2000);
}

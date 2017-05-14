#include <ASN1ino.h>

ASN1ino asn1ino(&Serial) ;

void setup() {
    Serial.begin(115200) ;
    for (uint8_t pin = 2; pin < 14 ; pin++) {
        pinMode(pin, OUTPUT) ;
    }
    for (uint8_t pin = 2; pin < 14 ; pin++) {
        digitalWrite(pin, LOW) ;
    }

    asn1ino.setCommandHadler(commandHandler) ;
}

void loop() {
    asn1ino.poll() ;
}

void commandHandler(ASN1ino *asn1Ino, Command_t *cmd) {
    if (!cmd || !asn1Ino) {
        return ;
    }

    if (cmd->command == 'M' && cmd->args && cmd->args->arg2) {
        pinMode(cmd->args->arg1, *cmd->args->arg2) ;
        asn1ino.sendCommand('M', cmd->args->arg1, *cmd->args->arg2) ;
    } else if (cmd->command == 'V' && cmd->args && cmd->args->arg2) {
        digitalWrite(cmd->args->arg1, *cmd->args->arg2) ;
        asn1ino.sendCommand('V', cmd->args->arg1, *cmd->args->arg2) ;
    } else if (cmd->command == 'v' && cmd->args) {
        byte value = digitalRead(cmd->args->arg1) ;
        asn1ino.sendCommand('v', cmd->args->arg1, value) ;
    } else if (cmd->command == 'a' && cmd->args) {
        byte value = analogRead(cmd->args->arg1) ;
        asn1ino.sendCommand('a', cmd->args->arg1, value) ;
    }
}


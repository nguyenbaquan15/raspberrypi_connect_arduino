# raspberrypi_connect_arduino
C, Python, Arduino

# Hardware Connection

## Raspberry Pi ¡ê Arduino UART Wiring

```text
Raspberry Pi                 Arduino
-----------                  --------
Pin 8  (TX)  ------------->  Pin 0 (RX)
Pin 10 (RX) <-------------   Pin 1 (TX)
Pin 6  (GND) ------------->  GND
```

Note: Because the Raspberry Pi uses 3.3V logic levels while the Arduino uses 5V logic levels, a logic level converter is required for UART communication
# python 2.7
import serial
import time

# UART port: Pin 8: TX, Pin 10: RX
ser = serial.Serial('/dev/ttyAMA0',115200)

while True:
	for i in range(4):
		packet = "turn_on,{}\n".format(i)
		ser.write(packet.encode())
		time.sleep(0.1)

	for i in range(4):
		packet = "turn_off,{}\n".format(i)
                ser.write(packet.encode())
                time.sleep(0.1)

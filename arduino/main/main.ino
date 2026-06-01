#define LED_1 2
#define LED_2 3
#define LED_3 4
#define LED_4 5

String inputString = "";      // a String to hold incoming data
bool stringComplete = false;  // whether the string is complete

void setup() {
  // initialize serial:
  Serial.begin(115200);

  // reserve 200 bytes for the inputString:
  inputString.reserve(200);

  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  pinMode(LED_4, OUTPUT);

}

void loop() {

  if (stringComplete) {
    inputString.trim();
    int commaPos = inputString.indexOf(',');

    if(commaPos!=-1)
    {
      String command = inputString.substring(0, commaPos);
      int value = inputString.substring(commaPos + 1).toInt();

      if(command == "turn_on")
      {
        switch (value)
        {
          case 0:
            digitalWrite(LED_1,HIGH);
            break;
          case 1:
            digitalWrite(LED_2,HIGH);
            break;
          case 2:
            digitalWrite(LED_3,HIGH);
            break;
          case 3:
            digitalWrite(LED_4,HIGH);
            break;
          default:
            break;
        }
      }
      else if (command == "turn_off")
      {
        switch (value)
        {
          case 0:
            digitalWrite(LED_1,LOW);
            break;
          case 1:
            digitalWrite(LED_2,LOW);
            break;
          case 2:
            digitalWrite(LED_3,LOW);
            break;
          case 3:
            digitalWrite(LED_4,LOW);
            break;
          default:
            break;
        }
      }
      else
      {
        ;
      }
    }

    inputString = "";
    stringComplete = false;

  }
  
}

/*
  SerialEvent occurs whenever a new data comes in the hardware serial RX. This
  routine is run between each time loop() runs, so using delay inside loop can
  delay response. Multiple bytes of data may be available.
*/
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}


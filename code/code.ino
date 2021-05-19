#define enablePin 11
#define in1Pin 10
#define in2Pin 9
#define schalterOben A4
#define schalterUnten A3

char stringComplete = "";
String inputString = "1";
int bedingung = 0;
boolean directionM;

void setup() {

  Serial.begin(9600);
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(enablePin, OUTPUT);
  pinMode(schalterOben, INPUT_PULLUP);
  pinMode(schalterUnten, INPUT_PULLUP);

}

void loop() {
  
 //Serial.println("{\"trigger\" : \"B\", \"value\": \"0\"}");
  //Serial.print("/n");
  delay(100);
  //Serial.println("{ trigger: \"T\", status: \"test\"}");
  Serial.print("vumsadsdasdasdsa");
  boolean buttonState;
  int speedM = 250;
  int obenState = digitalRead(schalterOben);
  int untenState = digitalRead(schalterUnten);
  switch (stringComplete) {

    case 'O':
      buttonState = 0;
      directionM = 1;
      setMotor(speedM, directionM);
      inputString = "";
      stringComplete = "";
      break;

    case 'C':
      buttonState = 0;
      directionM = 0;
      setMotor(speedM, directionM);
      inputString = "";
      stringComplete = "";
      break;
      
  }

  if (obenState == 0 && buttonState == 0 && directionM == 1) {
    setMotor(0, directionM);
    buttonState = 1;
    
  }

  if (untenState == 0 && buttonState == 0 && directionM == 0) {
    setMotor(0, directionM);
    buttonState = 1;
  }

}



void serialEvent() {

  while (Serial.available()) {
    char inChar = Serial.read();
    //Serial.println(inChar);
    switch (inChar) {

      case 'O':
        stringComplete = 'O';
        break;

      case 'C':
        stringComplete = 'C';
        break;

      default:
        inputString += inChar;
        break;
    }
  }

}

void setMotor(int speedM, boolean directionM) {

  analogWrite(enablePin, speedM);
  digitalWrite(in1Pin, !directionM);
  digitalWrite(in2Pin, directionM);

}

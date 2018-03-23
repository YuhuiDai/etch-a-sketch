#define BUTTONPIN 6
#define XPIN A0
#define YPIN A5

int x = 0;  
int y = 0;
int buttonState = 0;
unsigned long targetTime=0;
const unsigned long interval=1000; //TODO: How fast should we read
const String reset = "rst";
const String color = "color";
bool changeColor = false;


void setup(){
  // TODO: begin the serial connection with a baudrate of 115200
  Serial.begin(115200);   
  // initialize the pushbutton pin as an input:
  pinMode(BUTTONPIN, INPUT);

}

void loop(){
   
	if(millis()>=targetTime){
    buttonState = digitalRead(BUTTONPIN);
    if (buttonState == LOW) {
        Serial.println(reset.c_str());
      }
    if (changeColor) {
      Serial.println(color.c_str());
      changeColor = false;
    } else {
      changeColor = true;  
    }
		targetTime= millis()+interval;
		 //TODO: Add other sensor read outs
     //TODO: convert values into a string https://www.arduino.cc/en/Tutorial/StringConstructors
		 //TODO: combine them into a string that can be understood by server.js
    int curr_x = analogRead(XPIN);
    int xp =  map(curr_x, 0, 1023, 0, 500);
    int curr_y = analogRead(YPIN);
    int yp =  map(curr_y, 0, 1023, 0, 500);
    String newPosition = String(xp)+","+String(yp)+ "\r\n";
    Serial.println(newPosition);
		 //TODO: send the string over serial


	}
	// TODO: Detect if you want to reset the screen(shake the etch-a-sketch)
  // TODO: write the reset message(see server.js) to the serial port

}

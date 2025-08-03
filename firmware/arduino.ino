const int button1 = 1;
const int button2 = 2; 
const int button3 = 3;
const int button4 = 4;
const int led1 = 5;
const int led2 = 6;
const int led3= 7;
const int led4 = 8;
const int buzzer = 9;

const unsigned long longPressTime = 3000;

bool isButtonHeld = false;
unsigned long whenPressed = 0;
int whichButton = 0;

unsigned long startTime = 0;
unsigned long timerDuration = 0;
bool isTimerRunning = false;

void setup(){
    pinMode(button1, INPUT_PULLUP);
    pinMode(button2, INPUT_PULLUP);
    pinMode(button3, INPUT_PULLUP);
    pinMode(button4, INPUT_PULLUP);
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(led3, OUTPUT);
    pinMode(led4, OUTPUT);
    pinMode(buzzer, OUTPUT);
    turnOffLeds();
    beep();
}

void loop(){
    if(!isTimerRunning){
        checkButtonHold(button1, 1);
        checkButtonHold(button2, 2);
        checkButtonHold(button3, 3);
        checkButtonHold(button4, 4);
    }
    if (isTimerRunning){
        unsigned long timePassed = millis() - startTime;
        if(timePassed >= timerDuration *0.25) digitalWrite(led1, HIGH);
        if(timePassed >= timerDuration *0.5) digitalWrite(led2, HIGH);
        if(timePassed>= timerDuration *0.75) digitalWrite(led3, HIGH);
        if(timePassed>=timerDuration){
            digitalWrite(led4, HIGH);
            delay(200);
            beepOnce();
        }
    }
}


void checkButtonHold(int btnPin, intbtnID){
    bool isPressed = digitalRead(btnPin)==LOW;
    if (isPressed && !isButtonHeld){
        isButtonHeld = true;
        whenPressed = millis();
        whichButton = btnID;
    }
    if(!isPressed && isButtnoHeld && whichButton == btnID){
        unsigned long howLong = millis() - whenPressed;
        isButtonHeld = false;
        if(howLong>=longPressTime){
            startLongTimer(btnID);
            playEasterEgg(btnID);
        } else{
            startShortTimer(btnID);
        }
    }
}

void startShortTimer(intbtnID){
    switch(btnID){
        case 1: startTimer(3000); break;
        case 2: startTimer(6000); break;
        case 3: startTimer(30000); break;
        case 4: startTimer(60000); break;
    }
}

void startLongTimer(btnID){
    switch(btnID){
        case 1: startTimer(180000); break;
        case 2: startTimer(270000); break;
        case 3: startTimer(360000); break;
        case 4: startTimer(720000); break;
    }
}

void startTimer(unsigned long howLong){
    timerDuration = howLong;
    startTimer = millis();
    isTimerRunning = true;
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    delay(100);
    turnOffLeds();
    beepOnce();
}

void turnOffLeds(){
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
}

void beepOnce(){
    digitalWrite(buzzer, HIGH);
    delay(150);
    digitalWrite(buzzer, LOW);
}

void playEasterEgg(int btnID){
    switch(btnID){
        case 1:
        for (int i = 0; i<3; i++){
            digitalWrite(led1, HIGH); delay(100); digitalWrite(led1, LOW);
            digitalWrite(led2, HIGH); delay(100); digitalWrite(led2, LOW);
            digitalWrite(led3, HIGH); delay(100); digitalWrite(led3, LOW);
            digitalWrite(led4, HIGH); delay(100); digitalWrite(led4, LOW);
        } break;


        case 2:
        for (int i = 0; i<5; i++){
            digitalWrite(led1, HIGH); 
            digitalWrite(led2, HIGH); 
            digitalWrite(led3, HIGH);
            digitalWrite(led4, HIGH); 
            delay(150);
            turnOffLeds();
            delay(150);
        } break;

        case 3:
        for (int i = 0; i<2; i++){
            digitalWrite(led1, HIGH); delay(100);
            digitalWrite(led2, HIGH); delay(100);
            digitalWrite(led3, HIGH); delay(100);
            digitalWrite(led4, HIGH); delay(100);
            turnOffLeds(); delay(100);
            digitalWrite(led4, HIGH); delay(100);
            digitalWrite(led3, HIGH); delay(100);
            digitalWrite(led2, HIGH); delay(100); 
            digitalWrite(led1, HIGH); delay(100);
            turnOffLeds(); delay(100);
        } break;


        case 4:
        for (int i = 0; i<6; i++){
            digitalWrite(led1, HIGH);
            digitalWrite(led2, LOW);
            digitalWrite(led3, HIGH); 
            digitalWrite(led4, LOW);
            beepOnce(); delay(100);
            turnOffLeds(); delay(100);
        } break;
    }
}
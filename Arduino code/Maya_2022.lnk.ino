





const int TRIG_PIN = 8;
const int ECHO_PIN = 9;
const int LED_PIN  = 3;
int beep = 5;
const int DISTANCE_THRESHOLD = 10;


float duration_us, distance_cm;

// Voorbereiding

void setup() {
  Serial.begin (9600);      
  pinMode(TRIG_PIN, OUTPUT); 
  pinMode(ECHO_PIN, INPUT );  
  pinMode(LED_PIN, OUTPUT); 
  pinMode(beep, OUTPUT); 
}

void loop() {

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);


  duration_us = pulseIn(ECHO_PIN, HIGH);


// Formule voor afstand

  distance_cm = 0.017 * duration_us;



// Speaker gaat af wanneer ofstand kleiner is dan 'DISTANCE_THRESHOLD' 

  if (distance_cm < DISTANCE_THRESHOLD)

    digitalWrite(beep, HIGH); //turn on the speaker
  
  else

  
   digitalWrite(beep, LOW); //turn off the speaker


  // Speaker gaat ook af wanneer ofstand kleiner is dan 5cm

  if (distance_cm < DISTANCE_THRESHOLD)

    digitalWrite(LED_PIN, HIGH); // turn on LED
  
  else

  
    digitalWrite(LED_PIN, LOW);  // turn off LED
   

  //Enkel voor serial monitor

  Serial.print("distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");

//Hoelang het duurt voor de speaker aangaat

  delay(5000);
}

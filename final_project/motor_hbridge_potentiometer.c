
// Analog Pins for Motor 
int enA = 9;
int in1 = 8;
int in2 = 7;
int motor_speed = 0;
 
// Analog Pins for Potentiometer
int potentiometer_analog_input = A0;  

struct data{
    float potentiometer_analog_input;
    int motor_speed;
};
struct data data;

void setup(){
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
}
 
void loop(){
  // Setting Direction of Motor, based on the permutation of HIGH and LOW
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  
  // Read the values from the potentiometers
  data.potentiometer_analog_input = analogRead(potentiometer_analog_input); 
  
  // Use the map function to automatically scale analog values from a potentiometer scale to a motor scale
  data.motor_speed = map(data.potentiometer_analog_input, 0, 1023, 0, 255);
  
  // Adjust to prevent "buzzing" at very low speed
  if(data.motor_speed < 8){
    data.motor_speed = 0;
  }
  // Set the motor speeds
  analogWrite(enA, data.motor_speed);
}
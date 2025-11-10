/*Change all the ? in the code and add code in ??? to Control the speed of rotation.*/

#define IN1   27  // Replace the ? with the GPIO pin you selected to connect IN1
#define IN2   32   // Replace the ? with the GPIO pin you selected to connect IN2
#define A  34 // Replace the ? with the GPIO pin you selected to connect encoder A
#define B  35 // Replace the ? with the GPIO pin you selected to connect encoder B
#define PWM 14  // Replace the ? with the GPIO pin you selected to output PWM

int A_data=0;
int B_data=0;

String command;

void setup() {
  /*setup baud and pin mode */
  Serial.begin(9600);

  pinMode(IN1, OUTPUT);  // Set IN1 as an output pin
  pinMode(IN2, OUTPUT);  // Set IN2 as an output pin
  pinMode(PWM, OUTPUT);  // Set PWM as an output pin

  pinMode(A, INPUT);  // Set A as an input pin
  pinMode(B, INPUT);  // Set B as an input pin

  /*Set a rotation direction: Forward*/
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW); 

}

void loop() {
   
    if (Serial.available() > 0) {
        command = Serial.readStringUntil('\n'); // Read the incoming command
        command.trim(); // Remove any leading or trailing whitespace
        if (command == "0") {
        // output PWM signals with 0% duty cycle
        analogWrite(PWM,int(0));  
        } 
        else if (command == "25") {
        // output PWM signals with 25% duty cycle
        analogWrite(PWM,int(255*0.25));   
        }
        else if (command == "50") {
        // output PWM signals with 50% duty cycle
        analogWrite(PWM,int(255*0.50));   
        }
        else if (command == "75") {
        // output PWM signals with 75% duty cycle
        analogWrite(PWM,int(255*0.75));   
        }
        else if (command == "100") {
        // output PWM signals with 100% duty cycle
        analogWrite(PWM,int(255));   
        }
        }
    // Read values of A and B
       A_data=digitalRead(A);
       B_data=digitalRead(B);
    // Plot A B in Serial Plotter
       Serial.print("A:");
       Serial.print(A_data);
       Serial.print(",");
       Serial.print("B:");
       Serial.print(B_data);
       Serial.println("\t"); 
    
}

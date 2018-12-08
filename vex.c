// will vary depending on motor configuration
// just a sample motor config
#pragma config(StandardModel, "VEX Launchbot")
// 627 ticks per revolution

// drive functions
void moveForward(int power, long revolutions) {
		resetMotorEncoder(port1);
		resetMotorEncoder(port3);
		int distance = revolutions * 627;  // converting revolutions to number of ticks
		while(getMotorEncoder(port1) < distance && getMotorEncoder(port3) < distance) {
			motor[port1] = power;
			motor[port2] = power;
			motor[port3] = power;
			motor[port4] = power;
		}
	  motor[port1] = 0;
		motor[port2] = 0;
		motor[port3] = 0;
		motor[port4] = 0;

}

void turnRight(int power, long revolutions) {
	 resetMotorEncoder(port1);
	 int distance = revolutions * 627;  // converting revolutions to number of ticks
	 while(getMotorEncoder(port1) < distance){
   		motor[port1] = power;
   		motor[port2] = power;
 	 }

 	 motor[port1]  = 0;
   motor[port2] = 0;
}

void turnLeft(int power, long revolutions) {
	resetMotorEncoder(port3);
	int distance = revolutions * 627;  // converting revolutions to number of ticks
	 while(getMotorEncoder(port3) < distance){
   		motor[port3] = power;
   		motor[port4] = power;
 	 }
 	 motor[port3]  = 0;
   motor[port4] = 0;
}

void moveBackward(int power, long revolutions) {
		power = power * (0-1);
		resetMotorEncoder(port1);
		resetMotorEncoder(port3);
		int distance = revolutions * 627;  // converting revolutions to number of ticks

		while(getMotorEncoder(port1) < distance && getMotorEncoder(port3) < distance) {
			motor[port1] = power;
			motor[port2] = power;
			motor[port3] = power;
			motor[port4] = power;
		}
	  motor[port1] = 0;
		motor[port2] = 0;
		motor[port3] = 0;
		motor[port4] = 0;

}
// main power value most commonly used
int main_power = 70;

task main() {
	// for all motor functions
	// 1st arg: motor power
	// 2nd arg: number of ticks for the encoder
	// 627 ticks per revolution
	moveForward(main_power,5);
	turnRight(main_power, 2.5);
	turnLeft(main_power, 2.5);
	moveBackward(main_power, 5);
}

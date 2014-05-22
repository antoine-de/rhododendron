#include <Servo.h>

struct BtInput
{
	double pos_lon, pos_lat;
	double target_lon, target_lat;

	BtInput(double plon, double plat, double tlon, double tlat): 
		pos_lon(plon), pos_lat(plat),
		target_lon(tlon), target_lat(tlat) {}
};

struct CompassInput
{

};

struct BluetoothConnector
{
	BluetoothConnector(int serial = 9600) 
	{
		pinMode(13,OUTPUT);
		Serial.begin(9600);
	}

	BtInput read_flow() 
	{
		//mock
		return BtInput(0., 1., 2., 3.);
	}
};

struct Dir
{
	//TODO

	Dir() {}
};

Dir compute_directions(const BtInput bt_input, const CompassInput compa_input)
{
	return Dir();
}

struct CompassConnector
{
	CompassInput read_flow()
	{
		return CompassInput();
	}
};

BluetoothConnector bt;
CompassConnector compass;
DisplayManager display_manager;

struct DisplayManager
{
	Servo myservo;
	int servo_pos = 0;
	DisplayManager()
	{
		myservo.attach(9);  // attaches the servo on pin 9 to the servo object
	}

	void send_to_display(const Dir dir)
	{
		for(pos = 0; pos < 180; pos += 1)
		{
			myservo.write(pos);
			delay(15);
		}

		for(pos = 180; pos>=1; pos-=1)
		{
			myservo.write(pos);              // tell servo to go to position in variable 'pos'
			delay(15);                       // waits 15ms for the servo to reach the position
		} 
	}
};

void setup() 
{

}

void loop()
{
	BtInput i = bt.read_flow();

	CompassInput c_input = compass.read_flow();

	Dir computed_output = compute_directions(i, c_input);

	display_manager.send_to_display1(computed_output);
}


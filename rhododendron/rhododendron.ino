

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

void send_to_display1(const Dir dir)
{

}

void setup() 
{

}

void loop()
{
	BtInput i = bt.read_flow();

	CompassInput c_input = compass.read_flow();

	Dir computed_output = compute_directions(i, c_input);

	send_to_display1(computed_output);
}


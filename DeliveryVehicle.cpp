#include "DeliveryVehicle.H"
#include <iostream>
#include <cstring>

int DeliveryVehicle::PROFIT_PER_DELIVERY = 4;

//************************************************************************************* 
// Function name : DeliveryVehicle
//
// Description : Constructor for DeliveryVehicle class
//
// Parameters:  1) ID of the vehicle
//				2) quality of the vehicle
//
// Return value : none
//*************************************************************************************
DeliveryVehicle::DeliveryVehicle(const char* ID, Quality quality) : stop_(0), quality_(quality), type_(normal)
{
	ID_ = new char[strlen(ID) + 1];
	strcpy(ID_, ID);
}

//************************************************************************************* 
// Function name : ~DeliveryVehicle
//
// Description : Destructor for DeliveryVehicle class
//
// Parameters:  none
//
// Return value : none
//*************************************************************************************
DeliveryVehicle::~DeliveryVehicle()
{
	delete[] ID_;
	while(!trunk_.empty())
	{
		delete trunk_.front();
		trunk_.pop();
	}
}

//************************************************************************************* 
// Function name : addParcel
//
// Description : Adds a parcel to the trunk of a delivery vehicle
//
// Parameters:  1) a pointer to a parcel to add to the trunk
//
// Return value : true if the vehicle accepted the parcel, false if the add failed
//*************************************************************************************
bool DeliveryVehicle::addParcel(Parcel* parcel)
{
	if (trunk_.size() >= MAX_TRUNK || parcel == NULL)
		return false;
	trunk_.push(parcel);
	return true;
}

// helper func, return the dist from point A to B
//************************************************************************************* 
// Function name : countDist
//
// Description : Counts the distance between a vehicle's current location and a future
//				 location
//
// Parameters:  1) a starting station
//				2) an ending station
//
// Return value : the distance between the two stations
//*************************************************************************************
int countDist(int start, int end)
{
	int count = 0;
	for (int drive = start; drive != end; drive = ((drive + 1) % NUM_OF_STOPS))
		count++;

	return count;
}

//************************************************************************************* 
// Function name : performDeliveryDay
//
// Description : delivers all parcels (that the vehicle can possibly deliver)
//
// Parameters:  1) a pointer to a variable that store how many parcels were delivered
//
// Return value : the profit earned by the vehicle
//*************************************************************************************
int DeliveryVehicle::performDeliveryDay(int* numberOfDeliveries)
{
	int driveDist = MAX_DRIVE;
	int profit = -quality_;
	int deliveries = 0;
	int distanceDriven = 0;

	// edge case
	if (trunk_.empty())
	{
		cout << "No parcels to deliver for vehicle " << ID_ << endl;
		*numberOfDeliveries = deliveries;
		return 0;
	}
	// if we get here, there is at least one package in the trunk
	cout << "Starting deliveries for vehicle " << ID_ << endl;
	Parcel* top = trunk_.front();
	// continue until (1) there is no more parcel to deliver (2) the dest is too far way
	while (!trunk_.empty() && countDist(stop_, top->dest_) <= driveDist)
	{
		//print 
		cout << "Delivering parcel " << top->ID_ << " to position " << top->dest_ << endl;
		// drive to the stop
		driveDist -= countDist(stop_, top->dest_); //update max driving distance for day
		distanceDriven += countDist(stop_, top->dest_);
		profit -= countDist(stop_, top->dest_); //add fuel costs (num of stations traveled) to daily price of vehicle (total loss for one day)
		cout << "Fuel consumed: " << countDist(stop_, top->dest_) << " Revenue is: " << PROFIT_PER_DELIVERY << endl;
		stop_ = top->dest_;	//update vehicle location
		// deliver parcel
		delete trunk_.front();
		trunk_.pop();
		if (!trunk_.empty())
		{
			top = trunk_.front();
		}
		deliveries++; //update number of deliveries
		profit += PROFIT_PER_DELIVERY; // add profit from delivering package to total daily costs (profits)
	}
	cout << "Total travel distance is " << distanceDriven << endl;
	cout << "Total revenue is " << profit << endl;
	*numberOfDeliveries = deliveries;
	return profit;
}

// helper functions

//************************************************************************************* 
// Function name : getType
//
// Description : gets the type of vehicle (regular, fast, professional)
//
// Parameters:  none
//
// Return value : the type of vehicle (regular, fast, professional)
//*************************************************************************************
VehicleType DeliveryVehicle::getType()
{
	return type_;
}

//************************************************************************************* 
// Function name : getNumOfParcel
//
// Description : gets the number of parcels in the vehicle's trunk
//
// Parameters:  none
//
// Return value : the number of parcels in the vehicle's trunk
//*************************************************************************************
int DeliveryVehicle::getNumOfParcel()
{
	return trunk_.size();
}

//************************************************************************************* 
// Function name : getStop
//
// Description : gets the current location of the vehicle
//
// Parameters:  none
//
// Return value : the current location of the vehicle
//*************************************************************************************
int DeliveryVehicle::getStop()
{
	return stop_;
}

//************************************************************************************* 
// Function name : getVehicleID
//
// Description : gets the ID of the vehicle
//
// Parameters:  none
//
// Return value : the ID of the vehicle
//*************************************************************************************
const char* DeliveryVehicle::getVehicleID() const
{
	return ID_;
}
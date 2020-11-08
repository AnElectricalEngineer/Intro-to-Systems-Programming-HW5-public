#include "FastDeliveryVehicle.H"
#include <iostream>

//************************************************************************************* 
// Function name : FastDeliveryVehicle
//
// Description : Constructor for FastDeliveryVehicle class
//
// Parameters:  1) ID of the vehicle
//				2) quality of the vehicle
//
// Return value : none
//*************************************************************************************
FastDeliveryVehicle::FastDeliveryVehicle(const char* ID, Quality quality) : DeliveryVehicle(ID, quality)
{
	// change type
	type_ = fast;
}

// help func, return the dist from point A to B
//************************************************************************************* 
// Function name : countDist2
//
// Description : Counts the distance between a vehicle's current location and a future
//				 location
//
// Parameters:  1) a starting station
//				2) an ending station
//
// Return value : the distance between the two stations
//*************************************************************************************
int countDist2(int start, int end)
{
	int count = 0;
	for (int drive = start; drive != end; drive = ((drive + 1) % NUM_OF_STOPS))
		count++;

	return count;
}

//************************************************************************************* 
// Function name : performDeliveryDay (overrides that of DeliveryVehicle)
//
// Description : delivers all parcels (that the vehicle can possibly deliver)
//
// Parameters:  1) a pointer to a variable that store how many parcels were delivered
//
// Return value : the profit earned by the vehicle
//*************************************************************************************
int FastDeliveryVehicle::performDeliveryDay(int* numberOfDeliveries)
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
	// continue until (1) there is no more parcel to deliver (2) the dest is to far way
	while (!trunk_.empty() && countDist2(stop_, top->dest_) <= driveDist)
	{
		//print 
		cout << "Delivering parcel " << top->ID_ << " to position " << top->dest_ << endl;
		// drive to the stop
		driveDist -= countDist2(stop_, top->dest_); //update max driving distance for day
		distanceDriven += countDist2(stop_, top->dest_);
		profit += countDist2(stop_, top->dest_); // per stop we lose and get (-1+2)
		cout << "Fuel consumed: " << countDist2(stop_, top->dest_) << " Revenue is: " << 2 * countDist2(stop_, top->dest_) << endl;
		stop_ = top->dest_;
		// deliver parcel
		delete trunk_.front();
		trunk_.pop();
		if (!trunk_.empty())
		{
			top = trunk_.front();
		}
		deliveries++;
	}
	//print
	cout << "Total travel distance is " << distanceDriven << endl;
	cout << "Total revenue is " << profit << endl;
	*numberOfDeliveries = deliveries;
	return profit;
}
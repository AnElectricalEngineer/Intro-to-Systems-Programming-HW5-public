#include "ProfessionalDeliveryVehicle.H"
#include <iostream>

//************************************************************************************* 
// Function name : ProfessionalDeliveryVehicle
//
// Description : Constructor for ProfessionalDeliveryVehicle class
//
// Parameters:  1) ID of the vehicle
//				2) quality of the vehicle
//
// Return value : none
//*************************************************************************************
ProfessionalDeliveryVehicle::ProfessionalDeliveryVehicle(const char* ID, Quality quality) : DeliveryVehicle(ID, quality)
{
	// change type
	type_ = professional;
}

//************************************************************************************* 
// Function name : countDist3
//
// Description : Counts the distance between a vehicle's current location and a future
//				 location
//
// Parameters:  1) a starting station
//				2) an ending station
//
// Return value : the distance between the two stations
//*************************************************************************************
int countDist3(int start, int end)
{
	int count = 0;
	for (int drive = start; drive != end; drive = ((drive + 1) % NUM_OF_STOPS))
		count++;

	return count;
}

//adds parcel to vehicle returns false if add failed
//************************************************************************************* 
// Function name : addParcel (overrides that of DeliveryVehicle class)
//
// Description : Adds a parcel to the trunk of a delivery vehicle
//
// Parameters:  1) a pointer to a parcel to add to the trunk
//
// Return value : true if the vehicle accepted the parcel, false if the add failed
//*************************************************************************************
bool ProfessionalDeliveryVehicle::addParcel(Parcel* parcel)
{
	if (trunk_.size() >= MAX_TRUNK || parcel == NULL)
		return false;
	//if we get here, trunk is not full
	if (trunk_.empty())
	{
		if (countDist3(stop_, parcel->dest_) > PROFIT_PER_DELIVERY)
			return false;
		//if we get here, trunk is empty, but parcel is profitable
		trunk_.push(parcel);
		return true;
	}
	//if we get here, there is at least one parcel already in the trunk, and the trunk is not full
	if (countDist3(trunk_.back()->dest_, parcel->dest_) > PROFIT_PER_DELIVERY)
		return false;
	trunk_.push(parcel);
	return true;
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
int ProfessionalDeliveryVehicle::performDeliveryDay(int* numberOfDeliveries)
{
	int driveDist = MAX_DRIVE;
	int profit = -quality_;
	int deliveries = 0;
	int distanceDriven = 0;

	// edge case
	if (trunk_.empty())
	{
		cout << "No parcels to deliver for vehicle " << ID_ << endl;
		cout << "Revenue per distance: no distance" << endl;
		cout << "Revenue per parcel: no parcels" << endl;
		*numberOfDeliveries = deliveries;
		return 0;
	}
	// if we get here, there is at least one package in the trunk
	cout << "Starting deliveries for vehicle " << ID_ << endl;
	Parcel* top = trunk_.front();
	// continue until (1) there is no more parcel to deliver (2) the dest is to far way
	while (!trunk_.empty() && countDist3(stop_, top->dest_) <= driveDist)
	{
		//print 
		cout << "Delivering parcel " << top->ID_ << " to position " << top->dest_ << endl;
		// drive to the stop
		driveDist -= countDist3(stop_, top->dest_); //update max driving distance for day
		distanceDriven += countDist3(stop_, top->dest_);
		profit -= countDist3(stop_, top->dest_); //add fuel costs (num of stations traveled) to daily price of vehicle (total loss for one day)
		cout << "Fuel consumed: " << countDist3(stop_, top->dest_) << " Revenue is: " << PROFIT_PER_DELIVERY << endl;
		stop_ = top->dest_; //update vehicle location
		// deliver parcel
		delete trunk_.front();
		trunk_.pop();
		if (!trunk_.empty())
		{
			top = trunk_.front();
		}
		deliveries++;
		profit += PROFIT_PER_DELIVERY;// add profit from delivering package to total daily costs (profits)
	}
	//print
	cout << "Total travel distance is " << distanceDriven << endl;
	cout << "Total revenue is " << profit << endl;
	// add the print
	if(distanceDriven > 0)
	{
		const int averagePerDistance = profit / distanceDriven;
		cout << "Revenue per distance: " << averagePerDistance << endl;
	}
	else
	{
		cout << "Revenue per distance: no distance" << endl;
	}
	if(deliveries > 0)
	{
		const int averagePerParcels = profit / deliveries;
		cout << "Revenue per parcel: " << averagePerParcels << endl;
	}
	else
	{
		cout << "Revenue per parcel: no parcels" << endl;
	}
	*numberOfDeliveries = deliveries;
	return profit;
}
#include "FastDeliveryCompany.H"
#include <iostream>

//************************************************************************************* 
// Function name : FastDeliveryCompany
//
// Description : Constructor for FastDeliveryCompany class
//
// Parameters:  1) Initial Capital (Dollars)
//
// Return value : none
//*************************************************************************************
FastDeliveryCompany::FastDeliveryCompany(int money):DeliveryCompany(money){}

//************************************************************************************* 
// Function name : ~FastDeliveryCompany
//
// Description : Destructor for FastDeliveryCompany class
//
// Parameters:  none
//
// Return value : none
//*************************************************************************************
FastDeliveryCompany::~FastDeliveryCompany() {}

//************************************************************************************* 
// Function name : addVehicle
//
// Description : Adds a delivery vehicle to the list of vehicles for the company
//				 (overrides that of DeliveryVehicle class)
//
// Parameters:  1) a pointer to a vehicle
//
// Return value : True if the addition succeeded, false otherwise
//*************************************************************************************
bool FastDeliveryCompany::addVehicle(DeliveryVehicle* vehicle)
{
	if (vehicle == NULL) return false;
	
	if(vehicle->getType() != fast)
	{
		delete vehicle;
		return false;
	}
	//if we get here, we have received a fast delivery vehicle. Rest of the code/methods are same as regular company
	if (vehicleList_.empty())
	{
		vehicleList_.push_front(vehicle);
		if (receivedParcel_ == false)
			i_ = vehicleList_.begin();
		return true;
	}
	//if list is not empty, check if vehicle already exists
	for (auto i : vehicleList_)
	{
		if (i->getVehicleID() == vehicle->getVehicleID())
		{
			cout << "Can't add vehicle, it already exists" << endl;
			delete vehicle;
			return false;
		}
	}
	//if we get here, vehicle with same ID doesn't already exist in list
	vehicleList_.push_front(vehicle);
	if (receivedParcel_ == false)
		i_ = vehicleList_.begin();
	return true;
}

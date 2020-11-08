#ifndef FASTDELIVERYVEHICLE_H_
#define FASTDELIVERYVEHICLE_H_

#include "DeliveryVehicle.H"

class FastDeliveryVehicle : public DeliveryVehicle {
public:

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
	FastDeliveryVehicle(const char* ID, Quality quality);

	//************************************************************************************* 
	// Function name : ~FastDeliveryVehicle (can use that of DeliveryVehicle)
	//
	// Description : Destructor for FastDeliveryVehicle class
	//
	// Parameters:  none
	//
	// Return value : none
	//*************************************************************************************
	~FastDeliveryVehicle() {}

	//************************************************************************************* 
	// Function name : performDeliveryDay (overrides that of DeliveryVehicle)
	//
	// Description : delivers all parcels (that the vehicle can possibly deliver)
	//
	// Parameters:  1) a pointer to a variable that store how many parcels were delivered
	//
	// Return value : the profit earned by the vehicle
	//*************************************************************************************
	int performDeliveryDay(int* numberOfDeliveries);
};
#endif /* FASTDELIVERYVEHICLE_H_ */
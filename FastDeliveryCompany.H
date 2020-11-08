#ifndef FASTDELIVERYCOMPANY_H_
#define FASTDELIVERYCOMPANY_H_

#include "DeliveryCompany.H"

class FastDeliveryCompany:public DeliveryCompany{
public:
	//************************************************************************************* 
	// Function name : FastDeliveryCompany
	//
	// Description : Constructor for FastDeliveryCompany class
	//
	// Parameters:  1) Initial Capital (Dollars)
	//
	// Return value : none
	//*************************************************************************************
	FastDeliveryCompany(int money = 100);
	
	//************************************************************************************* 
	// Function name : ~FastDeliveryCompany
	//
	// Description : Destructor for FastDeliveryCompany class
	//
	// Parameters:  none
	//
	// Return value : none
	//*************************************************************************************
	~FastDeliveryCompany();
	
	//adds vehicle to vehicle queue
	//if vehicle exists - output is
	//Can't add vehicle, it already exists
	//
	//returns false if not possible and deletes vehicle
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
	bool addVehicle(DeliveryVehicle* vehicle);
};

#endif /* FASTDELIVERYCOMPANY_H_ */
#ifndef PROFESSIONALDELIVERYCOMPANY_H_
#define PROFESSIONALDELIVERYCOMPANY_H_

#include "DeliveryCompany.H"

class ProfessionalDeliveryCompany:public DeliveryCompany{
public:
	//************************************************************************************* 
	// Function name : ProfessionalDeliveryCompany
	//
	// Description : Constructor for ProfessionalDeliveryCompany class
	//
	// Parameters:  1) Initial Capital (Dollars)
	//
	// Return value : none
	//*************************************************************************************
	ProfessionalDeliveryCompany(int money = 100);
	
	//************************************************************************************* 
	// Function name : ~ProfessionalDeliveryCompany
	//
	// Description : Destructor for ProfessionalDeliveryCompany class
	//
	// Parameters:  none
	//
	// Return value : none
	//*************************************************************************************
	~ProfessionalDeliveryCompany();
	
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

#endif /* PROFESSIONALDELIVERYCOMPANY_H_ */

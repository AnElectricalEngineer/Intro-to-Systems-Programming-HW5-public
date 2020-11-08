#ifndef PROFESSIONALDELIVERYVEHICLE_H_
#define PROFESSIONALDELIVERYVEHICLE_H_

#include "DeliveryVehicle.H"

class ProfessionalDeliveryVehicle : public DeliveryVehicle {
public:
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
	ProfessionalDeliveryVehicle(const char* ID, Quality quality);

	//************************************************************************************* 
	// Function name : ~ProfessionalDeliveryVehicle (can use that of DeliveryVehicle)
	//
	// Description : Destructor for ProfessionalDeliveryVehicle class
	//
	// Parameters:  none
	//
	// Return value : none
	//*************************************************************************************
	~ProfessionalDeliveryVehicle() {}

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
	bool addParcel(Parcel* parcel);

	//Delivering parcel treasure to position 2
	//Fuel consumed: 2 Revenue is: 4
	//Total travel distance is 2
	//Total revenue is -2
	//Revenue per distance: -1
	//Revenue per parcel: -2
	//
	//if no parcels present:
	//No parcels to deliver for vehicle riksha
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

#endif /* PROFFESSIONALDELIVERYVEHICLE_H_ */
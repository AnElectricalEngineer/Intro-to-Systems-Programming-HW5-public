#ifndef DELIVERYCOMPANY_H_
#define DELIVERYCOMPANY_H_
#include "DeliveryVehicle.H"
#include <list>

class DeliveryCompany{
public:
	//************************************************************************************* 
	// Function name : DeliveryCompany
	//
	// Description : Constructor for DeliveryCompany class
	//
	// Parameters:  1) Initial Capital (Dollars)
	//
	// Return value : none
	//*************************************************************************************
	DeliveryCompany(int money = 100);
	
	//************************************************************************************* 
	// Function name : ~DeliveryCompany
	//
	// Description : Destructor for DeliveryCompany class
	//
	// Parameters:  none
	//
	// Return value : none
	//*************************************************************************************
	virtual ~DeliveryCompany();
	
	//adds vehicle to vehicle queue
	//if vehicle exists - output is
	//Can't add vehicle, it already exists
	//
	//returns false if not possible and deletes vehicle
	//************************************************************************************* 
	// Function name : addVehicle
	//
	// Description : Adds a delivery vehicle to the list of vehicles for the company
	//
	// Parameters:  1) a pointer to a vehicle
	//
	// Return value : True if the addition succeeded, false otherwise
	//*************************************************************************************
	virtual bool addVehicle(DeliveryVehicle* vehicle);
	
	//receives parcel if possible
	//returns false if not possible and deletes parcel
	//************************************************************************************* 
	// Function name : receiveParcel
	//
	// Description : Tries to receive a parcel and add it to the correct vehicle
	//
	// Parameters:  1) a pointer to a parcel
	//
	// Return value : True if the addition was successful, false otherwise
	//*************************************************************************************
	virtual bool receiveParcel(Parcel* parcel);
	
	//performs all deliveries possible for one day
	//returns false if no vehicles are present
	//output example:
	//Starting days deliveries:
	//<here comes output for each vehicle>
	//Total revenue for company is -2
	//************************************************************************************* 
	// Function name : performDeliveryDay
	//
	// Description : Has all the vehicles in the company's list deliver the packages that
	//				 they are able to deliver
	//
	// Parameters:  none
	//
	// Return value : True if at least one package was delivered, false otherwise
	//*************************************************************************************
	virtual bool performDeliveryDay();
	
	//displays company funds
	//output example:
	//Company balance is now 148
	//************************************************************************************* 
	// Function name : displayFunds
	//
	// Description : Displays the current capital of the company
	//
	// Parameters:  none
	//
	// Return value : none
	//*************************************************************************************
	virtual void displayFunds() const;
	
	//displays number of deliveries company has done so far
	//output example:
	//Till now company has delivered 3 parcels
	//************************************************************************************* 
	// Function name : displayNumberOfDeliveries
	//
	// Description : Displays the number of packages delivered by the company
	//
	// Parameters:  none
	//
	// Return value : none
	//*************************************************************************************
	virtual void displayNumberOfDeliveries() const;

protected:
	list<DeliveryVehicle*> vehicleList_;
	list<DeliveryVehicle*>::iterator i_;
	int totalMoney_;
	int numDeliveries_;
	bool receivedParcel_;
};

#endif /* DELIVERYCOMPANY_H_ */
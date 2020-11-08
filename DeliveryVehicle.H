#ifndef DELIVERYVEHICLE_H_
#define DELIVERYVEHICLE_H_

#include "Parcel.H"
#include <queue>

using namespace std;

typedef enum quality { good = 3, ok = 4, bad = 5 } Quality;
typedef enum vehicleType { normal = 1, fast = 2, professional = 3 } VehicleType;
#define MAX_TRUNK 5    // max number of parcels the vehicle can hold
#define MAX_DRIVE 12    // can move up to 12 stops per day
#define NUM_OF_STOPS 10 // from 0 to 9

class DeliveryVehicle {
public:
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
	DeliveryVehicle(const char* ID, Quality quality);

	//************************************************************************************* 
	// Function name : ~DeliveryVehicle
	//
	// Description : Destructor for DeliveryVehicle class
	//
	// Parameters:  none
	//
	// Return value : none
	//*************************************************************************************
	virtual ~DeliveryVehicle();

	//************************************************************************************* 
	// Function name : addParcel
	//
	// Description : Adds a parcel to the trunk of a delivery vehicle
	//
	// Parameters:  1) a pointer to a parcel to add to the trunk
	//
	// Return value : true if the vehicle accepted the parcel, false if the add failed
	//*************************************************************************************
	virtual bool addParcel(Parcel* parcel);

	//performs all possible deliveries for one day
	//output example
	//Starting deliveries for vehicle riksha
	//Delivering parcel hot_air to position 3
	//Fuel consumed: 3 Revenue is: 4
	//Delivering parcel mice to position 2
	//Fuel consumed: 9 Revenue is: 4
	//Total travel distance is 9
	//Total revenue is -4
	//
	//if no parcels present:
	//No parcels to deliver for vehicle riksha
	//
	//************************************************************************************* 
	// Function name : performDeliveryDay
	//
	// Description : delivers all parcels (that the vehicle can possibly deliver)
	//
	// Parameters:  1) a pointer to a variable that store how many parcels were delivered
	//
	// Return value : the profit earned by the vehicle
	//*************************************************************************************
	virtual int performDeliveryDay(int* numberOfDeliveries);

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
	VehicleType getType();
	
	//************************************************************************************* 
	// Function name : getNumOfParcel
	//
	// Description : gets the number of parcels in the vehicle's trunk
	//
	// Parameters:  none
	//
	// Return value : the number of parcels in the vehicle's trunk
	//*************************************************************************************
	int getNumOfParcel();

	//************************************************************************************* 
	// Function name : getStop
	//
	// Description : gets the current location of the vehicle
	//
	// Parameters:  none
	//
	// Return value : the current location of the vehicle
	//*************************************************************************************
	int getStop(); // probably we don't need this

	//************************************************************************************* 
	// Function name : getVehicleID
	//
	// Description : gets the ID of the vehicle
	//
	// Parameters:  none
	//
	// Return value : the ID of the vehicle
	//*************************************************************************************
	const char* getVehicleID() const;

	static int PROFIT_PER_DELIVERY;
	
protected:

	queue<Parcel*> trunk_;
	int stop_;
	char* ID_;
	Quality quality_;
	VehicleType type_;
};

#endif /* DELIVERYVEHICLE_H_ */
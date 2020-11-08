#include "DeliveryCompany.H"
#include <iostream>

//************************************************************************************* 
// Function name : DeliveryCompany
//
// Description : Constructor for DeliveryCompany class
//
// Parameters:  1) Initial Capital (Dollars)
//
// Return value : none
//*************************************************************************************
DeliveryCompany::DeliveryCompany(int money):totalMoney_(money), numDeliveries_(0), receivedParcel_(false)
{
	i_ = vehicleList_.begin();
}

//************************************************************************************* 
// Function name : ~DeliveryCompany
//
// Description : Destructor for DeliveryCompany class
//
// Parameters:  none
//
// Return value : none
//*************************************************************************************
DeliveryCompany::~DeliveryCompany()
{
	while(!vehicleList_.empty())
	{
		delete vehicleList_.back();
		vehicleList_.pop_back();
	}
}

//************************************************************************************* 
// Function name : addVehicle
//
// Description : Adds a delivery vehicle to the list of vehicles for the company
//
// Parameters:  1) a pointer to a vehicle
//
// Return value : True if the addition succeeded, false otherwise
//*************************************************************************************
bool DeliveryCompany::addVehicle(DeliveryVehicle* vehicle)
{
	if(vehicle == NULL) return false;
	
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
		if(i->getVehicleID() == vehicle->getVehicleID())
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

//************************************************************************************* 
// Function name : receiveParcel
//
// Description : Tries to receive a parcel and add it to the correct vehicle
//
// Parameters:  1) a pointer to a parcel
//
// Return value : True if the addition was successful, false otherwise
//*************************************************************************************
bool DeliveryCompany::receiveParcel(Parcel* parcel)
{
	if (parcel == NULL)
		return false;
	if (vehicleList_.empty()) //if company has no vehicles
	{
		delete parcel;
		return false;
	}
	//if we get here, list of vehicles is not empty
	if(receivedParcel_ == false) //if no vehicles have received parcels, try last pushed vehicle
	{
		for (auto j = vehicleList_.begin(); j != vehicleList_.end(); ++j) //try all vehicles starting from last pushed vehicle
		{
			if((*j)->addParcel(parcel)) //if the j'th vehicle accepted parcel
			{
				i_ = j; //update i_ (last vehicle to receive parcel)
				receivedParcel_ = true;
				return true;
			}
		}
		delete parcel;
		return false; //tried all vehicles, none accepted parcel
	}
	//if we get here, the company has already received at least one parcel
	const unsigned int size = vehicleList_.size();
	unsigned int numIterations = 0;
	auto j = i_;
	++j;
	for(; numIterations < size; ++j)
	{
		if(j == vehicleList_.end()) //cyclic
		{
			j = vehicleList_.begin();
		}
		++numIterations;
		if ((*j)->addParcel(parcel)) //if the j'th vehicle accepted parcel
		{
			i_ = j; //update i_ (last vehicle to receive parcel)
			return true;
		}
	}
	delete parcel;
	return false; //tried all vehicles, none accepted parcel
}

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
bool DeliveryCompany::performDeliveryDay()
{
	if (vehicleList_.empty())
		return false;
	int dailyTotalRevenue = 0;
	cout << "Starting days deliveries:" << endl;
	for (auto j = vehicleList_.begin(); j != vehicleList_.end(); ++j) //try all vehicles starting from last pushed vehicle
	{
		int tmpNumDeliveries = 0; //num of deliveries per vehicle
		dailyTotalRevenue += (*j)->performDeliveryDay(&tmpNumDeliveries);
		numDeliveries_ += tmpNumDeliveries;
	}
	totalMoney_ += dailyTotalRevenue;
	cout << "Total revenue for company is " << dailyTotalRevenue << endl;
	return true;
}

//************************************************************************************* 
// Function name : displayFunds
//
// Description : Displays the current capital of the company
//
// Parameters:  none
//
// Return value : none
//*************************************************************************************
void DeliveryCompany::displayFunds() const
{
	cout << "Company balance is now " << totalMoney_ << endl;
}

//************************************************************************************* 
// Function name : displayNumberOfDeliveries
//
// Description : Displays the number of packages delivered by the company
//
// Parameters:  none
//
// Return value : none
//*************************************************************************************
void DeliveryCompany::displayNumberOfDeliveries() const
{
	cout << "Till now company has delivered " << numDeliveries_ << " parcels" << endl;
}

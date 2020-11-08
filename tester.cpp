//#include <iostream>
//#include "Parcel.H"
//#include "DeliveryVehicle.H"
//#include "FastDeliveryVehicle.H"
//#include "ProfessionalDeliveryVehicle.H"
//#include "DeliveryCompany.H"
//
//using namespace std;
//
//int main()
//{
//	Parcel parcel1("abc", 5);
//	Parcel parcel2("bdcd", 2);
//	Parcel parcel3("bdcd", 3);
//
//	DeliveryVehicle vane("hello", bad);
//
//	vane.addParcel(&parcel1);
//	vane.addParcel(&parcel2);
//	vane.addParcel(&parcel3);
//
//	int numberOfDeliveries=0;
//	vane.performDeliveryDay(&numberOfDeliveries);
//	vane.performDeliveryDay(&numberOfDeliveries);
//	vane.performDeliveryDay(&numberOfDeliveries);
//	vane.performDeliveryDay(&numberOfDeliveries);
//
//	cout << endl << endl << endl;
//	FastDeliveryVehicle fastVane("toyou", bad);
//
//	fastVane.addParcel(&parcel1);
//	fastVane.addParcel(&parcel2);
//	fastVane.addParcel(&parcel3);
//	fastVane.performDeliveryDay(&numberOfDeliveries);
//	fastVane.performDeliveryDay(&numberOfDeliveries);
//	fastVane.performDeliveryDay(&numberOfDeliveries);
//	fastVane.performDeliveryDay(&numberOfDeliveries);
//
//	cout << endl << endl << endl;
//	ProfessionalDeliveryVehicle Pvane("bda", good);
//	Pvane.addParcel(&parcel2);
//	Pvane.performDeliveryDay(&numberOfDeliveries);
//	Pvane.performDeliveryDay(&numberOfDeliveries);
//	Pvane.performDeliveryDay(&numberOfDeliveries);
//	Pvane.performDeliveryDay(&numberOfDeliveries);
//
//	DeliveryCompany myComp;
//	auto vehicle1 = new DeliveryVehicle("1", good);
//	auto vehicle2 = new DeliveryVehicle("2", good);
//	auto vehicle3 = new DeliveryVehicle("3", good);
//	auto vehicle4 = new DeliveryVehicle("3", good);
//	myComp.addVehicle(vehicle1);
//	myComp.addVehicle(vehicle2);
//	myComp.addVehicle(vehicle3);
//	myComp.addVehicle(vehicle4);
//
//	DeliveryCompany emptyComp;
//	auto parcel_1 = new Parcel("123", 5);
//	emptyComp.receiveParcel(parcel_1);
//
//	auto parcel_2 = new Parcel("123", 5);
//	auto parcel_3 = new Parcel("13", 5);
//	auto parcel_4 = new Parcel("111", 5);
//
//	myComp.receiveParcel(parcel_2);
//	myComp.receiveParcel(parcel_3);
//	myComp.receiveParcel(parcel_4);
//
//	myComp.performDeliveryDay();
//
//
//
//	
//	
//	return 1;
//}
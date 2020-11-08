//#include "FastDeliveryCompany.H"
//#include "ProfessionalDeliveryCompany.H"
//#include "DeliveryCompany.H"
//#include "DeliveryVehicle.H"
//#include "FastDeliveryVehicle.H"
//#include "ProfessionalDeliveryVehicle.H"
//#include "Parcel.H"
//
//int main()
//{
//	DeliveryCompany* fedEks = new DeliveryCompany(50);
//	FastDeliveryCompany* DEEHL = new FastDeliveryCompany(10);
//
//	DeliveryVehicle* soobaroo = new DeliveryVehicle("soobaroo",bad);
//	ProfessionalDeliveryVehicle* cangoo = 
//		new ProfessionalDeliveryVehicle("cangoo",ok);
//	ProfessionalDeliveryVehicle* toostoos = 
//		new ProfessionalDeliveryVehicle("toostoos",good);
//	FastDeliveryVehicle* soosita = 
//		new FastDeliveryVehicle("soosita",good);
//	FastDeliveryVehicle* riksha = 
//		new FastDeliveryVehicle("riksha",bad);
//
//	fedEks->addVehicle(soobaroo);
//	fedEks->addVehicle(cangoo);
//	DEEHL->addVehicle(soosita);
//	DEEHL->addVehicle(toostoos);
//	DEEHL->addVehicle(riksha);
//	
//	Parcel* book = new Parcel("book",5);
//	Parcel* treasure = new Parcel("treasure",2);
//	Parcel* hot_air = new Parcel("hot_air",3);
//	Parcel* gum = new Parcel("gum",4);
//	Parcel* mice = new Parcel("mice",2);
//	Parcel* code = new Parcel("code",3);
//
//	fedEks->receiveParcel(book);
//	fedEks->receiveParcel(treasure);
//	DEEHL->receiveParcel(hot_air);
//	DEEHL->receiveParcel(gum);
//	DEEHL->receiveParcel(mice);
//	DEEHL->receiveParcel(code);
//
//	fedEks->performDeliveryDay();
//	fedEks->displayFunds();
//	
//	DEEHL->performDeliveryDay();
//	DEEHL->displayNumberOfDeliveries();
//	DEEHL->performDeliveryDay();
//	
//	delete DEEHL;
//	delete fedEks;
//	return 0;
//}

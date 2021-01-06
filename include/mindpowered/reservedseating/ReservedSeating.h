#pragma once
/*!
 * Copyright Mind Powered Corporation 2020
 * 
 * https://mindpowered.dev/
 */

#include <maglev/MagLev.h>
#include <maglev/MagLevCpp.h>
#include <maglev/CppCallbackPtr.h>
#include <maglev/CppAny.h>
#include <reservedseating/ReservedSeating.h>
#include <haxecpp/haxe_thread.h>
#include <string>
#include <map>

void __boot_maglev();
void __boot_reservedseating();

/*!
 * An Library for Reserved Seating
 * Venues have Seats, Events are at Venues
 * Reservations are Seats at Events
 */
class ReservedSeating {
public:
	ReservedSeating()
	{
		run_haxe([](){
			__boot_maglev();
			__boot_reservedseating();
			::maglev::MagLev m0 = ::maglev::MagLev_obj::getInstance("default");
			auto o = new ::reservedseating::ReservedSeating_obj();
			o->__construct(m0);
		});
	}
	~ReservedSeating()
	{
	}

	/*!
	 * Create a new venue
	 * @param ownerId Who is responsible for this venue
	 * @param name Name of Venue
	 * @param maxPeople Maximum people permitted in venue
	 * @return {std::string} the id of the new venue
	*/
	std::string CreateVenue(std::string ownerId, std::string name, double maxPeople)
	{
		::maglev::CppAny ret;
		run_haxe([&ret,ownerId,name,maxPeople](){
			::maglev::MagLevCpp bus = ::maglev::MagLevCpp_obj::getInstance("default");
			std::vector<::maglev::CppAny> myargs;
			::maglev::CppAny param0 = new ::maglev::CppAny_obj();
			param0->setStdString(ownerId);
			myargs.push_back(param0);
			::maglev::CppAny param1 = new ::maglev::CppAny_obj();
			param1->setStdString(name);
			myargs.push_back(param1);
			::maglev::CppAny param2 = new ::maglev::CppAny_obj();
			param2->setDouble(maxPeople);
			myargs.push_back(param2);
			bus->call("ReservedSeating.CreateVenue", myargs, [&ret] (::maglev::CppAny async_ret) { ret = async_ret; });
		});
		return ret->getStdString();
	}

	/*!
	 * Create a new Venue Congiguration
	 * @param venueId Venue
	 * @param name Name of Venue Configuration
	 * @param maxPeople Maximum number of people permitted in this Venue Configuration
	 * @return {std::string} the id of the new Venue Configuration
	*/
	std::string CreateVenueConfiguration(std::string venueId, std::string name, double maxPeople)
	{
		::maglev::CppAny ret;
		run_haxe([&ret,venueId,name,maxPeople](){
			::maglev::MagLevCpp bus = ::maglev::MagLevCpp_obj::getInstance("default");
			std::vector<::maglev::CppAny> myargs;
			::maglev::CppAny param0 = new ::maglev::CppAny_obj();
			param0->setStdString(venueId);
			myargs.push_back(param0);
			::maglev::CppAny param1 = new ::maglev::CppAny_obj();
			param1->setStdString(name);
			myargs.push_back(param1);
			::maglev::CppAny param2 = new ::maglev::CppAny_obj();
			param2->setDouble(maxPeople);
			myargs.push_back(param2);
			bus->call("ReservedSeating.CreateVenueConfiguration", myargs, [&ret] (::maglev::CppAny async_ret) { ret = async_ret; });
		});
		return ret->getStdString();
	}

	/*!
	 * Create a new seat
	 * @param name The seat name
	 * @param seatClass The class of seat
	 * @param venueConfigId the Venue Configuration the seat belongs to
	 * @param nextTo the seats that are next to this one
	 * @param tableId the table this seat is at
	 * @param geometry Information about where the Seat is
	 * @return {std::string} the id of the new seat
	*/
	std::string CreateSeat(std::string name, std::string seatClass, std::string venueConfigId, std::vector<::maglev::CppAny> nextTo, std::string tableId, std::map<std::string,::maglev::CppAny> geometry)
	{
		::maglev::CppAny ret;
		run_haxe([&ret,name,seatClass,venueConfigId,nextTo,tableId,geometry](){
			::maglev::MagLevCpp bus = ::maglev::MagLevCpp_obj::getInstance("default");
			std::vector<::maglev::CppAny> myargs;
			::maglev::CppAny param0 = new ::maglev::CppAny_obj();
			param0->setStdString(name);
			myargs.push_back(param0);
			::maglev::CppAny param1 = new ::maglev::CppAny_obj();
			param1->setStdString(seatClass);
			myargs.push_back(param1);
			::maglev::CppAny param2 = new ::maglev::CppAny_obj();
			param2->setStdString(venueConfigId);
			myargs.push_back(param2);
			::maglev::CppAny param3 = new ::maglev::CppAny_obj();
			param3->makeArray();
			for(auto item: nextTo)
			{
				param3->pushArray(item);
			}
			myargs.push_back(param3);
			::maglev::CppAny param4 = new ::maglev::CppAny_obj();
			param4->setStdString(tableId);
			myargs.push_back(param4);
			::maglev::CppAny param5 = new ::maglev::CppAny_obj();
			param5->setMap(geometry);
			myargs.push_back(param5);
			bus->call("ReservedSeating.CreateSeat", myargs, [&ret] (::maglev::CppAny async_ret) { ret = async_ret; });
		});
		return ret->getStdString();
	}

	/*!
	 * Create a new Event
	 * @param ownerId Who is responsible for this event
	 * @param venueConfigId Venue Configuration to use for this event
	 * @param maxPeople Maximum people permitted in venue
	 * @return {std::string} the id of the new Event
	*/
	std::string CreateEvent(std::string ownerId, std::string venueConfigId, double maxPeople)
	{
		::maglev::CppAny ret;
		run_haxe([&ret,ownerId,venueConfigId,maxPeople](){
			::maglev::MagLevCpp bus = ::maglev::MagLevCpp_obj::getInstance("default");
			std::vector<::maglev::CppAny> myargs;
			::maglev::CppAny param0 = new ::maglev::CppAny_obj();
			param0->setStdString(ownerId);
			myargs.push_back(param0);
			::maglev::CppAny param1 = new ::maglev::CppAny_obj();
			param1->setStdString(venueConfigId);
			myargs.push_back(param1);
			::maglev::CppAny param2 = new ::maglev::CppAny_obj();
			param2->setDouble(maxPeople);
			myargs.push_back(param2);
			bus->call("ReservedSeating.CreateEvent", myargs, [&ret] (::maglev::CppAny async_ret) { ret = async_ret; });
		});
		return ret->getStdString();
	}

	/*!
	 * Create a new Table
	 * @param venueConfigId Venue Configuration to use for this event
	 * @param minSeats Minimum number of people in a party to reserve the table
	 * @param maxSeats Maximum number of people that can sit at this table
	 * @param geometry Information about where the Table is
	 * @return {std::string} the id of the new Table
	*/
	std::string CreateTable(std::string venueConfigId, double minSeats, double maxSeats, std::map<std::string,::maglev::CppAny> geometry)
	{
		::maglev::CppAny ret;
		run_haxe([&ret,venueConfigId,minSeats,maxSeats,geometry](){
			::maglev::MagLevCpp bus = ::maglev::MagLevCpp_obj::getInstance("default");
			std::vector<::maglev::CppAny> myargs;
			::maglev::CppAny param0 = new ::maglev::CppAny_obj();
			param0->setStdString(venueConfigId);
			myargs.push_back(param0);
			::maglev::CppAny param1 = new ::maglev::CppAny_obj();
			param1->setDouble(minSeats);
			myargs.push_back(param1);
			::maglev::CppAny param2 = new ::maglev::CppAny_obj();
			param2->setDouble(maxSeats);
			myargs.push_back(param2);
			::maglev::CppAny param3 = new ::maglev::CppAny_obj();
			param3->setMap(geometry);
			myargs.push_back(param3);
			bus->call("ReservedSeating.CreateTable", myargs, [&ret] (::maglev::CppAny async_ret) { ret = async_ret; });
		});
		return ret->getStdString();
	}

	/*!
	 * Create a new Order
	 * @param userId The user who is placing the reservation
	 * @param eventId The event that the order is for
	 * @param expires Timestamp when order expires and is considered abondoned
	 * @return {std::string} the id of the new Order
	*/
	std::string CreateOrder(std::string userId, std::string eventId, double expires)
	{
		::maglev::CppAny ret;
		run_haxe([&ret,userId,eventId,expires](){
			::maglev::MagLevCpp bus = ::maglev::MagLevCpp_obj::getInstance("default");
			std::vector<::maglev::CppAny> myargs;
			::maglev::CppAny param0 = new ::maglev::CppAny_obj();
			param0->setStdString(userId);
			myargs.push_back(param0);
			::maglev::CppAny param1 = new ::maglev::CppAny_obj();
			param1->setStdString(eventId);
			myargs.push_back(param1);
			::maglev::CppAny param2 = new ::maglev::CppAny_obj();
			param2->setDouble(expires);
			myargs.push_back(param2);
			bus->call("ReservedSeating.CreateOrder", myargs, [&ret] (::maglev::CppAny async_ret) { ret = async_ret; });
		});
		return ret->getStdString();
	}

	/*!
	 * Get a Venue
	 * @param id Venue ID
	 * @return {std::map<std::string,::maglev::CppAny>} the Venue data as an object
	*/
	std::map<std::string,::maglev::CppAny> GetVenue(std::string id)
	{
		::maglev::CppAny ret;
		run_haxe([&ret,id](){
			::maglev::MagLevCpp bus = ::maglev::MagLevCpp_obj::getInstance("default");
			std::vector<::maglev::CppAny> myargs;
			::maglev::CppAny param0 = new ::maglev::CppAny_obj();
			param0->setStdString(id);
			myargs.push_back(param0);
			bus->call("ReservedSeating.GetVenue", myargs, [&ret] (::maglev::CppAny async_ret) { ret = async_ret; });
		});
		std::map<std::string,::maglev::CppAny> retmap;
		return retmap;
	}

	/*!
	 * Get a Venue Configuration
	 * @param id Venue Configuration ID
	 * @return {std::map<std::string,::maglev::CppAny>} the VenueConfiguration data as an object
	*/
	std::map<std::string,::maglev::CppAny> GetVenueConfiguration(std::string id)
	{
		::maglev::CppAny ret;
		run_haxe([&ret,id](){
			::maglev::MagLevCpp bus = ::maglev::MagLevCpp_obj::getInstance("default");
			std::vector<::maglev::CppAny> myargs;
			::maglev::CppAny param0 = new ::maglev::CppAny_obj();
			param0->setStdString(id);
			myargs.push_back(param0);
			bus->call("ReservedSeating.GetVenueConfiguration", myargs, [&ret] (::maglev::CppAny async_ret) { ret = async_ret; });
		});
		std::map<std::string,::maglev::CppAny> retmap;
		return retmap;
	}

	/*!
	 * Get a Seat
	 * @param id Seat ID
	 * @return {std::map<std::string,::maglev::CppAny>} the Seat data as an object
	*/
	std::map<std::string,::maglev::CppAny> GetSeat(std::string id)
	{
		::maglev::CppAny ret;
		run_haxe([&ret,id](){
			::maglev::MagLevCpp bus = ::maglev::MagLevCpp_obj::getInstance("default");
			std::vector<::maglev::CppAny> myargs;
			::maglev::CppAny param0 = new ::maglev::CppAny_obj();
			param0->setStdString(id);
			myargs.push_back(param0);
			bus->call("ReservedSeating.GetSeat", myargs, [&ret] (::maglev::CppAny async_ret) { ret = async_ret; });
		});
		std::map<std::string,::maglev::CppAny> retmap;
		return retmap;
	}

	/*!
	 * Get an Event
	 * @param id Event ID
	 * @return {std::map<std::string,::maglev::CppAny>} the Event data as an object
	*/
	std::map<std::string,::maglev::CppAny> GetEvent(std::string id)
	{
		::maglev::CppAny ret;
		run_haxe([&ret,id](){
			::maglev::MagLevCpp bus = ::maglev::MagLevCpp_obj::getInstance("default");
			std::vector<::maglev::CppAny> myargs;
			::maglev::CppAny param0 = new ::maglev::CppAny_obj();
			param0->setStdString(id);
			myargs.push_back(param0);
			bus->call("ReservedSeating.GetEvent", myargs, [&ret] (::maglev::CppAny async_ret) { ret = async_ret; });
		});
		std::map<std::string,::maglev::CppAny> retmap;
		return retmap;
	}

	/*!
	 * Get a Table
	 * @param id Table ID
	 * @return {std::map<std::string,::maglev::CppAny>} the Table data as an object
	*/
	std::map<std::string,::maglev::CppAny> GetTable(std::string id)
	{
		::maglev::CppAny ret;
		run_haxe([&ret,id](){
			::maglev::MagLevCpp bus = ::maglev::MagLevCpp_obj::getInstance("default");
			std::vector<::maglev::CppAny> myargs;
			::maglev::CppAny param0 = new ::maglev::CppAny_obj();
			param0->setStdString(id);
			myargs.push_back(param0);
			bus->call("ReservedSeating.GetTable", myargs, [&ret] (::maglev::CppAny async_ret) { ret = async_ret; });
		});
		std::map<std::string,::maglev::CppAny> retmap;
		return retmap;
	}

	/*!
	 * Update a Venue
	 * @param data Venue data to update
	 * @param complete if set to true, missing fields should be deleted
	*/
	void UpdateVenue(std::map<std::string,::maglev::CppAny> data, bool complete)
	{
		::maglev::CppAny ret;
		run_haxe([&ret,data,complete](){
			::maglev::MagLevCpp bus = ::maglev::MagLevCpp_obj::getInstance("default");
			std::vector<::maglev::CppAny> myargs;
			::maglev::CppAny param0 = new ::maglev::CppAny_obj();
			param0->setMap(data);
			myargs.push_back(param0);
			::maglev::CppAny param1 = new ::maglev::CppAny_obj();
			param1->setBool(complete);
			myargs.push_back(param1);
			bus->call("ReservedSeating.UpdateVenue", myargs, [&ret] (::maglev::CppAny async_ret) { ret = async_ret; });
		});
	}

	/*!
	 * Update a Venue Configuration
	 * @param data Venue Configuration data to update
	 * @param complete if set to true, missing fields should be deleted
	*/
	void UpdateVenueConfiguration(std::map<std::string,::maglev::CppAny> data, bool complete)
	{
		::maglev::CppAny ret;
		run_haxe([&ret,data,complete](){
			::maglev::MagLevCpp bus = ::maglev::MagLevCpp_obj::getInstance("default");
			std::vector<::maglev::CppAny> myargs;
			::maglev::CppAny param0 = new ::maglev::CppAny_obj();
			param0->setMap(data);
			myargs.push_back(param0);
			::maglev::CppAny param1 = new ::maglev::CppAny_obj();
			param1->setBool(complete);
			myargs.push_back(param1);
			bus->call("ReservedSeating.UpdateVenueConfiguration", myargs, [&ret] (::maglev::CppAny async_ret) { ret = async_ret; });
		});
	}

	/*!
	 * Update a Seat
	 * @param data Seat data to update
	 * @param complete if set to true, missing fields should be deleted
	*/
	void UpdateSeat(std::map<std::string,::maglev::CppAny> data, bool complete)
	{
		::maglev::CppAny ret;
		run_haxe([&ret,data,complete](){
			::maglev::MagLevCpp bus = ::maglev::MagLevCpp_obj::getInstance("default");
			std::vector<::maglev::CppAny> myargs;
			::maglev::CppAny param0 = new ::maglev::CppAny_obj();
			param0->setMap(data);
			myargs.push_back(param0);
			::maglev::CppAny param1 = new ::maglev::CppAny_obj();
			param1->setBool(complete);
			myargs.push_back(param1);
			bus->call("ReservedSeating.UpdateSeat", myargs, [&ret] (::maglev::CppAny async_ret) { ret = async_ret; });
		});
	}

	/*!
	 * Update an Event
	 * @param data Event data to update
	 * @param complete if set to true, missing fields should be deleted
	*/
	void UpdateEvent(std::map<std::string,::maglev::CppAny> data, bool complete)
	{
		::maglev::CppAny ret;
		run_haxe([&ret,data,complete](){
			::maglev::MagLevCpp bus = ::maglev::MagLevCpp_obj::getInstance("default");
			std::vector<::maglev::CppAny> myargs;
			::maglev::CppAny param0 = new ::maglev::CppAny_obj();
			param0->setMap(data);
			myargs.push_back(param0);
			::maglev::CppAny param1 = new ::maglev::CppAny_obj();
			param1->setBool(complete);
			myargs.push_back(param1);
			bus->call("ReservedSeating.UpdateEvent", myargs, [&ret] (::maglev::CppAny async_ret) { ret = async_ret; });
		});
	}

	/*!
	 * Update a Table
	 * @param data Table data to update
	 * @param complete if set to true, missing fields should be deleted
	*/
	void UpdateTable(std::map<std::string,::maglev::CppAny> data, bool complete)
	{
		::maglev::CppAny ret;
		run_haxe([&ret,data,complete](){
			::maglev::MagLevCpp bus = ::maglev::MagLevCpp_obj::getInstance("default");
			std::vector<::maglev::CppAny> myargs;
			::maglev::CppAny param0 = new ::maglev::CppAny_obj();
			param0->setMap(data);
			myargs.push_back(param0);
			::maglev::CppAny param1 = new ::maglev::CppAny_obj();
			param1->setBool(complete);
			myargs.push_back(param1);
			bus->call("ReservedSeating.UpdateTable", myargs, [&ret] (::maglev::CppAny async_ret) { ret = async_ret; });
		});
	}

	/*!
	 * Delete a Venue
	 * @param id Venue ID
	*/
	void DeleteVenue(std::string id)
	{
		::maglev::CppAny ret;
		run_haxe([&ret,id](){
			::maglev::MagLevCpp bus = ::maglev::MagLevCpp_obj::getInstance("default");
			std::vector<::maglev::CppAny> myargs;
			::maglev::CppAny param0 = new ::maglev::CppAny_obj();
			param0->setStdString(id);
			myargs.push_back(param0);
			bus->call("ReservedSeating.DeleteVenue", myargs, [&ret] (::maglev::CppAny async_ret) { ret = async_ret; });
		});
	}

	/*!
	 * Delete a Venue Configuration
	 * Must be unavailable first
	 * @param id Venue Configuration ID
	*/
	void DeleteVenueConfiguration(std::string id)
	{
		::maglev::CppAny ret;
		run_haxe([&ret,id](){
			::maglev::MagLevCpp bus = ::maglev::MagLevCpp_obj::getInstance("default");
			std::vector<::maglev::CppAny> myargs;
			::maglev::CppAny param0 = new ::maglev::CppAny_obj();
			param0->setStdString(id);
			myargs.push_back(param0);
			bus->call("ReservedSeating.DeleteVenueConfiguration", myargs, [&ret] (::maglev::CppAny async_ret) { ret = async_ret; });
		});
	}

	/*!
	 * Delete a Seat
	 * Venue Configuration must be unavailable first
	 * @param id Seat ID
	*/
	void DeleteSeat(std::string id)
	{
		::maglev::CppAny ret;
		run_haxe([&ret,id](){
			::maglev::MagLevCpp bus = ::maglev::MagLevCpp_obj::getInstance("default");
			std::vector<::maglev::CppAny> myargs;
			::maglev::CppAny param0 = new ::maglev::CppAny_obj();
			param0->setStdString(id);
			myargs.push_back(param0);
			bus->call("ReservedSeating.DeleteSeat", myargs, [&ret] (::maglev::CppAny async_ret) { ret = async_ret; });
		});
	}

	/*!
	 * Delete an Event
	 * Events on sale must be cancelled before being deleted.
	 * @param id Event ID
	*/
	void DeleteEvent(std::string id)
	{
		::maglev::CppAny ret;
		run_haxe([&ret,id](){
			::maglev::MagLevCpp bus = ::maglev::MagLevCpp_obj::getInstance("default");
			std::vector<::maglev::CppAny> myargs;
			::maglev::CppAny param0 = new ::maglev::CppAny_obj();
			param0->setStdString(id);
			myargs.push_back(param0);
			bus->call("ReservedSeating.DeleteEvent", myargs, [&ret] (::maglev::CppAny async_ret) { ret = async_ret; });
		});
	}

	/*!
	 * Delete a Table
	 * Venue Configuration must be unavailable first
	 * @param id Table ID
	*/
	void DeleteTable(std::string id)
	{
		::maglev::CppAny ret;
		run_haxe([&ret,id](){
			::maglev::MagLevCpp bus = ::maglev::MagLevCpp_obj::getInstance("default");
			std::vector<::maglev::CppAny> myargs;
			::maglev::CppAny param0 = new ::maglev::CppAny_obj();
			param0->setStdString(id);
			myargs.push_back(param0);
			bus->call("ReservedSeating.DeleteTable", myargs, [&ret] (::maglev::CppAny async_ret) { ret = async_ret; });
		});
	}

	/*!
	 * Delete an Order
	 * Reservations must be cancelled first
	 * @param id Order ID
	*/
	void DeleteOrder(std::string id)
	{
		::maglev::CppAny ret;
		run_haxe([&ret,id](){
			::maglev::MagLevCpp bus = ::maglev::MagLevCpp_obj::getInstance("default");
			std::vector<::maglev::CppAny> myargs;
			::maglev::CppAny param0 = new ::maglev::CppAny_obj();
			param0->setStdString(id);
			myargs.push_back(param0);
			bus->call("ReservedSeating.DeleteOrder", myargs, [&ret] (::maglev::CppAny async_ret) { ret = async_ret; });
		});
	}

	/*!
	 * Complete order and convert holds into reservations
	 * @param orderId Order ID
	*/
	void CompleteOrder(std::string orderId)
	{
		::maglev::CppAny ret;
		run_haxe([&ret,orderId](){
			::maglev::MagLevCpp bus = ::maglev::MagLevCpp_obj::getInstance("default");
			std::vector<::maglev::CppAny> myargs;
			::maglev::CppAny param0 = new ::maglev::CppAny_obj();
			param0->setStdString(orderId);
			myargs.push_back(param0);
			bus->call("ReservedSeating.CompleteOrder", myargs, [&ret] (::maglev::CppAny async_ret) { ret = async_ret; });
		});
	}

	/*!
	 * Place a hold on a seat and add it to an order
	 * @param orderId Order ID
	 * @param seatId Seat ID
	*/
	void AddSeatToOrder(std::string orderId, std::string seatId)
	{
		::maglev::CppAny ret;
		run_haxe([&ret,orderId,seatId](){
			::maglev::MagLevCpp bus = ::maglev::MagLevCpp_obj::getInstance("default");
			std::vector<::maglev::CppAny> myargs;
			::maglev::CppAny param0 = new ::maglev::CppAny_obj();
			param0->setStdString(orderId);
			myargs.push_back(param0);
			::maglev::CppAny param1 = new ::maglev::CppAny_obj();
			param1->setStdString(seatId);
			myargs.push_back(param1);
			bus->call("ReservedSeating.AddSeatToOrder", myargs, [&ret] (::maglev::CppAny async_ret) { ret = async_ret; });
		});
	}

	/*!
	 * Keep an order from expiring and becoming abondoned
	 * @param orderId Order ID
	 * @param expires New timestamp when order will expire
	*/
	void ContinueOrder(std::string orderId, double expires)
	{
		::maglev::CppAny ret;
		run_haxe([&ret,orderId,expires](){
			::maglev::MagLevCpp bus = ::maglev::MagLevCpp_obj::getInstance("default");
			std::vector<::maglev::CppAny> myargs;
			::maglev::CppAny param0 = new ::maglev::CppAny_obj();
			param0->setStdString(orderId);
			myargs.push_back(param0);
			::maglev::CppAny param1 = new ::maglev::CppAny_obj();
			param1->setDouble(expires);
			myargs.push_back(param1);
			bus->call("ReservedSeating.ContinueOrder", myargs, [&ret] (::maglev::CppAny async_ret) { ret = async_ret; });
		});
	}

	/*!
	 * Automatically select some seats and add them to the order
	 * @param numSeats Number of seats to select
	 * @param seatClassPreference Which seat classes to prefer in order
	*/
	void AutoSelect(double numSeats, std::vector<::maglev::CppAny> seatClassPreference)
	{
		::maglev::CppAny ret;
		run_haxe([&ret,numSeats,seatClassPreference](){
			::maglev::MagLevCpp bus = ::maglev::MagLevCpp_obj::getInstance("default");
			std::vector<::maglev::CppAny> myargs;
			::maglev::CppAny param0 = new ::maglev::CppAny_obj();
			param0->setDouble(numSeats);
			myargs.push_back(param0);
			::maglev::CppAny param1 = new ::maglev::CppAny_obj();
			param1->makeArray();
			for(auto item: seatClassPreference)
			{
				param1->pushArray(item);
			}
			myargs.push_back(param1);
			bus->call("ReservedSeating.AutoSelect", myargs, [&ret] (::maglev::CppAny async_ret) { ret = async_ret; });
		});
	}

	/*!
	 * Cancel an event and all reservations for that event
	 * @param eventId Event ID
	*/
	void CancelEvent(std::string eventId)
	{
		::maglev::CppAny ret;
		run_haxe([&ret,eventId](){
			::maglev::MagLevCpp bus = ::maglev::MagLevCpp_obj::getInstance("default");
			std::vector<::maglev::CppAny> myargs;
			::maglev::CppAny param0 = new ::maglev::CppAny_obj();
			param0->setStdString(eventId);
			myargs.push_back(param0);
			bus->call("ReservedSeating.CancelEvent", myargs, [&ret] (::maglev::CppAny async_ret) { ret = async_ret; });
		});
	}

	/*!
	 * Cancel a reservation and release the seats
	 * @param orderId Order ID
	 * @param seatId Seat ID
	*/
	void CancelReservation(std::string orderId, std::string seatId)
	{
		::maglev::CppAny ret;
		run_haxe([&ret,orderId,seatId](){
			::maglev::MagLevCpp bus = ::maglev::MagLevCpp_obj::getInstance("default");
			std::vector<::maglev::CppAny> myargs;
			::maglev::CppAny param0 = new ::maglev::CppAny_obj();
			param0->setStdString(orderId);
			myargs.push_back(param0);
			::maglev::CppAny param1 = new ::maglev::CppAny_obj();
			param1->setStdString(seatId);
			myargs.push_back(param1);
			bus->call("ReservedSeating.CancelReservation", myargs, [&ret] (::maglev::CppAny async_ret) { ret = async_ret; });
		});
	}

	/*!
	 * Get all Seats and Tables for an Event
	 * @param eventId Event ID
	 * @param page page number
	 * @param perpage per page
	*/
	void GetSeatsAndTablesForEvent(std::string eventId, double page, double perpage)
	{
		::maglev::CppAny ret;
		run_haxe([&ret,eventId,page,perpage](){
			::maglev::MagLevCpp bus = ::maglev::MagLevCpp_obj::getInstance("default");
			std::vector<::maglev::CppAny> myargs;
			::maglev::CppAny param0 = new ::maglev::CppAny_obj();
			param0->setStdString(eventId);
			myargs.push_back(param0);
			::maglev::CppAny param1 = new ::maglev::CppAny_obj();
			param1->setDouble(page);
			myargs.push_back(param1);
			::maglev::CppAny param2 = new ::maglev::CppAny_obj();
			param2->setDouble(perpage);
			myargs.push_back(param2);
			bus->call("ReservedSeating.GetSeatsAndTablesForEvent", myargs, [&ret] (::maglev::CppAny async_ret) { ret = async_ret; });
		});
	}

	/*!
	 * Get any abondoned (expired) orders
	 * @param page page number
	 * @param perpage per page
	 * @return {std::vector<::maglev::CppAny>} abondoned orders
	*/
	std::vector<::maglev::CppAny> FindAbandonedOrders(double page, double perpage)
	{
		::maglev::CppAny ret;
		run_haxe([&ret,page,perpage](){
			::maglev::MagLevCpp bus = ::maglev::MagLevCpp_obj::getInstance("default");
			std::vector<::maglev::CppAny> myargs;
			::maglev::CppAny param0 = new ::maglev::CppAny_obj();
			param0->setDouble(page);
			myargs.push_back(param0);
			::maglev::CppAny param1 = new ::maglev::CppAny_obj();
			param1->setDouble(perpage);
			myargs.push_back(param1);
			bus->call("ReservedSeating.FindAbandonedOrders", myargs, [&ret] (::maglev::CppAny async_ret) { ret = async_ret; });
		});
		std::vector<::maglev::CppAny> retarr;
		return retarr;
	}

	/*!
	 * Get a users orders
	 * @param userId User ID
	 * @param page page number
	 * @param perpage per page
	 * @return {std::vector<::maglev::CppAny>} orders for user
	*/
	std::vector<::maglev::CppAny> GetOrdersForUser(std::string userId, double page, double perpage)
	{
		::maglev::CppAny ret;
		run_haxe([&ret,userId,page,perpage](){
			::maglev::MagLevCpp bus = ::maglev::MagLevCpp_obj::getInstance("default");
			std::vector<::maglev::CppAny> myargs;
			::maglev::CppAny param0 = new ::maglev::CppAny_obj();
			param0->setStdString(userId);
			myargs.push_back(param0);
			::maglev::CppAny param1 = new ::maglev::CppAny_obj();
			param1->setDouble(page);
			myargs.push_back(param1);
			::maglev::CppAny param2 = new ::maglev::CppAny_obj();
			param2->setDouble(perpage);
			myargs.push_back(param2);
			bus->call("ReservedSeating.GetOrdersForUser", myargs, [&ret] (::maglev::CppAny async_ret) { ret = async_ret; });
		});
		std::vector<::maglev::CppAny> retarr;
		return retarr;
	}

	/*!
	 * Get all Events marked on sale
	 * @param page page number
	 * @param perpage per page
	 * @return {std::vector<::maglev::CppAny>} events on sale
	*/
	std::vector<::maglev::CppAny> GetAllEventsOnSale(double page, double perpage)
	{
		::maglev::CppAny ret;
		run_haxe([&ret,page,perpage](){
			::maglev::MagLevCpp bus = ::maglev::MagLevCpp_obj::getInstance("default");
			std::vector<::maglev::CppAny> myargs;
			::maglev::CppAny param0 = new ::maglev::CppAny_obj();
			param0->setDouble(page);
			myargs.push_back(param0);
			::maglev::CppAny param1 = new ::maglev::CppAny_obj();
			param1->setDouble(perpage);
			myargs.push_back(param1);
			bus->call("ReservedSeating.GetAllEventsOnSale", myargs, [&ret] (::maglev::CppAny async_ret) { ret = async_ret; });
		});
		std::vector<::maglev::CppAny> retarr;
		return retarr;
	}

	/*!
	 * Make a venue configuration available or unavailable.
	 * Must not have any events for sale using this venute configuration.
	 * @param venueConfigurationId Venue Configuration ID
	 * @param available availability
	*/
	void UpdateVenueConfigurationAvailability(std::string venueConfigurationId, bool available)
	{
		::maglev::CppAny ret;
		run_haxe([&ret,venueConfigurationId,available](){
			::maglev::MagLevCpp bus = ::maglev::MagLevCpp_obj::getInstance("default");
			std::vector<::maglev::CppAny> myargs;
			::maglev::CppAny param0 = new ::maglev::CppAny_obj();
			param0->setStdString(venueConfigurationId);
			myargs.push_back(param0);
			::maglev::CppAny param1 = new ::maglev::CppAny_obj();
			param1->setBool(available);
			myargs.push_back(param1);
			bus->call("ReservedSeating.UpdateVenueConfigurationAvailability", myargs, [&ret] (::maglev::CppAny async_ret) { ret = async_ret; });
		});
	}

	/*!
	 * Get Venue Configurations for a Venue
	 * @param venueId Venue ID
	 * @return {std::vector<::maglev::CppAny>} the Venue Configurations for the specified Venue
	*/
	std::vector<::maglev::CppAny> GetVenueConfigurations(std::string venueId)
	{
		::maglev::CppAny ret;
		run_haxe([&ret,venueId](){
			::maglev::MagLevCpp bus = ::maglev::MagLevCpp_obj::getInstance("default");
			std::vector<::maglev::CppAny> myargs;
			::maglev::CppAny param0 = new ::maglev::CppAny_obj();
			param0->setStdString(venueId);
			myargs.push_back(param0);
			bus->call("ReservedSeating.GetVenueConfigurations", myargs, [&ret] (::maglev::CppAny async_ret) { ret = async_ret; });
		});
		std::vector<::maglev::CppAny> retarr;
		return retarr;
	}

	/*!
	 * Get a summary of an Order
	 * @param orderId Order ID
	 * @return {std::vector<::maglev::CppAny>} the summary for the specified Order
	*/
	std::vector<::maglev::CppAny> GetOrderSummary(std::string orderId)
	{
		::maglev::CppAny ret;
		run_haxe([&ret,orderId](){
			::maglev::MagLevCpp bus = ::maglev::MagLevCpp_obj::getInstance("default");
			std::vector<::maglev::CppAny> myargs;
			::maglev::CppAny param0 = new ::maglev::CppAny_obj();
			param0->setStdString(orderId);
			myargs.push_back(param0);
			bus->call("ReservedSeating.GetOrderSummary", myargs, [&ret] (::maglev::CppAny async_ret) { ret = async_ret; });
		});
		std::vector<::maglev::CppAny> retarr;
		return retarr;
	}

	/*!
	 * Get all Venues for an owner
	 * @param ownerId owner id
	 * @return {std::vector<::maglev::CppAny>} List of venues
	*/
	std::vector<::maglev::CppAny> GetAllVenuesByOwner(std::string ownerId)
	{
		::maglev::CppAny ret;
		run_haxe([&ret,ownerId](){
			::maglev::MagLevCpp bus = ::maglev::MagLevCpp_obj::getInstance("default");
			std::vector<::maglev::CppAny> myargs;
			::maglev::CppAny param0 = new ::maglev::CppAny_obj();
			param0->setStdString(ownerId);
			myargs.push_back(param0);
			bus->call("ReservedSeating.GetAllVenuesByOwner", myargs, [&ret] (::maglev::CppAny async_ret) { ret = async_ret; });
		});
		std::vector<::maglev::CppAny> retarr;
		return retarr;
	}

};


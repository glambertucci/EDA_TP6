#include "client.h"



client::client()
{
/*	this->io_handler = new boost::asio::io_service();
	this->client_socket = new boost::asio::ip::tcp::socket(*io_handler);
	this->client_resolver = new boost::asio::ip::tcp::resolver(*io_handler); 
*/}

void client::connect(const char * host, const char * port)
{
/*	auto query = boost::asio::ip::tcp::resolver::query(host, port);
	this->endpoint = this->client_resolver->resolve(query);
	boost::asio::connect(*(this->client_socket), this->endpoint); 
*/}

void client::send_msg(string buffer)
{
	/*
	boost::system::error_code error;
	do{
	(this->client_socket)->write_some(boost::asio::buffer(buffer, buffer.size()),error);
	} while (error);
	*/
}

client::~client()
{
//	this->client_socket->close();
//	this->client_resolver;
//	delete this->io_handler;
//	delete this->client_resolver;
//	delete this->client_socket;
}

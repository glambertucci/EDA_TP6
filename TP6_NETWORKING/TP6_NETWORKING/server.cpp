#include "server.h"



server::server(const char * port)
{
	this->io_handler = new boost::asio::io_service();
	this->server_socket = new boost::asio::ip::tcp::socket(*io_handler);
	this->server_acceptor = new boost::asio::ip::tcp::acceptor(*io_handler, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port));
}


server::~server()
{
}

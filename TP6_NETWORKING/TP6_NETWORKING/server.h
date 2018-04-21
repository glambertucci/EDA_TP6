#pragma once
#include <boost/asio.hpp>
class server
{
public:
	server(const char * port);
	void connect();

	~server();
private:
	boost::asio::io_service * io_handler;
	boost::asio::ip::tcp::socket * server_socket;
	boost::asio::ip::tcp::acceptor * server_acceptor;
};


#pragma once
//#include <boost/asio.hpp>

#include <string>
using namespace std;
class server
{
public:
	server(const char * port);//constructor
	void listen(); 
	string recive_msg();
	~server();
private:
	bool finished;
/*	boost::asio::io_service * io_handler;
	boost::asio::ip::tcp::socket * server_socket;
	boost::asio::ip::tcp::acceptor * server_acceptor;
*/	
};


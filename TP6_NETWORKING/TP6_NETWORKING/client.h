#pragma once
#include <boost/asio.hpp>
#include <string>
using namespace std;
class client
{
public:
	client(); //inicia socket resolver endpoint y handler
	void connect(char const * host, char const * port);
	void send_msg(string buffer);
	~client();
private:

	boost::asio::io_service * io_handler;
	boost::asio::ip::tcp::socket * client_socket;
	boost::asio::ip::tcp::resolver * client_resolver;
	boost::asio::ip::tcp::resolver::iterator endpoint;
};


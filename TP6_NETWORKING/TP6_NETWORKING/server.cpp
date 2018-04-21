#include "server.h"



server::server(const char * port)
{
	finished = false;
	this->io_handler = new boost::asio::io_service();
	this->server_socket = new boost::asio::ip::tcp::socket(*io_handler);
	this->server_acceptor = new boost::asio::ip::tcp::acceptor(*io_handler, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(),  atoi(port)));
}

void server::listen()
{
	this->server_acceptor->accept(); //Escucha
}

string server::recive_msg()
{
	char buffer[1 + 255 + 1]; // 1 byte de codigo 255 para maquinas
	size_t length;
	boost::system::error_code error;
	do{
	length = this->server_socket->read_some(buffer, error);
	} while (error);
	buffer[length] = 0; //terminador
	string final = buffer;
	return final;
}

server::~server()
{
	this->server_socket->close();
	this->server_acceptor->close();
	delete this->io_handler;
	delete this->server_acceptor;
	delete this->server_socket;

}

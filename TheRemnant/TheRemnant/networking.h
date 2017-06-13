#pragma once
#include "stdafx.h"
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment(lib, "Ws2_32.lib")
#include <WinSock2.h>
#include <iostream>
#include <string>
using namespace std;

void send_data(std::string ip, int port, std::string data)
{
	WSADATA WSAData;
	SOCKET server;
	SOCKADDR_IN addr;

	WSAStartup(MAKEWORD(2, 0), &WSAData);
	server = socket(AF_INET, SOCK_STREAM, 0);

	addr.sin_addr.s_addr = inet_addr(ip.c_str()); // replace the ip with your futur server ip address. If server AND client are running on the same computer, you can use the local ip 127.0.0.1
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);

	connect(server, (SOCKADDR *)&addr, sizeof(addr));
	char buffer[1024];
	strncpy_s(buffer, data.c_str(), sizeof(buffer) - 1);
	buffer[sizeof(buffer) - 1] = '\0';
	send(server, buffer, sizeof(buffer), 0);

	closesocket(server);
	WSACleanup();
	
}

std::string recieve_data(int port)
{
	WSADATA WSAData;

	SOCKET server, client;

	SOCKADDR_IN serverAddr, clientAddr;

	WSAStartup(MAKEWORD(2, 0), &WSAData);
	server = socket(AF_INET, SOCK_STREAM, 0);

	serverAddr.sin_addr.s_addr = INADDR_ANY;
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(port);

	bind(server, (SOCKADDR *)&serverAddr, sizeof(serverAddr));
	listen(server, 0);

	cout << "Listening for incoming connections..." << endl;

	char buffer[1024];
	int clientAddrSize = sizeof(clientAddr);
	if ((client = accept(server, (SOCKADDR *)&clientAddr, &clientAddrSize)) != INVALID_SOCKET)
	{
		cout << "Client connected!" << endl;
		recv(client, buffer, sizeof(buffer), 0);
		cout << "Client says: " << buffer << endl;
		memset(buffer, 0, sizeof(buffer));
		
		closesocket(client);
		return std::string(buffer);
		
	}
	else {
		return std::string("");
	}
}

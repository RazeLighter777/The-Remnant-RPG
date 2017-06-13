// TheRemnant.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "networking.h"

int main()
{
	send_data("127.0.0.1", 80, "Hello from client");
    return 0;
}


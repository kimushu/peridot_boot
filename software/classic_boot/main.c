/*
 * main.c
 *
 *  Created on: 2017/05/02
 *      Author: shuta
 */

#include "peridot_rpc_server.h"

int main(void)
{
	for (;;) {
		peridot_rpc_server_process();
	}
	return 0;
}


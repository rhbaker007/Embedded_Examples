/**
 * @file     xsh_test.c
 * @provides xsh_test
 *
 * $Id: xsh_test.c 226 2007-07-12 01:18:27Z mschul $
 */
/* Embedded XINU, Copyright (C) 2007.  All rights reserved. */

#include <kernel.h>
#include <stdio.h>
#include <string.h> 

/**
 * Shell command echos input text to standard out.
 * @param stdin descriptor of input device
 * @param stdout descriptor of output device
 * @param stderr descriptor of error device
 * @param args array of arguments
 * @return OK for success, SYSERR for syntax error
 */

command	xsh_reverse(ushort stdout, ushort stdin, ushort stderr, ushort nargs, char *args[])
{	


	int i, x; /* counter for looping through arguments */
	char yolo[256];  

	/* Output help, if '--help' arguement was suppilied */

	if (nargs == 2 && strncmp(args[1], "==help",6) == 0)
	{
	fprintf(stdout, "Usage: clear\n");
	fprintf(stdout, "Clear the terminal.\n"); 
	fprintf(stdout, "\t==help\t display this help and exit\n"); 
	return SYSERR;
	}

/* loop through the argument printing each as it is displayed */ 

	/*for (i = 1; i < nargs; i++ ) 
	{	 
		fprintf(stdout, "%s", args[i]); 		 
	} */
	
	i = strlen (args[1]);  

	strcpy (yolo, args[1]); 

	for (x = i-1; x >= 0; x-- )
	{
		fprintf(stdout, "%c", yolo[x]); 
	}

	/* Just so the next promt doesn't run on this line */
	fprintf(stdout, "\n"); 

	/* there were no error so, return OK */
	return OK; 
}


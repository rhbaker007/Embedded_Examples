/* NAME: RONALD BAKER & MICHAEL AU
 * CLASS: REAL-TIME EMBEDDED SYSTEMS  
 */

////////////////////////////////////////////////////////////
//PART 1: REVERSE					  //
////////////////////////////////////////////////////////////
//- Our group looked up different ideas from open course  //
//  information located on line.			  //
//- RON went to professor Bina for assistance on this     // 
//  portion of the project.  				  //	
//- The code was very straight forward. 		  //
//********************************************************//
//OPERATION: reverse					  //
//********************************************************//
//- Must be run on the xinu_mips-1.0.2			  //
//- You must type reverse in the command		  //
//- Any text that is entered will be reversed		  //
//- QUIT => ctrl+spacebar then q   			  //
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
//PART 2: SCHEDULE					  //
////////////////////////////////////////////////////////////
//- We looked at the TableDrivenCE.c file located in the  //
//  demo directory for assistance.			  //
//- Looked at examples from textbook to assist with the   //
//  schedule planning. 					  //
//- Found an example for the threading inside the main.c  //
//  file located in the system folder. 			  //
//- Both of the partners work loosly with each other      //
//  attempted to solve the problem individualy. 	  //
//- Each partner just provided each other with source info// 
//  to do this portion of the lab. 		          //
//********************************************************//
//OPERATION: schedule.c					  //
//********************************************************//
//- Must be run on the xinu_mips-1.5			  //
//- Connect using mips-console (OPEN ROUTER) 		  //
//- Type in schedule after the XINU appears		  //
//- The schedule should start to print out at this point  //
//- QUIT => ctrl+spacebar then q   			  //
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
//PART 3: CHAT 						  //
////////////////////////////////////////////////////////////
//- Mike decide put the name and password of the user in  //
//  the same array separated by a space. 		  //
//- To print out the message between the users, it was    //
//  decided to use fprintf. 				  //
//- The two of us worked on the code separately after this//
//  point of the project. 				  //				
//- I assigned the Administrative user is assigned to the //
//  TTY0.						  //
//- The other user was assigned to TTY1	                  //
//- TTY0 Admin Primar (enter both at same time with _ )	  //
//- TTY1 User1 Second (enter both at same time with _ )   //
//- (MIKE)To kick the other user out of the conversation, //
//  we used getpid() to get process id. To kick the other //
//  user, we use getpid() from first running chat and add //
//  one to it to kill the second chat process.  	  //
//- To exit from the conversation, the user just has type //
//  in exit.						  // 
//********************************************************//
//OPERATION: chat.c					  //
//********************************************************//
//- Must be run on the xinu_mips-1.0.2			  //
//- Connect using mips-console (OPEN ROUTER)		  //
//- Connect using xinu-console (OPEN ROUTER)		  //
//- Type in chat for each of the console's		  //
//- Begin chating ot the other user			  //
//- QUIT => ctrl+spacebar then q  			  //
////////////////////////////////////////////////////////////


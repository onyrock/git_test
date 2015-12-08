/*------------------------------------------------*/
/*    C socket server example                     */
/*------------------------------------------------*/

#include <iostream>
using namespace std;
 
#include<stdio.h>
#include<string.h>    //strlen
#include<sys/socket.h>
#include<arpa/inet.h> //inet_addr
#include<unistd.h>    //write


class tcp
{
  private:
    int client_sock , c , read_size;
    struct sockaddr_in server , client;
    char client_message[2000];
 
  public:
    int socket_desc;
    tcp(int port_num, const char *ip_addr) // default constructor
    {
         //Create socket
    	 socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    	if (socket_desc == -1)
    	{
    	    std::cout << "Error in socket creation." << std::endl;
    	}
        puts("TCP Socket created");

        server.sin_family = AF_INET;
        server.sin_addr.s_addr = INADDR_ANY; // add the IP address here
        server.sin_port = htons( port_num );

        //Bind
        if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0)
        {
          perror("bind failed. Error");
        }
        puts("bind successfull.");

        listen(socket_desc , 3);
        printf("Successfully created a a TCP socket with a backlog of 3.\n");

    }

    // other member functions here....
};


int main()
{
    tcp tcp_conn1(8889,"127.0.0.1");
    std::cout << "connection desc ID is : " << tcp_conn1.socket_desc << std::endl;
    return 0;
}




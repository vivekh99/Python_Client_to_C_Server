#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/time.h>
#include <stdlib.h>
#include <memory.h>
#include <ifaddrs.h>
#include <net/if.h>
#include <stdarg.h>
#include <math.h>
#include <sys/termios.h>
#include <string.h> 
#include <resolv.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>
#include <sys/mman.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>


int main(int argc, char *argv[])
{
    
    char established[256] = "This is data sent from server to verify connection to client";
    
    char recieved_message[256];
    //create socket
    int new_socket;
    new_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(new_socket < 0){
        printf("ERROR making socket");
        exit(1);
    }

    //create server address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9001);
    //INADDR_ANY resolves to iP address on local machine, 
    //should change to 223.234.234.2 later
    server_address.sin_addr.s_addr = INADDR_ANY;

    //bind the socket to IP and port
    bind(new_socket, (struct sockaddr*) &server_address, sizeof(server_address));


    //begin listening to connections
    listen(new_socket, 5);

    int client_socket;
    client_socket = accept(new_socket, NULL, NULL);

    send(client_socket, established, sizeof(established), 0);

    if(recv(client_socket, &recieved_message, sizeof(recieved_message), 0) < 0){
        printf("ERROR, connection made but data not recieved\n");
    }
    else{
        printf("%s", recieved_message);
        printf("\n");
    }
    
    
    close(new_socket);
    return 0;
}
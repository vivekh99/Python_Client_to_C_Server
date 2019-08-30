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
    int fd;
    char *name = "/dev/mem";
    void *dat;
    uint32_t recieved_message;
    
    //create socket
    int new_socket;
    new_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(new_socket < 0){
        printf("ERROR making socket");
        printf("\n");
        exit(1);
    }

    if((fd = open(name, O_RDWR)) < 0)
    {
        perror("open");
        return EXIT_FAILURE;
    }


    dat = mmap(NULL, sysconf(_SC_PAGESIZE), PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0x42000000);


    //create server address
    struct sockaddr_in server_address;
    //internet
    server_address.sin_family = AF_INET;
    //create port to use --> needs to be same port as client
    server_address.sin_port = htons(9001);
    //INADDR_ANY resolves to whatever IP address is inputted into the client 
    server_address.sin_addr.s_addr = INADDR_ANY;

    //bind the socket to IP and port
    bind(new_socket, (struct sockaddr*) &server_address, sizeof(server_address));


    //begin listening to connections
    listen(new_socket, 5);

    
    while (1) {
        int client_socket;
        //accept connection from socket
        client_socket = accept(new_socket, NULL, NULL);
        //send string established to client_socket
        send(client_socket, established, sizeof(established), 0);
        //recieve string from client_socket
        if (recv(client_socket, &recieved_message, sizeof(recieved_message), 0) < 0){
            printf("ERROR, connection made but data not recieved\n");
        }
        else {
            *((int32_t *)(dat + 0)) = recieved_message;
            printf("%s", recieved_message);
            printf("\n");
            
            close(client_socket);

        }

    }
       
    close(new_socket);
    return 0;
}
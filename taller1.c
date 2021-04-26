#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h> 

int main(){
    
    int conection = 0;
    int socket_id = 0;
    socket_id = socket(PF_INET, SOCK_DGRAM, 0);

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("200.25.3.11");
    server.sin_port = htons(123);

    conection = connect(socket_id, (struct sockaddr*)&server, sizeof(server));
    if(conection < 0){
        printf("Error al realizar la conexión\r\n");
        return(-1);
    }

    printf("Conexión realizada con éxito\r\n");

    char msg[]="GET hora\r\n\r\n",htmlcode[50]={0};

    if(send(socket_id,msg,strlen(msg),0)<0) printf("Fallo al enviar el mensaje");
    printf("Mensaje Enviado\n");

    while(recv(socket_id,htmlcode,sizeof(htmlcode),0) > 0)
    {
        printf("%s",htmlcode);
    }
    close(socket_id);
    return(0); 
}
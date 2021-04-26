#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define NTP_TIMESTAMP_DELTA 2208988800ull

typedef struct
  {
    char li_vn_mode;      

    char stratum;         
    char poll;            
    char precision;       

    unsigned int rootDelay;      
    unsigned int rootDispersion; 
    char refId[4];        

    unsigned int refTm_s;        
    unsigned int refTm_f;       

    unsigned int origTm_s;       
    unsigned int origTm_f;       

    unsigned int rxTm_s;         
    unsigned int rxTm_f;         

    unsigned int txTm_s;         
    unsigned int txTm_f;         

  } ntp_packet;           


int main(){

    int conection = 0;
    int socket_id = 0;
    socket_id = socket(PF_INET, SOCK_DGRAM , 0);

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("200.25.3.11");
    server.sin_port = htons(123);

    conection = connect(socket_id, (struct sockaddr*)&server, sizeof(server));
    if(conection < 0){
        printf("Error al realizar la conexión\r\n");
        return(-1);
    }

    ntp_packet packet = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

    packet.li_vn_mode=0x1B;

    if (send(socket_id,(char*)&packet,sizeof(ntp_packet),0)<0) printf("Error al enviar el mensaje");
    if (read(socket_id,(char*)&packet,sizeof(ntp_packet))<0) printf("Error al recibir el mensaje");

    packet.txTm_s = ntohl( packet.txTm_s );
    packet.txTm_f = ntohl( packet.txTm_f );

    time_t txTm = ( time_t ) ( packet.txTm_s - NTP_TIMESTAMP_DELTA );

    printf( "Time: %s", ctime( ( const time_t* ) &txTm ) );

    
}
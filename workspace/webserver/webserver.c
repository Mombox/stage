#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <sockLib.h>
#include <string.h>

#include "webserver.h"

#define SERVER_PORT     80 /* Port 80 is reserved for HTTP protocol */
#define SERVER_MAX_CONNECTIONS  20




void www(int argc, char *argv[])
{
  int s;
  int newFd;
  struct sockaddr_in serverAddr;
  struct sockaddr_in clientAddr;
  int sockAddrSize;

  sockAddrSize = sizeof(struct sockaddr_in);
  bzero((char *) &serverAddr, sizeof(struct sockaddr_in));
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(SERVER_PORT);
  serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);

  s=socket(AF_INET, SOCK_STREAM, 0);
  if (s<0)
  {
    printf("Error: www: socket(%d)\n", s);
    return;
  }

  {
	  int optval = 1;
	  setsockopt(s, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));
  }
  
  if (bind(s, (struct sockaddr *) &serverAddr, sockAddrSize) == ERROR)
  {
    perror("Error: www: bind");
    return;
  }

  if (listen(s, SERVER_MAX_CONNECTIONS) == ERROR)
  {
    perror("www listen");
    close(s);
    return;
  }

  printf("www server running\n");

  while(1)
  {
    /* accept waits for somebody to connect and the returns a new file descriptor */
    if ((newFd = accept(s, (struct sockaddr *) &clientAddr, &sockAddrSize)) == ERROR)
    {
      perror("www accept");
      close(s);
      return;
    }

    FILE *f = fdopen(newFd, "r+");
    char request[256];
    
    if (fgets(request, sizeof(request), f) != NULL) {
    	printf("%s\n", request);
    	if (strstr(request, "/quit") != NULL) {
    		fclose(f);
    		break;
    	}
    }
    fprintf(f,HTTP);
    fprintf(f, "HTTP/1.0 200 OK\r\n\r\n");
    fprintf(f, "<?xml version=\"1.0\"?>"
"<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.0//EN\" \"http://www.w3.org/TR/2001/REC-SVG-20010904/DTD/svg10.dtd\">"
"<svg width=\"500\" height=\"300\" xmlns='http://www.w3.org/2000/svg'>"
"  <g transform=\"translate(50,130) scale(1)\">"
"    <!-- Now Draw the main X and Y axis -->"
"    <g style=\"stroke-width:2; stroke:black\">"
"      <!-- X Axis -->"
"      <path d=\"M 0 0 L 400 0 Z\"/>"
"      <!-- Y Axis -->"
"      <path d=\"M 0 -100 L 0 100 Z\"/>"
"    </g>"
"    <g style=\"fill:none; stroke:#B0B0B0; stroke-width:1; stroke-dasharray:2 4;text-anchor:end; font-size:30\">"
"      <text style=\"fill:black; stroke:none\" x=\"-1\" y=\"100\" >-100</text>"
"      <text style=\"fill:black; stroke:none\" x=\"-1\" y=\"0\" >0</text>"
"      <text style=\"fill:black; stroke:none\" x=\"-1\" y=\"-100\" >100</text>"
"      <g style=\"text-anchor:middle\">"
"	<text style=\"fill:black; stroke:none\" x=\"100\" y=\"20\" >100</text>"
"	<text style=\"fill:black; stroke:none\" x=\"200\" y=\"20\" >200</text>"
"	<text style=\"fill:black; stroke:none\" x=\"300\" y=\"20\" >300</text>"
"	<text style=\"fill:black; stroke:none\" x=\"400\" y=\"20\" >400</text>"
"      </g>"
"    </g>"
"    <polyline"
"	      points=\"");
    
    int i;
    for (i = 0; i < 100; i++)
    	fprintf(f, "%d, %d,\n", i, rand()%100);
 		
    		fprintf(f, "\"" 
"	      style=\"stroke:red; stroke-width: 1; fill : none;\"/>"
"  </g>"
"</svg>");

    		
    		fclose(f); 
    		
  }
  close(s);
  printf("Byebye\n");
}

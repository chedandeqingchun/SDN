#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <strings.h>
#include <arpa/inet.h>
#include <unistd.h>

int
main(int argc, char **argv) {
  struct sockaddr_in addr;
  char recvline[50];
  int n;

  int fd = socket(AF_UNIX, SOCK_STREAM, 0);

  if (fd == -1) {
    printf("create socket error\n");
    return -1;
  }

  bzero(&addr, sizeof(sockaddr_in));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(13); 

  if (inet_pton(AF_INET, argv[1], &addr.sin_addr) <= 0) {
    printf("convert address to address error\n");
    return -1;
  }


  if (connect(fd, (struct sockaddr*)&addr, sizeof(sockaddr_in)) < 0) {
    printf("connect error\n");
  }

  while ((n = read(fd, recvline, 50)) > 0) {
    recvline[n] = 0;

    if (fputs(recvline, stdout) == EOF) {
      printf("fputs error\n");
    }
  }

  if (n < 0) {
    printf("read error\n");
  }
 
  exit(0);
  return 0;
}

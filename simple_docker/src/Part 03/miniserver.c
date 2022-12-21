#include "fcgi_stdio.h"
#include <stdlib.h>

int main() {
    while (FCGI_Accept() >= 0) {
        printf("Content-type: text/html\r\n"
               "\r\nStatus: 200 OK"
               "\r\n"
               "<title>FastCGI Hello World!</title>"
               "<h1>FastCGI Hello World!</h1>");
    }
    return 0;
}

#define _WIN32_WINNT 0x0601
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#pragma comment(lib, "Ws2_32.lib")

#define DEFAULT_PORT "27015"
#define SERVER_IP "127.0.0.1"
#define BUFFER_SIZE 512


int main() {
    WSADATA wsaData;
    int iResult;
    const char* message = "TEMP= ";
    int temp = 20;
    char buffer2[40];
    char recvbuf[BUFFER_SIZE];

    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        printf("WSAStartup failed: %d\n", WSAGetLastError());
        return 1;
    }

    struct addrinfo hints, *result = NULL;
    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    iResult = getaddrinfo(SERVER_IP, DEFAULT_PORT, &hints, &result);
    if (iResult != 0) {
        printf("getaddrinfo failed: %d\n", iResult);
        WSACleanup();
        return 1;
    }

    SOCKET ConnectSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (ConnectSocket == INVALID_SOCKET) {
        printf("socket() failed: %ld\n", WSAGetLastError());
        freeaddrinfo(result);
        WSACleanup();
        return 1;
    }

    // Connect to server
    iResult = connect(ConnectSocket, result->ai_addr, (int)result->ai_addrlen);
    if (iResult == SOCKET_ERROR) {
        printf("connect() failed: %d\n", WSAGetLastError());
        closesocket(ConnectSocket);
        ConnectSocket = INVALID_SOCKET;
    }

    freeaddrinfo(result);

    if (ConnectSocket == INVALID_SOCKET) {
        WSACleanup();
        return 1;
    }

    // Send dummy sensor data
    for (int i = 0; i<10; i++){
        snprintf(buffer2, sizeof(buffer2), "TEMP=%d", temp);
        send(ConnectSocket, buffer2, sizeof(buffer2), 0);
        iResult = recv(ConnectSocket, recvbuf, BUFFER_SIZE, 0);
        if (iResult > 0) {
            recvbuf[iResult] = '\0';
            printf("Received from server: %s\n", recvbuf);
        }
        Sleep(1000);
    }

    // Receive server response


    closesocket(ConnectSocket);
    WSACleanup();
    return 0;
}
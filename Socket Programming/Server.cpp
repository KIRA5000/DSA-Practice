#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <iostream>
#include <fstream>
#include <vector>

class serverSocket
{
    int sockFd = -1, clientFd = -1, portNum;
    sockaddr_in addr_in, newAddr_in;
    std::string addr;

    public:

    serverSocket(string addr = "", int portNum = 8080)
    {
        this->addr = addr;
        this->portNum = portNum;
    }

    std::string createAndBind(int connectCount)
    {
        sockFd = socket(AF_INET, SOCK_STREAM, 0);

        if (sockFd < 0)
        {
            return "Error while creating socket";
        }

        addr_in.sin_family = AF_INET;
        addr_in.sin_port = htons(portNum);

        if (addr == "")
        {
            addr_in.sin_addr.s_addr = INADDR_ANY;
        }
        else
        {
            int ret = inet_pton(AF_INET, addr.c_str(), &addr_in.sin_addr);

            if (ret <= 0)
            {
                return "Invalid address. Adress not supported";
            }
        }

        int ret = bind(sockFd, (const sockaddr*)&addr_in, sizeof(addr_in));

        if (ret < 0)
        {
            return "Server binding failed: " + std::to_string(ret); 
        }

        listen(sockFd, connectCount);

        return std::string();
    }

    std::string accept()
    {
        socklen_t addr_len = 0;

        clientFd = accept(sockFd, (sockaddr*)&newAddr_in, &addr_len);

        if (clientFd < 0)
        {
            return "Accept failed";
        }

        return std::string();
    }

    void readAndAck(std::vector<char>& data, int& size)
    {
        int valRead = 1;

        while (valRead)
        {
            char buffer[1024] = {0};
            valRead = read(newSockFd, buffer, 1024);
            data.insert(data.end(), buffer, buffer + valRead);
            size += valRead;
        }

        send(clientFd, "Message have been recieved", 27, 0);        
    }

    ~serverSocket()
    {
        if (sockFd != -1)
        {
            close(sockFd);
        }

        if (clientFd != -1)
        {
            close(clientFd);
        }
    }
};

int main()
{
    
}
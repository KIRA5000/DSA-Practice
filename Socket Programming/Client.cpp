#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <iostream>
#include <fstream>
#include <vector>

class clientSocket
{
    int sockFd = -1, portNum;
    sockaddr_in addr_in;
    std::string addr;

    public:

    clientSocket(string addr, int portNum = 8080)
    {
        this->addr = addr;
        this->portNum = portNum;
    }

    std::string createAndConnect()
    {
        if (addr == "")
        {
            return "Set a valid ip address";
        }

        sockFd = socket(AF_INET, SOCK_STREAM, 0);

        if (socketfd < 0)
        {
            return "Error while creating socket";
        }

        addr_in.sin_family = AF_INET;
        addr_in.sin_port = htons(portNum);

        int ret = inet_pton(AF_INET, addr.c_str(), &addr_in.sin_addr);

        if (ret <= 0)
        {
            return "Invalid address. Adress not supported";
        }

        ret = connect(sockFd, (const sockaddr *)&addr, sizeof(addr));

        if (ret < 0)
        {
            return "Connection failed";
        }

        return std::string();
    }

    std::vector<char> sendAndAck(std::vector<char> data, int size)
    {
        send(sockFd, &data[0], size, 0);

        std::vector<char> data;
        int valRead = 1;

        while (valRead)
        {
            char buffer[1024] = {0};
            valRead = read(newSockFd, buffer, 1024);
            data.insert(data.end(), buffer, buffer + valRead);
            size += valRead;
        }

        return data;
    }

    ~clientSocket()
    {
        if (sockFd != -1)
        {
            close(sockFd);
        }
    }
}

int main(int argc, char* argv[])
{
    std::string path;

    std::cout << "Enter path name of file: ";
    std::cin >> path;

    std::ifstream iF(path, std::ios::in | std::ios::binary);

    iF.seekg(0, std::ios::end);
    size_t size = iF.tellg();
    iF.seekg(0, std::ios::beg);

    char* data = new char[size];

    iF.read(data, size);

    clientSocket cs("127.0.0.1");

    cs.createAndConnect();
    cs.sendAndAck(data, size);
    
    iF.close();

    return 0;
}
#include "TCPSocket.h"


TCPSocket::TCPSocket(int sock) {

    this->sock = sock;
    this->msg_buf = Buffer::allocate(PACKET_SIZE);
}

TCPSocket::~TCPSocket() {

    ::close(this->sock);
    this->msg_buf.free();
}

TCPSocket* TCPSocket::connect(const HostAndPort& hp) {
    
    struct addrinfo hints, *res;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = PF_INET;
    hints.ai_flags = AI_PASSIVE;
    hints.ai_socktype = SOCK_STREAM;
    res = NULL;

    if (getaddrinfo(hp.hostname, hp.port_str, &hints, &res) != 0) {
        perror("getaddrinfo");
        exit(1);
    }

    int com = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (com < 0) {
        perror("socket");
        freeaddrinfo(res);
        exit(1);
    }

    int one = 1;
    if (setsockopt(com, IPPROTO_TCP, TCP_NODELAY, (char*)&one, sizeof(one)) < 0) {
	perror("setsockopt");
	freeaddrinfo(res);
	::close(com);
	exit(1);
    }
    
    if (::connect(com, res->ai_addr, res->ai_addrlen) < 0) {
        perror("connect");
        freeaddrinfo(res);
        ::close(com);
        exit(1);
    }

    freeaddrinfo(res);

    return new TCPSocket(com);
}

void TCPSocket::send(void* buf, size_t count) const {

    if (write(this->sock, buf, count) < 0) {
	perror("write");
	exit(1);
    }
}

void TCPSocket::recv(void* buf, size_t count) const {

    if (read(this->sock, buf, count) < 0) {
	perror("read");
	exit(1);
    }
}

void TCPSocket::send_msg(MessageHeader header, char* body) {

    send(&header);
    send(body, header.body_size);
}

void TCPSocket::recv_header(MessageHeader* header) {
    recv(header);
}

char* TCPSocket::get_body(size_t body_size) {

    recv(this->msg_buf.addr, body_size);
    return this->msg_buf.addr;
}

void TCPSocket::clear_msg_buf() {
    this->msg_buf.clear();
}

void TCPSocket::send_close() {
    Communicator::send(MessageType::CLOSE);
}

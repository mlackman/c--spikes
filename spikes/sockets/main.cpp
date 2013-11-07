#include <boost/asio.hpp>
#include <iostream>
#include <functional>


class SocketServer {
public:

    typedef std::function<void(boost::asio::ip::tcp::socket, 
        const boost::system::error_code&)> SocketAvailableCallaback;

    SocketServer(boost::asio::io_service& io_service) : 
        mAcceptor(io_service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), 8080)),
        mSocket(io_service) {
        mAcceptor.async_accept(mSocket, [this](const boost::system::error_code& error) {
            if (mCallback) {
                mCallback(std::move(mSocket), error);
            }
        });
    }

    void setCallback(const SocketAvailableCallaback& callback) {
        mCallback = callback;
    }

private:

    boost::asio::ip::tcp::acceptor mAcceptor;
    boost::asio::ip::tcp::socket mSocket;

    SocketAvailableCallaback mCallback;

};

void notifyConnection(boost::asio::ip::tcp::socket socket, const boost::system::error_code& error) {
    std::cout << "connection" << std::endl;
}

 
int main(int argc, char** argv) {
    using namespace boost::asio;
    using namespace boost::asio::ip;

    io_service io_service;
    SocketServer socketServer(io_service);
    SocketServer::SocketAvailableCallaback cb(notifyConnection);
    socketServer.setCallback(cb);
    io_service.run();
}
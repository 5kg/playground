#include <iostream>
#include <ctime>
#include <boost/array.hpp>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/enable_shared_from_this.hpp>

using boost::asio::ip::tcp;

std::string make_daytime_string()
{
    using namespace std;
    time_t now = time(0);
    return ctime(&now);
}

class tcp_connection : public boost::enable_shared_from_this<tcp_connection> {
public:
    typedef boost::shared_ptr<tcp_connection> pointer;

    static pointer create(boost::asio::io_service& io_service)
    {
        return pointer(new tcp_connection(io_service));
    }

    tcp::socket& socket()
    {
        return socket_;
    }

    void start()
    {
        message_ = make_daytime_string();
        boost::asio::async_write(socket_, boost::asio::buffer(message_), [] (boost::system::error_code ec, std::size_t) {});
    }
private:
    tcp_connection(boost::asio::io_service& io_service)
        : socket_(io_service)
    {}

    tcp::socket socket_;
    std::string message_;
};

class tcp_server {
public:
    tcp_server(boost::asio::io_service& io_service)
        : acceptor_(io_service, tcp::endpoint(tcp::v4(), 13))
    {
        start_accept();
    }

private:
    void start_accept()
    {
        tcp_connection::pointer new_connection =
            tcp_connection::create(acceptor_.get_io_service());

        acceptor_.async_accept(new_connection->socket(),
                [this, new_connection] (const boost::system::error_code& error)
                {
                    if (!error) {
                        new_connection->start();
                    }

                    start_accept();
                });
    }

     tcp::acceptor acceptor_;
};

int main(int argc, char* argv[])
{
    try {
        boost::asio::io_service io_service;
        tcp_server server(io_service);

        io_service.run();
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}

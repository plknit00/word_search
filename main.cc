#include <boost/asio/ip/tcp.hpp>
#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>
#include <iostream>
#include <ostream>

#include "word_search.h"
#include <boost/beast.hpp>

namespace beast = boost::beast;         // from <boost/beast.hpp>
namespace http = beast::http;           // from <boost/beast/http.hpp>
namespace websocket = beast::websocket; // from <boost/beast/websocket.hpp>
namespace net = boost::asio;            // from <boost/asio.hpp>
using tcp = boost::asio::ip::tcp;       // from <boost/asio/ip/tcp.hpp>

namespace wsg {
void handler(tcp::socket socket) {
  websocket::stream<tcp::socket> ws{std::move(socket)};

  ws.set_option(
      websocket::stream_base::decorator([](websocket::response_type &res) {
        res.set(http::field::server, std::string(BOOST_BEAST_VERSION_STRING) +
                                         " websocket-server-sync");
      }));

  ws.accept();
  while (true) {
    std::cout << "a\n";
    beast::flat_buffer buffer;
    std::cout << "b\n";
    ws.read(buffer);
    std::cout << "c\n";
    ws.text(ws.got_text());
    std::cout << "d\n";
    ws.write(buffer.data());
    std::cout << "e\n";
  }
}
} // namespace wsg

int main(int argc, const char **argv) {

  /*if (argc != 2) {
    std::cout << "Expected input:" << std::endl;
    std::cout << "1. Address." << std::endl;
    std::cout << "2. Port." << std::endl;
    // std::cout << "Expected input:" << std::endl;
    // std::cout << "1. Dictionary of words separated by newline." << std::endl;
    // std::cout << "2. 2D letter grid separated by space or newline."
    //           << std::endl;
    return -1;
  }*/

  // auto const address = net::ip::make_address(argv[0]);
  // auto const port = static_cast<>argv[1];
  const auto address = net::ip::make_address("127.0.0.1");
  const short port = 1234;

  net::io_context ioc{/*concurrency_hint=*/
                      1};

  tcp::acceptor acceptor{ioc, {address, port}};
  while (true) {
    std::cout << "q\n";
    tcp::socket socket{ioc};
    std::cout << "r\n";
    acceptor.accept(socket);
    std::cout << "w\n";
    wsg::handler(std::move(socket));
  }

  //   FILE file1 = open(argv[0]);s
  //   FILE file2 = open(argv[1]);

  // You are given a dictionary of words, and a 2d grid of letters and you're
  // finding all possible word search words. Normally word search only allows
  // following lines along one of 8 directions, but this word search allows you
  // to follow lines along any rational angle. For a line that is at some angle,
  // you only include the tiles that the line exactly intercepts. So for like a
  // line that goes at an angle of atan(3 / 5), if you atarted from (0,0) it
  // would include (5,3), (10,6), etc

  //   if (!WSG::init_dict_words(file1)) {
  //     std::cout << "Dictionary of words is invalid." << std::endl;
  //     return -1;
  //   }

  //   if (!WSG::init_2d_letter_grid(file2)) {
  //     std::cout << "2D letter grid invalid." << std::endl;
  //     return -1;
  //   }

  // WordSearchGrid wsg;
  //  wsg.look_for_dict_words_in_grid();
  //  wsg.print_words_found();
}
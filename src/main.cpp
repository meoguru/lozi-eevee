/**
 * Copyright (c) 2014, LOZI., JSC
 * All rights reserved.
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited.
 * Proprietary and confidential.
 */

#include <algorithm>
#include <iostream>

#include <asio/ip/tcp.hpp>
#include <json11/json11.hpp>

int main() {
  try {
    std::string host = "lozi.vn";
    std::string path = "/trang-chu.json?city=Hồ+Chí+Minh";

    asio::ip::tcp::iostream s;

    // The entire sequence of I/O operations must complete within 30 seconds.
    // If an expiry occurs, the socket is automatically closed and the stream
    // becomes bad.
    s.expires_after(std::chrono::seconds(30));

    // Establish a connection to the server.
    s.connect(host, "http");
    if (!s) {
      std::cout << "Unable to connect: " << s.error().message() << "\n";
      return 1;
    }

    // Send the request. We specify the "Connection: close" header so that the
    // server will close the socket after transmitting the response. This will
    // allow us to treat all data up until the EOF as the content.
    s << "GET " << path << " HTTP/1.0\r\n";
    s << "Host: " << host << "\r\n";
    s << "Accept: */*\r\n";
    s << "Connection: close\r\n\r\n";

    // By default, the stream is tied with itself. This means that the stream
    // automatically flush the buffered output before attempting a read. It is
    // not necessary not explicitly flush the stream at this point.

    // Check that response is OK.
    std::string http_version;
    s >> http_version;

    unsigned int status_code;
    s >> status_code;

    std::string status_message;
    std::getline(s, status_message);

    if (!s || http_version.substr(0, 5) != "HTTP/") {
      std::cout << "Invalid response\n";
      return 1;
    }

    if (status_code != 200) {
      std::cout << "Response returned with status code " << status_code << "\n";
      return 1;
    }

    // Process the response headers, which are terminated by a blank line.
    std::string header;
    while (std::getline(s, header) && header != "\r") {
      std::cout << header << "\n";
    }
    std::cout << "\n";

    std::istreambuf_iterator<char> eos;
    std::string content(decltype(eos)(s), eos);
    std::string err;
    auto json = json11::Json::parse(content, err);

    if (!err.empty()) {
      std::cout << "Exception: " << err << "\n";
    }
    else {
      auto blocks = json["blocks"].array_items();

      std::cout << blocks.size() << " blocks are returned:\n";
      std::for_each(blocks.begin(), blocks.end(), [](const json11::Json& block) {
        std::cout << block["_id"].string_value() << "\n";
      });
    }
  }
  catch (std::exception& e) {
    std::cout << "Exception: " << e.what() << "\n";
  }

  return 0;
}

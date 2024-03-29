#include "bigquery/client.h"

int main(int argc, char* argv[]) {
  bigquery::ConnectionOptions options;
  bigquery::Client client(bigquery::MakeConnection(options));
  google::cloud::StatusOr<std::string> res = client.CreateSession(
      "aryann-bigquery", "bigquery-public-data:samples.shakespeare");

  if (res.ok()) {
    std::cout << "Session name: " << res.value() << "\n";
    return EXIT_SUCCESS;
  } else {
    std::cerr << "Session creation failed with error: " << res.status() << "\n";
    return EXIT_FAILURE;
  }
}

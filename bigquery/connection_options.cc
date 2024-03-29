#include <grpcpp/grpcpp.h>
#include <memory>
#include <string>

#include "bigquery/connection_options.h"
#include "bigquery/version.h"

namespace bigquery {
inline namespace BIGQUERY_CLIENT_NS {
namespace internal {
std::string BaseUserAgentPrefix() {
  // TODO(aryann): Add more info here.
  return "aryann-cpp-bigquery/" + VersionString();
}
}  // namespace internal

ConnectionOptions::ConnectionOptions(
    std::shared_ptr<grpc::ChannelCredentials> credentials)
    : credentials_(std::move(credentials)),
      bigquerystorage_endpoint_("bigquerystorage.googleapis.com"),
      user_agent_prefix_(internal::BaseUserAgentPrefix()) {}

ConnectionOptions::ConnectionOptions()
    : ConnectionOptions(grpc::GoogleDefaultCredentials()) {}

grpc::ChannelArguments ConnectionOptions::CreateChannelArguments() const {
  grpc::ChannelArguments channel_arguments;

  channel_arguments.SetUserAgentPrefix(user_agent_prefix());
  return channel_arguments;
}

}  // namespace BIGQUERY_CLIENT_NS
}  // namespace bigquery

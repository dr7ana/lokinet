#pragma once

#include <llarp/crypto/encrypted.hpp>
#include <llarp/crypto/types.hpp>
#include <llarp/path/path_types.hpp>
#include <vector>

#include "link_message.hpp"

namespace llarp
{
  /*
      Data messages to be sent via quic datagrams
  */

  struct RelayUpstreamMessage final : public AbstractDataMessage
  {
    Encrypted<MAX_LINK_MSG_SIZE - 128> enc;
    TunnelNonce nonce;

    bool
    decode_key(const llarp_buffer_t& key, llarp_buffer_t* buf) override;

    std::string
    bt_encode() const override;

    bool
    handle_message(Router* router) const override;

    void
    clear() override;

    const char*
    name() const override
    {
      return "RelayUpstream";
    }
    uint16_t
    priority() const override
    {
      return 0;
    }
  };

  struct RelayDownstreamMessage final : public AbstractDataMessage
  {
    Encrypted<MAX_LINK_MSG_SIZE - 128> enc;
    TunnelNonce nonce;

    bool
    decode_key(const llarp_buffer_t& key, llarp_buffer_t* buf) override;

    std::string
    bt_encode() const override;

    bool
    handle_message(Router* router) const override;

    void
    clear() override;

    const char*
    name() const override
    {
      return "RelayDownstream";
    }

    uint16_t
    priority() const override
    {
      return 0;
    }
  };
}  // namespace llarp

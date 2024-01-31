#pragma once

#include <llarp/router_id.hpp>
#include <llarp/router_contact.hpp>

#include <quic.hpp>

namespace llarp::link
{
  struct Connection
  {
    std::shared_ptr<oxen::quic::connection_interface> conn;
    std::shared_ptr<oxen::quic::BTRequestStream> control_stream;
    RouterContact remote_rc;

    // one side of a connection will be responsible for some things, e.g. heartbeat
    bool inbound{false};
    bool remote_is_relay{true};

    Connection(
        std::shared_ptr<oxen::quic::connection_interface>& c,
        std::shared_ptr<oxen::quic::BTRequestStream>& s,
        const RouterContact& rc);
  };
}  // namespace llarp::link

/*
  TODO:
    - make control_stream a weak pointer?
*/

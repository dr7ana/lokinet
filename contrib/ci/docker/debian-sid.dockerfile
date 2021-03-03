FROM debian:sid
RUN /bin/bash -c 'echo "man-db man-db/auto-update boolean false" | debconf-set-selections'
RUN /bin/bash -c 'apt-get -o=Dpkg::Use-Pty=0 -q update && apt-get -o=Dpkg::Use-Pty=0 -q dist-upgrade -y && apt-get -o=Dpkg::Use-Pty=0 -q install -y eatmydata gdb cmake git ninja-build pkg-config ccache clang-11 libsodium-dev libsystemd-dev python3-dev libuv1-dev libunbound-dev nettle-dev libssl-dev libevent-dev libsqlite3-dev'
FROM --platform=linux/amd64 ubuntu:latest

# Install necessary packages
RUN apt update && apt install -y \
    gcc \
    gdb \
    make \
    nasm \
    binutils \
    libc6-dev \
    vim \
    build-essential \
    && rm -rf /var/lib/apt/lists/*

# Set working directory
WORKDIR /workspace

# Default command to start a shell
CMD ["/bin/bash"]

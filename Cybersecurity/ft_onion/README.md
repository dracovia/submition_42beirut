# ft_onion

*This project has been created as part of the 42 curriculum by 'mfassad'*

## Description

**ft_onion** is a Docker-based web server deployment project.

The goal is to create a secure static website server accessible through
a **Tor hidden service (`.onion`)** while providing secure remote
administration through SSH.

The project uses:

-   Nginx as the web server
-   Tor as the hidden service provider
-   OpenSSH for remote administration
-   Docker for containerization
-   Docker Compose for service management

## Architecture

    ft_onion container

    ├── Nginx
    │     |
    │     └── Static website (HTTP port 80)
    │
    ├── OpenSSH
    │     |
    │     └── Secure administration (SSH port 4242)
    │
    └── Tor
          |
          └── Hidden service (.onion address)

## Project Structure

    ft_onion/

    ├── Dockerfile
    ├── docker-compose.yml
    ├── start.sh
    │
    ├── html/
    │   ├── index.html
    │   └── images/
    │
    ├── nginx/
    │   └── nginx.conf
    │
    ├── ssh/
    │   ├── sshd_config
    │   └── authorized_keys
    │
    └── tor/
        └── torrc

# Docker Setup

## Build

``` bash
docker build -t ft_onion .
```

## Run

``` bash
docker compose up
```

The container starts:

-   sshd
-   nginx
-   tor

The generated onion address is displayed during startup.

# Web Server

Nginx serves the website from:

    /var/www/html

The website is available through HTTP port 80.

Request flow:

    Client
      |
      v
    Nginx :80
      |
      v
    /var/www/html/index.html

# Tor Hidden Service

Tor provides anonymous access to the website.

Configuration:

    tor/torrc

contains:

    HiddenServiceDir /var/lib/tor/ft_onion/
    HiddenServicePort 80 127.0.0.1:80

The Tor identity is stored in a Docker volume to keep the same onion
address after restarting containers.

# SSH Configuration

SSH is enabled on:

    Port 4242

Connection:

``` bash
ssh -p 4242 username@localhost
```

# SSH Hardening

## Dedicated User Account

Remote administration is performed using a normal user instead of root.

The user is created with:

``` bash
useradd -m -s /bin/bash fassa
```

and added to sudo:

``` bash
usermod -aG sudo fassa
```

This follows the principle of least privilege.

## Disable Root Login

Configuration:

    PermitRootLogin no

Direct SSH access using the root account is disabled.

## Disable Password Authentication

Configuration:

    PasswordAuthentication no

SSH passwords are disabled to prevent brute-force attacks.

Authentication relies only on SSH keys.

## Public Key Authentication

The public key is stored in:

    /home/fassa/.ssh/authorized_keys

Permissions:

    .ssh              700
    authorized_keys   600

Authentication flow:

    Client
     |
     | private key
     v
    SSH authentication
     |
     v
    Server checks authorized_keys
     |
     v
    Access granted

## SSH Configuration

The hardened SSH configuration contains:

    Port 4242

    PermitRootLogin no

    PasswordAuthentication no

    PubkeyAuthentication yes

# Security Benefits

  Feature               Protection
  --------------------- -------------------------------------
  Custom SSH port       Reduces automated scans
  Disabled root login   Prevents direct root access
  Disabled passwords    Prevents password brute force
  SSH keys              Strong cryptographic authentication
  Dedicated user        Limits privileges
  File permissions      Protects authentication files

# Docker Volume Persistence

Tor keys are stored in a persistent volume.

Without persistence:

    Container deleted
           |
           v
    New onion address

With persistence:

    Container deleted
           |
           v
    Same Tor identity
           |
           v
    Same .onion address

# Useful Commands

Start:

``` bash
docker compose up
```

Stop:

``` bash
docker compose down
```

Enter container:

``` bash
docker exec -it ft_onion_server bash
```

Check containers:

``` bash
docker ps
```

SSH test:

``` bash
ssh -p 4242 fassa@localhost
```

# Technologies Used

-   Docker
-   Docker Compose
-   Ubuntu 24.04
-   Nginx
-   OpenSSH
-   Tor Hidden Services
-   HTML/CSS/JavaScript


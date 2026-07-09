This project has been created as part of the 42 curriculum by mfassad.

## NetPractice

## Description

NetPractice is a practical networking project from the 42 curriculum. The goal of the project is to understand the basics of computer networking by configuring small simulated networks.

The project focuses on TCP/IP addressing, subnet masks, default gateways, routers, switches, and routing tables. Each level contains a broken network configuration, and the objective is to fix the editable fields so that the required hosts and interfaces can communicate correctly.

The training interface provides 10 levels. For each level, the correct configuration must be exported and submitted.

## Instructions

## Running the Training Interface

First, download and extract the NetPractice files provided on the project page.

Then, from the extracted project folder, run:

bash
./run.sh

If run.sh does not work, the interface can be launched manually with:

bash
python3 -m http.server 49242

Then open:

text
http://localhost:49242

## Using the Interface

1. Enter the correct 42 login in the training interface.
2. Solve each of the 10 levels by editing the available network configuration fields.
3. Use the *Check again* button to test the configuration.
4. Read the logs at the bottom of the page to understand routing, gateway, or addressing errors.
5. When a level is completed, use *Get my config* to export the configuration file.
6. Repeat this process for all 10 levels.

## Submission Requirements

The repository must contain:

text
README.md
level1 configuration file
level2 configuration file
level3 configuration file
level4 configuration file
level5 configuration file
level6 configuration file
level7 configuration file
level8 configuration file
level9 configuration file
level10 configuration file

The 10 exported configuration files, one for each level, must be placed at the root of the Git repository.

Only the files present in the repository will be evaluated during the defense.

## Networking Concepts Studied

## IPv4 Addressing

An IPv4 address identifies a device on a network. It is written as four decimal numbers separated by dots, for example:

text
192.168.1.10

Each device must have a valid IP address that belongs to the correct network.

## Subnet Masks

A subnet mask defines which part of an IP address represents the network and which part represents the host.

Example:

text
IP:   192.168.1.10
Mask: 255.255.255.0

This means the device belongs to the 192.168.1.0/24 network.

## Network Address, Usable Hosts, and Broadcast Address

Each subnet has:

| Element | Meaning |
|---|---|
| Network address | The first address of the subnet |
| Usable host range | Addresses that can be assigned to devices |
| Broadcast address | The last address of the subnet |

For example:

text
192.168.1.0/24

The usable host range is:

text
192.168.1.1 -> 192.168.1.254

## Default Gateway

A default gateway is the router address used by a host to reach destinations outside its own subnet.

Example:

text
Host:    192.168.1.10/24
Gateway: 192.168.1.1

The gateway must be in the same subnet as the host.

## Routers

A router connects different networks. Each router interface usually belongs to a different subnet.

Routers use routing tables to decide where packets should be forwarded.

## Switches

A switch connects devices inside the same local network. It does not route traffic between different subnets.

text
Switch = same network
Router = different networks

## Routing Tables

A routing table tells a host or router where to send packets.

A route usually contains:

text
Destination network
Subnet mask
Gateway / next hop

A default route is written as:

text
0.0.0.0/0

It means that any unknown destination should be sent to the specified gateway.

## OSI Model

NetPractice mainly focuses on:

| OSI Layer | Role in this project |
|---|---|
| Layer 2 - Data Link | Switching and local network communication |
| Layer 3 - Network | IP addressing, routers, gateways, and routes |
| Layer 4 - Transport | TCP/UDP concepts, but not the main focus of the project |

## Useful Debugging Method

For each level, I followed this logic:

1. Identify which devices are connected to the same network.
2. Check that IP addresses and masks are valid.
3. Make sure hosts have the correct default gateway.
4. Make sure router interfaces are in the correct subnets.
5. Check routing tables for forward and reverse paths.
6. Use the logs to find errors such as invalid routes, missing gateways, or unreachable next hops.

## Resources

The following concepts and resources were used to complete the project:

- TCP/IP addressing
- IPv4 subnetting
- Subnet masks and CIDR notation
- Default gateways
- Routers and switches
- Routing tables
- OSI model basics
- NetPractice subject PDF
- NetPractice training interface logs
- Peer discussion and testing during practice

## AI Usage

AI was used as a learning assistant to explain networking concepts, especially:

- IPv4 addressing
- Subnet masks
- Usable host ranges
- Default gateways
- Routing tables
- Forward and reverse packet paths
- Understanding NetPractice error logs

AI was not used as a replacement for understanding the project. All final configurations were tested manually in the NetPractice interface, and the concepts were reviewed to prepare for peer evaluation and defense.
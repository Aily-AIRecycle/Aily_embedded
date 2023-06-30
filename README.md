# Aily Embedded System
![License](https://img.shields.io/github/license/Aily-AIRecycle/Aily_embedded)
![GitHub contributors](https://img.shields.io/github/contributors/Aily-AIRecycle/Aily_embedded)

This repository contains the Arduino source code for the Aily Trash Sorter project, which utilizes YOLOv5 for automatically discriminating and discarding general trash, plastic, and cans.

## Table of Contents

- [Aily Embedded System](#aily-embedded-system)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Installation](#installation)
  - [Usage](#usage)
  - [Code Files](#code-files)
  - [Contributors](#contributors)
  - [License](#license)

## Introduction

The main goal of this project is to create a machine that can automatically sort different types of trash. The Arduino source code provided in this repository controls various components of the trash sorting system, including the timing of garbage falling and the manipulation of the trash box. The system is designed to work in conjunction with the YOLOv5 object detection model to identify and sort general trash, plastic, and cans.

## Installation

To run this code on your Arduino board, follow the steps below:

1. Set up the Arduino IDE on your computer.
2. Connect the Arduino board to your computer using a USB cable.
3. Open the Arduino IDE and create a new sketch for each code file provided in this repository.
4. Copy the content of each code file into their respective sketches.
5. Verify and upload each sketch to your Arduino board.
6. Ensure that the necessary hardware components, such as stepper motors, servos, and the nRF24L01 radio module, are properly connected to the Arduino board as per the pin configurations specified in the code.

Please note that you may need to install additional libraries, such as `Servo`, `SPI`, and `RF24`, before uploading the code. These libraries can be installed using the Arduino Library Manager.

## Usage

Once the code is successfully uploaded to your Arduino board, you can use it as follows:

1. Ensure that the trash sorting system is set up properly and all connections are secure.
2. Power on the system and wait for it to initialize.
3. Monitor the Arduino Serial Monitor or any other serial communication software to observe the status and debug messages.
4. The `compressor.ino` code is used to control the compressor that generates the air pressure for the trash to fall.
5. The `rail.ino` code handles the communication with the YOLOv5 model and the movement of the trash box along the rail system.
6. The `box.ino` code receives commands via the radio module and controls the servos that manipulate the trash box.
Please refer to the individual code files for more specific details on their functionalities.

## Code Files

This repository includes the following code files:

- `rail.ino`: Controls the timing of garbage falling and the movement of the trash box along the rail system.
- `box.ino`: Receives commands via a radio module and controls the servos that manipulate the trash box.
- `compressor.ino`: Controls the compressor.
- `rf24-send.ino`: Sends commands to the trash sorting system using the nRF24L01 radio module.
- `rf24-receive.ino`: Receives commands on the trash sorting system using the nRF24L01 radio module.
- `tb6600.ino`: Controls the stepper motor for precise movement.

## Contributors

- [Lee InHo](https://github.com/2inlee) - Project Manager, AIoT Device Architect, Embedded Developer
- [Lee SangHoon](https://github.com/dltkdgns00) - AIoT Device Architect, Embedded Developer

## License

The source code in this repository is licensed under the [MIT License](LICENSE). Feel free to use, modify, and distribute it as per the terms of the license.

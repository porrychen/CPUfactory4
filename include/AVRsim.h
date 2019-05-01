// Copyright 2019 Roie R. Black
#pragma once
#include <cstdint>
#include <fstream>
#include <string>
#include <vector>
#include "Component.h"
#include "Wire.h"
#include "microcode.h"

class AVRsim {
 public:
    AVRsim();
    void builder(std::string fname);
    uint16_t tick(uint16_t pc);
    uint16_t get_signal_by_name(std::string n);
    void set_debug(void);
 private:
    bool debug;
    uint16_t pc;
    std::vector<Component *> parts;
    std::vector<Wire *> wires;
    std::vector<uCode *> ucodes;
    int nparts;
    int nwires;
    int nucodes;
    Component * find_part(std::string name);
    Pin * find_pin(Component * part, std::string name);
    void attach_driven(Wire * w, std::string id);
    void attach_drives(Wire * w, std::string id);
};

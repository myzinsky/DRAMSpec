/*
 * Copyright (c) 2015, University of Kaiserslautern
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER
 * OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * Authors: Omar Naji
 *          Matthias Jung
 *          Christian Weis
 *          Kamal Haddad
 *          Andr'e Lucas Chinazzo
 */

#ifndef CHIPTEST_CPP
#define CHIPTEST_CPP

#include <boost/test/included/unit_test.hpp>

#include "../../core/Chip.h"

BOOST_AUTO_TEST_SUITE( testChip )

BOOST_AUTO_TEST_CASE( checkChip_real_input )
{
    int sim_argc = 5;
    char* sim_argv[] = {"./executable",
                        "-t",
                        "../../technology_input/test_technology.json",
                        "-p",
                        "../../architecture_input/test_architecture.json"};

    ArgumentsParser inputFileName(sim_argc, sim_argv);

    std::string exceptionMsg("Empty");
    try {
        inputFileName.runArgParser();
    }catch (std::string exceptionMsgThrown){
        exceptionMsg = exceptionMsgThrown;
    }

    std::string expectedMsg("Empty");
    BOOST_CHECK_MESSAGE( exceptionMsg == expectedMsg,
                        "Error message different from what was expected."
                        << "\nExpected: " << expectedMsg
                        << "\nGot: " << exceptionMsg);

    Chip chip(inputFileName.technologyFileName[0],
                      inputFileName.architectureFileName[0]);

    BOOST_CHECK_MESSAGE( chip.chipStorage == 1*drs::gibibits,
                        "Chip storage size different from the expected."
                        << "\nExpected: " << 1*drs::gibibits
                        << "\nGot: " << chip.chipStorage);

    BOOST_CHECK_MESSAGE( ceil(chip.chipWidth) == 11199*drs::micrometer,
                        "Width of chip different from the expected."
                        << "\nExpected: " << 11199*drs::micrometer
                        << "\nGot: " << ceil(chip.chipWidth));

    BOOST_CHECK_MESSAGE( ceil(chip.chipHeight) == 4747*drs::micrometer,
                        "Height of chip different from the expected."
                        << "\nExpected: " << 4747*drs::micrometer
                        << "\nGot: " << ceil(chip.chipHeight));

    BOOST_CHECK_MESSAGE( ceil(chip.chipArea) == 54*drs::square_millimeter,
                        "Area of chip different from the expected."
                        << "\nExpected: " << 54*drs::square_millimeter
                        << "\nGot: " << ceil(chip.chipArea));

}

BOOST_AUTO_TEST_CASE( checkChip_dummy_input )
{
    int sim_argc = 5;
    char* sim_argv[] = {"./executable",
                        "-t",
                        "../../technology_input/tech_dummy_input.json",
                        "-p",
                        "../../architecture_input/arch_dummy_input.json"};

    ArgumentsParser inputFileName(sim_argc, sim_argv);

    std::string exceptionMsg("Empty");
    try {
        inputFileName.runArgParser();
    }catch (std::string exceptionMsgThrown){
        exceptionMsg = exceptionMsgThrown;
    }

    std::string expectedMsg("Empty");
    BOOST_CHECK_MESSAGE( exceptionMsg == expectedMsg,
                        "Error message different from what was expected."
                        << "\nExpected: " << expectedMsg
                        << "\nGot: " << exceptionMsg);

    try {
        Chip chip(inputFileName.technologyFileName[0],
                  inputFileName.architectureFileName[0]);
    }catch (std::string exceptionMsgThrown){
        exceptionMsg = exceptionMsgThrown;
    }

    expectedMsg = "[ERROR] Architecture must have ";
    expectedMsg.append("1, 2 or 4 tile per bank.");
    BOOST_CHECK_MESSAGE( exceptionMsg == expectedMsg,
                        "Error message different from what was expected."
                        << "\nExpected: " << expectedMsg
                        << "\nGot: " << exceptionMsg);

    Chip chip;
    chip.readjson(inputFileName.technologyFileName[0],
                  inputFileName.architectureFileName[0]);
    try {
        chip.chipCompute();
    }catch (std::string exceptionMsgThrown){
        exceptionMsg = exceptionMsgThrown;
    }

    expectedMsg = "[ERROR] Architecture must have ";
    expectedMsg.append("1, 2, 4, 6, 8 or 16 banks.");
    BOOST_CHECK_MESSAGE( exceptionMsg == expectedMsg,
                        "Error message different from what was expected."
                        << "\nExpected: " << expectedMsg
                        << "\nGot: " << exceptionMsg);


}

BOOST_AUTO_TEST_CASE( checkChip_different_bank_configs )
{
    int sim_argc = 5;
    char* sim_argv[] = {"./executable",
                        "-t",
                        "../../technology_input/test_technology.json",
                        "-p",
                        "../../architecture_input/test_architecture.json"};

    ArgumentsParser inputFileName(sim_argc, sim_argv);

    std::string exceptionMsg("Empty");
    try {
        inputFileName.runArgParser();
    }catch (std::string exceptionMsgThrown){
        exceptionMsg = exceptionMsgThrown;
    }

    std::string expectedMsg("Empty");
    BOOST_CHECK_MESSAGE( exceptionMsg == expectedMsg,
                        "Error message different from what was expected."
                        << "\nExpected: " << expectedMsg
                        << "\nGot: " << exceptionMsg);

    Chip chip(inputFileName.technologyFileName[0],
                      inputFileName.architectureFileName[0]);

    chip.nBanks = 1.0*drs::bank;
    try {
        chip.tileCompute();
    }catch (std::string exceptionMsgThrown){
        std::cerr << exceptionMsgThrown << std::endl;
    }
    chip.bankCompute();
    chip.chipCompute();

    BOOST_CHECK_MESSAGE( chip.chipStorage == 1*drs::gibibits,
                        "Chip storage size different from the expected."
                        << "\nExpected: " << 1*drs::gibibits
                        << "\nGot: " << chip.chipStorage);

    BOOST_CHECK_MESSAGE( ceil(chip.chipWidth) == 2799*drs::micrometer,
                        "Width of chip different from the expected."
                        << "\nExpected: " << 2799*drs::micrometer
                        << "\nGot: " << ceil(chip.chipWidth));

    BOOST_CHECK_MESSAGE( ceil(chip.chipHeight) == 15428*drs::micrometer,
                        "Height of chip different from the expected."
                        << "\nExpected: " << 15428*drs::micrometer
                        << "\nGot: " << ceil(chip.chipHeight));

    BOOST_CHECK_MESSAGE( ceil(chip.chipArea) == 44*drs::square_millimeter,
                        "Area of chip different from the expected."
                        << "\nExpected: " << 44*drs::square_millimeter
                        << "\nGot: " << ceil(chip.chipArea));

    chip.nBanks = 2.0*drs::bank;
    try {
        chip.tileCompute();
    }catch (std::string exceptionMsgThrown){
        std::cerr << exceptionMsgThrown << std::endl;
    }
    chip.bankCompute();
    chip.chipCompute();

    BOOST_CHECK_MESSAGE( chip.chipStorage == 1*drs::gibibits,
                        "Chip storage size different from the expected."
                        << "\nExpected: " << 1*drs::gibibits
                        << "\nGot: " << chip.chipStorage);

    BOOST_CHECK_MESSAGE( ceil(chip.chipWidth) == 5599*drs::micrometer,
                        "Width of chip different from the expected."
                        << "\nExpected: " << 5599*drs::micrometer
                        << "\nGot: " << ceil(chip.chipWidth));

    BOOST_CHECK_MESSAGE( ceil(chip.chipHeight) == 8111*drs::micrometer,
                        "Height of chip different from the expected."
                        << "\nExpected: " << 8111*drs::micrometer
                        << "\nGot: " << ceil(chip.chipHeight));

    BOOST_CHECK_MESSAGE( ceil(chip.chipArea) == 46*drs::square_millimeter,
                        "Area of chip different from the expected."
                        << "\nExpected: " << 46*drs::square_millimeter
                        << "\nGot: " << ceil(chip.chipArea));

    chip.nBanks = 4.0*drs::bank;
    try {
        chip.tileCompute();
    }catch (std::string exceptionMsgThrown){
        std::cerr << exceptionMsgThrown << std::endl;
    }
    chip.bankCompute();
    chip.chipCompute();

    BOOST_CHECK_MESSAGE( chip.chipStorage == 1*drs::gibibits,
                        "Chip storage size different from the expected."
                        << "\nExpected: " << 1*drs::gibibits
                        << "\nGot: " << chip.chipStorage);

    BOOST_CHECK_MESSAGE( ceil(chip.chipWidth) == 5599*drs::micrometer,
                        "Width of chip different from the expected."
                        << "\nExpected: " << 5599*drs::micrometer
                        << "\nGot: " << ceil(chip.chipWidth));

    BOOST_CHECK_MESSAGE( ceil(chip.chipHeight) == 8406*drs::micrometer,
                        "Height of chip different from the expected."
                        << "\nExpected: " << 8406*drs::micrometer
                        << "\nGot: " << ceil(chip.chipHeight));

    BOOST_CHECK_MESSAGE( ceil(chip.chipArea) == 48*drs::square_millimeter,
                        "Area of chip different from the expected."
                        << "\nExpected: " << 48*drs::square_millimeter
                        << "\nGot: " << ceil(chip.chipArea));

    chip.nBanks = 6.0*drs::bank;
    try {
        chip.tileCompute();
    }catch (std::string exceptionMsgThrown){
        std::cerr << exceptionMsgThrown << std::endl;
    }
    chip.bankCompute();
    chip.chipCompute();

    BOOST_CHECK_MESSAGE( chip.chipStorage == 1*drs::gibibits,
                        "Chip storage size different from the expected."
                        << "\nExpected: " << 1*drs::gibibits
                        << "\nGot: " << chip.chipStorage);

    BOOST_CHECK_MESSAGE( ceil(chip.chipWidth) == 8399*drs::micrometer,
                        "Width of chip different from the expected."
                        << "\nExpected: " << 8399*drs::micrometer
                        << "\nGot: " << ceil(chip.chipWidth));

    BOOST_CHECK_MESSAGE( ceil(chip.chipHeight) == 5967*drs::micrometer,
                        "Height of chip different from the expected."
                        << "\nExpected: " << 5967*drs::micrometer
                        << "\nGot: " << ceil(chip.chipHeight));

    BOOST_CHECK_MESSAGE( ceil(chip.chipArea) == 51*drs::square_millimeter,
                        "Area of chip different from the expected."
                        << "\nExpected: " << 51*drs::square_millimeter
                        << "\nGot: " << ceil(chip.chipArea));

    chip.nBanks = 8.0*drs::bank;
    try {
        chip.tileCompute();
    }catch (std::string exceptionMsgThrown){
        std::cerr << exceptionMsgThrown << std::endl;
    }
    chip.bankCompute();
    chip.chipCompute();

    BOOST_CHECK_MESSAGE( chip.chipStorage == 1*drs::gibibits,
                        "Chip storage size different from the expected."
                        << "\nExpected: " << 1*drs::gibibits
                        << "\nGot: " << chip.chipStorage);

    BOOST_CHECK_MESSAGE( ceil(chip.chipWidth) == 11199*drs::micrometer,
                        "Width of chip different from the expected."
                        << "\nExpected: " << 11199*drs::micrometer
                        << "\nGot: " << ceil(chip.chipWidth));

    BOOST_CHECK_MESSAGE( ceil(chip.chipHeight) == 4747*drs::micrometer,
                        "Height of chip different from the expected."
                        << "\nExpected: " << 4747*drs::micrometer
                        << "\nGot: " << ceil(chip.chipHeight));

    BOOST_CHECK_MESSAGE( ceil(chip.chipArea) == 54*drs::square_millimeter,
                        "Area of chip different from the expected."
                        << "\nExpected: " << 54*drs::square_millimeter
                        << "\nGot: " << ceil(chip.chipArea));

}

BOOST_AUTO_TEST_SUITE_END()

#endif // CHIPTEST_CPP

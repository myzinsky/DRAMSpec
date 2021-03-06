/*
 * Copyright (c) 2017, University of Kaiserslautern
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
 * Authors: Omar Naji,
 *          Matthias Jung,
 *          Christian Weis,
 *          Kamal Haddad,
 *          Andre Lucas Chinazzo
 */



#ifndef TECHNOLOGYVALUESTEST_CPP
#define TECHNOLOGYVALUESTEST_CPP

#include <boost/test/included/unit_test.hpp>

#include "../../parser/TechnologyValues.h"

BOOST_AUTO_TEST_SUITE( testTechnologyValues )

BOOST_AUTO_TEST_CASE( checkInputTechnologyValues_real_input )
{
    int sim_argc = 5;
    char* sim_argv[] = {"./executable",
                        "-t",
                        "technology_input/test_technology.json",
                        "-p",
                        "architecture_input/test_architecture.json"};

    ArgumentsParser inputFileName(sim_argc, sim_argv);


    string exceptionMsg("Empty");
    try {
        inputFileName.runArgParser();
    }catch (string exceptionMsgThrown){
        exceptionMsg = exceptionMsgThrown;
    }
    string expectedMsg("Empty");
    BOOST_CHECK_MESSAGE( exceptionMsg == expectedMsg,
                        "Error message different from what was expected."
                        << "\nExpected: " << expectedMsg
                        << "\nGot: " << exceptionMsg);

    TechnologyValues techValues;
    try {
        techValues = TechnologyValues(inputFileName.technologyFileName[0],
                         inputFileName.architectureFileName[0]);
    }catch (string exceptionMsgThrown){
        exceptionMsg = exceptionMsgThrown;
    }
    expectedMsg = string("Empty");
    if ( exceptionMsg != expectedMsg ) {
        BOOST_FAIL( exceptionMsg );
    }

    BOOST_CHECK_MESSAGE( techValues.technologyNode
                         == 58*drs::nanometer,
                         "Technology node"
                         " different from the expected."
                         << "\nExpected: " << 58*drs::nanometer
                         << "\nGot: " << techValues.technologyNode);

    BOOST_CHECK_MESSAGE( techValues.vpp
                         == 2.8*si::volt,
                         "VPP"
                         " different from the expected."
                         << "\nExpected: " << 2.8*si::volt
                         << "\nGot: " << techValues.vpp);

    BOOST_CHECK_MESSAGE( techValues.vdd
                         == 1.1*si::volt,
                         "VDD"
                         " different from the expected."
                         << "\nExpected: " << 1.1*si::volt
                         << "\nGot: " << techValues.vdd);

    BOOST_CHECK_MESSAGE( techValues.wireResistance
                         == 100*drs::ohm_per_millimeter,
                         "Wire resistance"
                         " different from the expected."
                         << "\nExpected: " << 100*drs::ohm_per_millimeter
                         << "\nGot: " << techValues.wireResistance);

    BOOST_CHECK_MESSAGE( techValues.wireCapacitance
                         == 382*drs::femtofarads_per_millimeter,
                         "Wire capacitance"
                         " different from the expected."
                         << "\nExpected: "
                         << 382*drs::femtofarads_per_millimeter
                         << "\nGot: " << techValues.wireCapacitance);

    BOOST_CHECK_MESSAGE( techValues.capacitancePerCell
                         == 20*drs::femtofarads,
                        "Capacitance per cell"
                        " different from the expected."
                        << "\nExpected: " << 20*drs::femtofarads
                        << "\nGot: " << techValues.capacitancePerWLCell);

    BOOST_CHECK_MESSAGE( techValues.resistancePerCell
                         == 20*drs::kiloohm,
                        "Resistance per cell"
                        " different from the expected."
                        << "\nExpected: " << 20*drs::kiloohm
                        << "\nGot: " << techValues.resistancePerWLCell);

    BOOST_CHECK_MESSAGE( techValues.cellWidth
                         == 0.12*drs::micrometer,
                         "Cell width"
                         " different from the expected."
                         << "\nExpected: " << 0.12*drs::micrometer
                         << "\nGot: " << techValues.cellWidth);

    BOOST_CHECK_MESSAGE( techValues.cellHeight
                         == 0.18*drs::micrometer,
                         "Cell height"
                         " different from the expected."
                         << "\nExpected: " << 0.18*drs::micrometer
                         << "\nGot: " << techValues.cellHeight);

    BOOST_CHECK_MESSAGE( techValues.capacitancePerBLCell
                         == 160*drs::attofarads,
                        "Capacitance per bitline cell"
                        " different from the expected."
                        << "\nExpected: " << 160*drs::attofarads
                        << "\nGot: " << techValues.capacitancePerBLCell);

    BOOST_CHECK_MESSAGE( techValues.resistancePerBLCell
                         == 36*drs::ohm,
                        "Resistance per bitline cell"
                        " different from the expected."
                        << "\nExpected: " << 36*drs::ohm
                        << "\nGot: " << techValues.resistancePerBLCell);

    BOOST_CHECK_MESSAGE( techValues.capacitancePerWLCell
                         == 150*drs::attofarads,
                        "Capacitance per wordline cell"
                        " different from the expected."
                        << "\nExpected: " << 150*drs::attofarads
                        << "\nGot: " << techValues.capacitancePerWLCell);

    BOOST_CHECK_MESSAGE( techValues.resistancePerWLCell
                         == 46*drs::ohm,
                        "Resistance per wordline cell"
                        " different from the expected."
                        << "\nExpected: " << 46*drs::ohm
                        << "\nGot: " << techValues.resistancePerWLCell);

    BOOST_CHECK_MESSAGE( techValues.BLSenseAmpHeight
                         == 20*drs::micrometer,
                         "Bitline sense amp. height"
                         " different from the expected."
                         << "\nExpected: " << 20*drs::micrometer
                         << "\nGot: " << techValues.BLSenseAmpHeight);

    BOOST_CHECK_MESSAGE( techValues.LWLDriverWidth
                         == 9*drs::micrometer,
                         "Wordline driver width"
                         " different from the expected."
                         << "\nExpected: " << 9*drs::micrometer
                         << "\nGot: " << techValues.LWLDriverWidth);

    BOOST_CHECK_MESSAGE( techValues.LWLDriverResistance
                         == 1000*drs::ohm,
                         "Local wordline driver resistance"
                         " different from the expected."
                         << "\nExpected: " << 1000*drs::ohm
                         << "\nGot: " << techValues.LWLDriverResistance);

    BOOST_CHECK_MESSAGE( techValues.rowDecoderWidth
                         == 240*drs::micrometer,
                         "Row decoder (between tiles) width"
                         " different from the expected."
                         << "\nExpected: " << 240*drs::micrometer
                         << "\nGot: " << techValues.rowDecoderWidth);

    BOOST_CHECK_MESSAGE( techValues.GWLDriverResistance
                         == 400*drs::ohm,
                         "Global wordline driver resistance"
                         " different from the expected."
                         << "\nExpected: " << 400*drs::ohm
                         << "\nGot: " << techValues.GWLDriverResistance);

    BOOST_CHECK_MESSAGE( techValues.Issa
                         == 300*drs::microampere_per_bit,
                         "SSA current"
                         " different from the expected."
                         << "\nExpected: " << 300*drs::microampere_per_bit
                         << "\nGot: " << techValues.Issa);

    BOOST_CHECK_MESSAGE( techValues.WRDriverResistance
                         == 600*drs::ohm,
                         "WR restore driver resistance"
                         " different from the expected."
                         << "\nExpected: " << 600*drs::ohm
                         << "\nGot: " << techValues.WRDriverResistance);

    BOOST_CHECK_MESSAGE( techValues.colDecoderHeight
                         == 200*drs::micrometer,
                         "Column decoder (between tiles) width"
                         " different from the expected."
                         << "\nExpected: " << 200*drs::micrometer
                         << "\nGot: " << techValues.colDecoderHeight);

    BOOST_CHECK_MESSAGE( techValues.CSLDriverResistance
                         == 600*drs::ohm,
                         "CSL driver resistance"
                         " different from the expected."
                         << "\nExpected: " << 600*drs::ohm
                         << "\nGot: " << techValues.CSLDriverResistance);

    BOOST_CHECK_MESSAGE( techValues.CSLLoadCapacitance
                         == 8*drs::femtofarads,
                        "Load capacitance of CSL"
                        " different from the expected."
                        << "\nExpected around: " << 8*drs::femtofarads
                        << "\nGot: " << techValues.CSLLoadCapacitance);

    BOOST_CHECK_MESSAGE( techValues.GDLDriverResistance
                         == 600*drs::ohm,
                         "GDL driver resistance"
                         " different from the expected."
                         << "\nExpected: " << 600*drs::ohm
                         << "\nGot: " << techValues.GDLDriverResistance);

    BOOST_CHECK_MESSAGE( techValues.DQDriverHeight
                         == 250*drs::micrometer,
                         "DQ driver (between banks) height"
                         " different from the expected."
                         << "\nExpected: " << 250*drs::micrometer
                         << "\nGot: " << techValues.DQDriverHeight);

    BOOST_CHECK_MESSAGE( techValues.DQDriverResistance == 500*drs::ohm,
                         "DQ driver resistance different from the expected."
                         << "\nExpected: " << 500*drs::ohm
                         << "\nGot: " << techValues.DQDriverResistance);

    BOOST_CHECK_MESSAGE( techValues.idd2nFreqSlope
                         == 0.025*drs::milliamperes_per_megahertz_clock,
                         "Background current slope"
                         " different from the expected."
                         << "\nExpected: "
                         << 0.025*drs::milliamperes_per_megahertz_clock
                         << "\nGot: " << techValues.idd2nFreqSlope);

    BOOST_CHECK_MESSAGE( techValues.idd2nTempAlpha
                         == 0.6775*drs::milliamperes,
                         "Background current alpha coefficient"
                         " different from the expected."
                         << "\nExpected: " << 0.6775*drs::milliamperes
                         << "\nGot: " << techValues.idd2nTempAlpha);

    BOOST_CHECK_MESSAGE( techValues.idd2nTempBeta
                         == 0.04467*drs::eergeds,
                         "Background current beta coefficient"
                         " different from the expected."
                         << "\nExpected: " << 0.04467*drs::eergeds
                         << "\nGot: " << techValues.idd2nTempBeta);

    BOOST_CHECK_MESSAGE( techValues.idd2nRefTemp
                         == 25*bu::celsius::degrees,
                         "Background current reference temperature"
                         " different from the expected."
                         << "\nExpected: " << 25*bu::celsius::degrees
                         << "\nGot: " << techValues.idd2nRefTemp);

    BOOST_CHECK_MESSAGE( techValues.idd2nOffset
                         == 17*drs::milliamperes,
                         "Background current offset"
                         " different from the expected."
                         << "\nExpected: " << 17*drs::milliamperes
                         << "\nGot: " << techValues.idd2nOffset);

    BOOST_CHECK_MESSAGE( techValues.IddOcdRcvSlope
                         == 5.629*drs::microamperes_per_megahertz_clock,
                         "Current slope per IO pin"
                         " different from the expected."
                        << "\nExpected: "
                         << 5.629*drs::microamperes_per_megahertz_clock
                        << "\nGot: " << techValues.IddOcdRcvSlope);

    BOOST_CHECK_MESSAGE( techValues.fullySharedResourcesCurrent
                         == 2 * drs::milliamperes,
                         "Current of fully shared resources"
                         " different from the expected."
                        << "\nExpected: " << 2 * drs::milliamperes
                        << "\nGot: " << techValues.fullySharedResourcesCurrent);

    BOOST_CHECK_MESSAGE( techValues.semiSharedResourcesCurrent
                         == 0.5 * drs::milliamperes,
                         "Current of semi shared resources"
                         " different from the expected."
                        << "\nExpected: " << 0.5 * drs::milliamperes
                        << "\nGot: " << techValues.semiSharedResourcesCurrent);

    BOOST_CHECK_MESSAGE( techValues.nBanksPerSemiSharedResource
                         == 2,
                         "Number of banks per semi shared resources"
                         " different from the expected."
                        << "\nExpected: " << 2
                        << "\nGot: " << techValues.nBanksPerSemiSharedResource);

    BOOST_CHECK_MESSAGE( techValues.TSVHeight
                         == 0*drs::micrometer,
                         "Height of the TSV area needed for each bank I/O"
                         " different from the expected."
                        << "\nExpected: " << 0*drs::micrometer
                        << "\nGot: " << techValues.TSVHeight);

    BOOST_CHECK_MESSAGE( techValues.additionalLatencyTrl
                         == 1*drs::clock,
                         "Additional latency to trl"
                         " different from the expected."
                        << "\nExpected: " << 1*drs::clock
                        << "\nGot: " << techValues.additionalLatencyTrl);

    BOOST_CHECK_MESSAGE( techValues.driverEnableDelay
                         == 0.6*drs::nanoseconds,
                        "Driver enabling time different from the expected."
                        << "\nExpected around: " << 0.6*drs::nanoseconds
                        << "\nGot: " << techValues.driverEnableDelay);

    BOOST_CHECK_MESSAGE( techValues.inOutSSADelay
                         == 2*drs::nanoseconds,
                        "Secondary sense amplifier delay"
                        " different from the expected."
                        << "\nExpected around: " << 2*drs::nanoseconds
                        << "\nGot: " << techValues.inOutSSADelay);

    BOOST_CHECK_MESSAGE( techValues.cmdDecoderDelay
                         == 2*drs::nanoseconds,
                        "Command decoder delay"
                        " different from the expected."
                        << "\nExpected around: " << 2*drs::nanoseconds
                        << "\nGot: " << techValues.cmdDecoderDelay);

    BOOST_CHECK_MESSAGE( techValues.IODelay
                         == 1*drs::nanoseconds,
                        "IO interface Delay"
                        " different from the expected."
                        << "\nExpected around: " << 1*drs::nanoseconds
                        << "\nGot: " << techValues.IODelay);

    BOOST_CHECK_MESSAGE( techValues.SSAPrechargeDelay
                         == 1*drs::nanoseconds,
                        "Delay of SSA precharge"
                        " different from the expected."
                        << "\nExpected around: " << 1*drs::nanoseconds
                        << "\nGot: " << techValues.SSAPrechargeDelay);

    BOOST_CHECK_MESSAGE( techValues.tWRMargin
                         == 1*drs::nanoseconds,
                        "Security margin for write recovery"
                        " different from the expected."
                        << "\nExpected around: " << 1*drs::nanoseconds
                        << "\nGot: " << techValues.tWRMargin);

    BOOST_CHECK_MESSAGE( techValues.equalizerDelay
                         == 1*drs::nanoseconds,
                        "Equalizer circuit enabling delay"
                        " different from the expected."
                        << "\nExpected around: " << 1*drs::nanoseconds
                        << "\nGot: " << techValues.equalizerDelay);



    BOOST_CHECK_MESSAGE( techValues.dramType
                         == "DDR3",
                         "DRAM type"
                         " different from the expected."
                        << "\nExpected: " << "DDR3"
                        << "\nGot: " << techValues.dramType);

    BOOST_CHECK_MESSAGE( techValues.is3D
                         == false,
                         "3D flag"
                         " different from the expected."
                        << "\nExpected: " << false
                        << "\nGot: " << techValues.is3D);

    BOOST_CHECK_MESSAGE( techValues.isDLL
                         == true,
                         "DLL flag"
                         " different from the expected."
                        << "\nExpected: " << true
                        << "\nGot: " << techValues.isDLL);

    BOOST_CHECK_MESSAGE( techValues.channelSize
                         == 1*drs::gibibit,
                         "DRAM Size"
                         " different from the expected."
                        << "\nExpected: " << 1*drs::gibibit
                        << "\nGot: " << techValues.channelSize);

    BOOST_CHECK_MESSAGE( techValues.nBanks
                         == 8,
                         "Number of banks"
                         " different from the expected."
                        << "\nExpected: " << 8
                        << "\nGot: " << techValues.nBanks);

    BOOST_CHECK_MESSAGE( techValues.nHorizontalBanks
                         == INVALID_VALUE,
                         "Number of banks in the row"
                         " direction different from the expected."
                        << "\nExpected: " << INVALID_VALUE
                        << "\nGot: " << techValues.nHorizontalBanks);

    BOOST_CHECK_MESSAGE( techValues.nVerticalBanks
                         == INVALID_VALUE,
                         "Number of banks in the colunm"
                         " direction different from the expected."
                        << "\nExpected: " << INVALID_VALUE
                        << "\nGot: " << techValues.nHorizontalBanks);

    BOOST_CHECK_MESSAGE( techValues.cellsPerLWL
                         == 524,
                         "Cells per local wordline"
                         " different from the expected."
                        << "\nExpected: " << 524
                        << "\nGot: " << techValues.cellsPerLWL);

    BOOST_CHECK_MESSAGE( techValues.cellsPerLWLRedundancy
                         == 12,
                         "Redundant cells per local wordline"
                         " different from the expected."
                        << "\nExpected: " << 12
                        << "\nGot: " << techValues.cellsPerLWLRedundancy);

    BOOST_CHECK_MESSAGE( techValues.cellsPerLBL
                         == 524,
                         "Cells per local bitline"
                         " different from the expected."
                        << "\nExpected: " << 524
                        << "\nGot: " << techValues.cellsPerLBL);

    BOOST_CHECK_MESSAGE( techValues.cellsPerLBLRedundancy
                         == 12,
                         "Redundant cells per local bitline"
                         " different from the expected."
                        << "\nExpected: " << 12
                        << "\nGot: " << techValues.cellsPerLBLRedundancy);

    BOOST_CHECK_MESSAGE( techValues.interface
                         == 16*drs::bit,
                         "Interface"
                         " different from the expected."
                        << "\nExpected: " << 16*drs::bit
                        << "\nGot: " << techValues.interface);

    BOOST_CHECK_MESSAGE( techValues.prefetch
                         == 8,
                         "Prefetch"
                         " different from the expected."
                        << "\nExpected: " << 8
                        << "\nGot: " << techValues.prefetch);

    BOOST_CHECK_MESSAGE( techValues.dramFreq
                         == 800*drs::megahertz_clock,
                         "DRAM frequency"
                         " different from the expected."
                        << "\nExpected: " << 800*drs::megahertz_clock
                        << "\nGot: " << techValues.dramFreq);

    BOOST_CHECK_MESSAGE( techValues.dramCoreFreq
                         == 0*drs::megahertz_clock,
                         "DRAM core frequency"
                         " different from the expected."
                        << "\nExpected: " << 0*drs::megahertz_clock
                        << "\nGot: " << techValues.dramCoreFreq);

    BOOST_CHECK_MESSAGE( techValues.nTilesPerBank
                         == 2,
                         "Tiles per bank"
                         " different from the expected."
                        << "\nExpected: " << 2
                        << "\nGot: " << techValues.nTilesPerBank);

    BOOST_CHECK_MESSAGE( techValues.pageStorage
                         == 2*drs::kibibyte,
                         "Page size"
                         " different from the expected."
                        << "\nExpected: " << 2*drs::kibibyte
                        << "\nGot: " << techValues.pageStorage);

    BOOST_CHECK_MESSAGE( techValues.pageSpanningFactor
                         == 0.5,
                         "Pages per tile"
                         " different from the expected."
                        << "\nExpected: " << 0.5
                        << "\nGot: " << techValues.pageSpanningFactor);

    BOOST_CHECK_MESSAGE( techValues.subArrayToPageFactor
                         == 1,
                         "Ratio of subarrays activated pro command"
                         " different from the expected."
                        << "\nExpected: " << 1
                        << "\nGot: " << techValues.subArrayToPageFactor);

    BOOST_CHECK_MESSAGE( techValues.BLArchitecture
                         == "OPEN",
                        "Bitline architecture"
                        " different from the expected."
                        << "\nExpected: " << "OPEN"
                        << "\nGot: " << techValues.BLArchitecture);

    BOOST_CHECK_MESSAGE( techValues.retentionTime
                         == 64*drs::millisecond,
                         "Retention time"
                         " different from the expected."
                        << "\nExpected: " << 64*drs::millisecond
                        << "\nGot: " << techValues.retentionTime);

    BOOST_CHECK_MESSAGE( techValues.trefIBase
                         == 7.8125*drs::microsecond,
                         "Retention time"
                         " different from the expected."
                        << "\nExpected: " << 7.8125*drs::microsecond
                        << "\nGot: " << techValues.trefIBase);

    BOOST_CHECK_MESSAGE( techValues.refreshMode
                         == 1,
                         "Refresh mode"
                         " different from the expected."
                        << "\nExpected: " << 1
                        << "\nGot: " << techValues.refreshMode);

    BOOST_CHECK_MESSAGE( techValues.temperature
                         == 27*bu::celsius::degrees,
                         "Required trefI"
                         " different from the expected."
                        << "\nExpected: " << 27*bu::celsius::degrees
                        << "\nGot: " << techValues.temperature);

}


BOOST_AUTO_TEST_CASE( checkInputTechnologyValues_dummy_input )
{
    int sim_argc = 5;
    char* sim_argv[] = {"./executable",
                        "-t",
                        "technology_input/tech_dummy_input.json",
                        "-p",
                        "architecture_input/arch_dummy_input.json"};

    ArgumentsParser inputFileName(sim_argc, sim_argv);

    string exceptionMsg("Empty");
    try {
        inputFileName.runArgParser();
    }catch (string exceptionMsgThrown){
        exceptionMsg = exceptionMsgThrown;
    }
    string expectedMsg("Empty");
    if ( exceptionMsg != expectedMsg ) {
        BOOST_FAIL( exceptionMsg );
    }

    TechnologyValues techValues;
    try {
        techValues = TechnologyValues(inputFileName.technologyFileName[0],
                         inputFileName.architectureFileName[0]);
    }catch (string exceptionMsgThrown){
        exceptionMsg = exceptionMsgThrown;
    }
    expectedMsg = string("Empty");
    if ( exceptionMsg != expectedMsg ) {
        BOOST_FAIL( exceptionMsg );
    }


    BOOST_CHECK_MESSAGE( techValues.technologyNode
                         == 3946*drs::nanometer,
                        "Technology node"
                        " different from the expected."
                        << "\nExpected: " << 3946*drs::nanometer
                        << "\nGot: " << techValues.technologyNode);

    BOOST_CHECK_MESSAGE( techValues.vpp
                         == 1189*si::volt,
                         "VPP"
                         " different from the expected."
                        << "\nExpected: " << 1189*si::volt
                        << "\nGot: " << techValues.vpp);

    BOOST_CHECK_MESSAGE( techValues.vdd
                         == 3374*si::volt,
                         "VDD"
                         " different from the expected."
                        << "\nExpected: " << 3374*si::volt
                        << "\nGot: " << techValues.vdd);

    BOOST_CHECK_MESSAGE( techValues.wireResistance
                         == 8638*drs::ohm_per_millimeter,
                         "Wire resistance"
                         " different from the expected."
                        << "\nExpected: " << 8638*drs::ohm_per_millimeter
                        << "\nGot: " << techValues.wireResistance);

    BOOST_CHECK_MESSAGE( techValues.wireCapacitance
                         == 2179*drs::femtofarads_per_millimeter,
                         "Wire capacitance"
                         " different from the expected."
                        << "\nExpected: "
                         << 2179*drs::femtofarads_per_millimeter
                        << "\nGot: " << techValues.wireCapacitance);

    BOOST_CHECK_MESSAGE( techValues.capacitancePerCell
                         == 3944*drs::femtofarads,
                        "Capacitance per cell"
                        " different from the expected."
                        << "\nExpected: " << 3944*drs::femtofarads
                        << "\nGot: " << techValues.capacitancePerCell);

    BOOST_CHECK_MESSAGE( techValues.resistancePerCell
                         == 2287*drs::kiloohm,
                        "Resistance per cell"
                        " different from the expected."
                        << "\nExpected: " << 2287*drs::kiloohm
                        << "\nGot: " << techValues.resistancePerCell);

    BOOST_CHECK_MESSAGE( techValues.cellWidth
                         == 1070*drs::micrometer,
                         "Cell width"
                         " different from the expected."
                        << "\nExpected: " << 1070*drs::micrometer
                        << "\nGot: " << techValues.cellWidth);

    BOOST_CHECK_MESSAGE( techValues.cellHeight
                         == 885*drs::micrometer,
                         "Cell height"
                         " different from the expected."
                        << "\nExpected: " << 885*drs::micrometer
                        << "\nGot: " << techValues.cellHeight);

    BOOST_CHECK_MESSAGE( techValues.capacitancePerBLCell
                         == 8281*drs::attofarads,
                        "Capacitance per bitline cell"
                        " different from the expected."
                        << "\nExpected: " << 8281*drs::attofarads
                        << "\nGot: " << techValues.capacitancePerBLCell);

    BOOST_CHECK_MESSAGE( techValues.resistancePerBLCell
                         == 7024*drs::ohm,
                        "Resistance per bitline cell"
                        " different from the expected."
                        << "\nExpected: " << 7024*drs::ohm
                        << "\nGot: " << techValues.resistancePerBLCell);

    BOOST_CHECK_MESSAGE( techValues.capacitancePerWLCell
                         == 6381*drs::attofarads,
                        "Capacitance per wordline cell"
                        " different from the expected."
                        << "\nExpected: " << 6381*drs::attofarads
                        << "\nGot: " << techValues.capacitancePerWLCell);

    BOOST_CHECK_MESSAGE( techValues.resistancePerWLCell
                         == 8543*drs::ohm,
                        "Resistance per wordline cell"
                        " different from the expected."
                        << "\nExpected: " << 8543*drs::ohm
                        << "\nGot: " << techValues.resistancePerWLCell);

    BOOST_CHECK_MESSAGE( techValues.BLSenseAmpHeight
                         == 4104*drs::micrometer,
                         "Bitline sense amp. height"
                         " different from the expected."
                        << "\nExpected: " << 4104*drs::micrometer
                        << "\nGot: " << techValues.BLSenseAmpHeight);

    BOOST_CHECK_MESSAGE( techValues.LWLDriverWidth
                         == 8791*drs::micrometer,
                         "Wordline driver width"
                         " different from the expected."
                        << "\nExpected: " << 8791*drs::micrometer
                        << "\nGot: " << techValues.LWLDriverWidth);

    BOOST_CHECK_MESSAGE( techValues.LWLDriverResistance
                         == 5222*drs::ohm,
                         "Local wordline driver resistance"
                         " different from the expected."
                        << "\nExpected: " << 5222*drs::ohm
                        << "\nGot: " << techValues.LWLDriverResistance);

    BOOST_CHECK_MESSAGE( techValues.rowDecoderWidth
                         == 5812*drs::micrometer,
                         "Row decoder (between tiles) width"
                         " different from the expected."
                        << "\nExpected: " << 5812*drs::micrometer
                        << "\nGot: " << techValues.rowDecoderWidth);

    BOOST_CHECK_MESSAGE( techValues.GWLDriverResistance
                         == 4405*drs::ohm,
                         "Global wordline driver resistance"
                         " different from the expected."
                        << "\nExpected: " << 4405*drs::ohm
                        << "\nGot: " << techValues.GWLDriverResistance);

    BOOST_CHECK_MESSAGE( techValues.Issa
                         == 1877*drs::microampere_per_bit,
                         "SSA current"
                         " different from the expected."
                        << "\nExpected: " << 1877*drs::microampere_per_bit
                        << "\nGot: " << techValues.Issa);

    BOOST_CHECK_MESSAGE( techValues.WRDriverResistance
                         == 5931*drs::ohm,
                         "WRrestore driver resistance"
                         " different from the expected."
                        << "\nExpected: " << 5931*drs::ohm
                        << "\nGot: " << techValues.WRDriverResistance);

    BOOST_CHECK_MESSAGE( techValues.colDecoderHeight
                         == 7970*drs::micrometer,
                         "Column decoder (between tiles) width"
                         " different from the expected."
                        << "\nExpected: " << 7970*drs::micrometer
                        << "\nGot: " << techValues.colDecoderHeight);

    BOOST_CHECK_MESSAGE( techValues.CSLDriverResistance
                         == 9601*drs::ohm,
                         "CSL driver resistance"
                         " different from the expected."
                        << "\nExpected: " << 9601*drs::ohm
                        << "\nGot: " << techValues.CSLDriverResistance);

    BOOST_CHECK_MESSAGE( techValues.CSLLoadCapacitance
                         == 2056*drs::femtofarads,
                        "Load capacitance of CSL"
                        " different from the expected."
                        << "\nExpected around: " << 2056*drs::femtofarads
                        << "\nGot: " << techValues.CSLLoadCapacitance);

    BOOST_CHECK_MESSAGE( techValues.GDLDriverResistance
                         == 5885*drs::ohm,
                         "GDL driver resistance"
                         " different from the expected."
                        << "\nExpected: " << 5885*drs::ohm
                        << "\nGot: " << techValues.GDLDriverResistance);

    BOOST_CHECK_MESSAGE( techValues.DQDriverHeight
                         == 5457*drs::micrometer,
                         "DQ driver (between banks) height"
                         " different from the expected."
                        << "\nExpected: " << 5457*drs::micrometer
                        << "\nGot: " << techValues.DQDriverHeight);

    BOOST_CHECK_MESSAGE( techValues.DQDriverResistance
                         == 9240*drs::ohm,
                         "DQ driver resistance"
                         " different from the expected."
                        << "\nExpected: " << 9240*drs::ohm
                        << "\nGot: " << techValues.DQDriverResistance);

    BOOST_CHECK_MESSAGE( techValues.idd2nFreqSlope
                         == 483*drs::milliamperes_per_megahertz_clock,
                         "Background current slope"
                         " different from the expected."
                        << "\nExpected: "
                         << 483*drs::milliamperes_per_megahertz_clock
                        << "\nGot: " << techValues.idd2nFreqSlope);

    BOOST_CHECK_MESSAGE( techValues.idd2nTempAlpha
                         == 1833*drs::milliamperes,
                         "Background current alpha coefficient"
                         " different from the expected."
                        << "\nExpected: " << 1833*drs::milliamperes
                        << "\nGot: " << techValues.idd2nTempAlpha);

    BOOST_CHECK_MESSAGE( techValues.idd2nTempBeta
                         == 5108*drs::eergeds,
                         "Background current beta coefficient"
                         " different from the expected."
                        << "\nExpected: " << 5108*drs::eergeds
                        << "\nGot: " << techValues.idd2nTempBeta);

    BOOST_CHECK_MESSAGE( techValues.idd2nRefTemp
                         == 3901*bu::celsius::degrees,
                         "Background current reference temperature"
                         " different from the expected."
                        << "\nExpected: " << 3901*bu::celsius::degrees
                        << "\nGot: " << techValues.idd2nRefTemp);

    BOOST_CHECK_MESSAGE( techValues.idd2nOffset
                         == 8513*drs::milliampere,
                         "Background current offset"
                         " different from the expected."
                        << "\nExpected: " << 8513*drs::milliampere
                        << "\nGot: " << techValues.idd2nOffset);

    BOOST_CHECK_MESSAGE( techValues.IddOcdRcvSlope
                         == 4560*drs::microamperes_per_megahertz_clock,
                         "Current slope per IO pin"
                         " different from the expected."
                        << "\nExpected: "
                         << 4560*drs::microamperes_per_megahertz_clock
                        << "\nGot: " << techValues.IddOcdRcvSlope);

    BOOST_CHECK_MESSAGE( techValues.fullySharedResourcesCurrent
                         == 1621*drs::milliamperes,
                         "Current of fully shared resources"
                         " different from the expected."
                        << "\nExpected: "
                         << 1621*drs::milliamperes
                        << "\nGot: " << techValues.fullySharedResourcesCurrent);

    BOOST_CHECK_MESSAGE( techValues.semiSharedResourcesCurrent
                         == 2780*drs::milliamperes,
                         "Current of semi shared resources"
                         " different from the expected."
                        << "\nExpected: "
                         << 2780*drs::milliamperes
                        << "\nGot: " << techValues.semiSharedResourcesCurrent);

    BOOST_CHECK_MESSAGE( techValues.nBanksPerSemiSharedResource
                         == 7115,
                         "Number of banks per semi shared resources"
                         " different from the expected."
                        << "\nExpected: "
                         << 7115
                        << "\nGot: " << techValues.nBanksPerSemiSharedResource);

    BOOST_CHECK_MESSAGE( techValues.TSVHeight
                         == 9483*drs::micrometer,
                         "Height of the TSV area needed for each bank I/O"
                         " different from the expected."
                        << "\nExpected: " << 9483*drs::micrometer
                        << "\nGot: " << techValues.TSVHeight);

    BOOST_CHECK_MESSAGE( techValues.additionalLatencyTrl
                         == 9541*drs::clock,
                         "Additional latency to trl"
                         " different from the expected."
                        << "\nExpected: " << 9541*drs::clock
                        << "\nGot: " << techValues.additionalLatencyTrl);

    BOOST_CHECK_MESSAGE( techValues.driverEnableDelay
                         == 5654*drs::nanoseconds,
                        "Driver enabling time"
                        " different from the expected."
                        << "\nExpected around: " << 5654*drs::nanoseconds
                        << "\nGot: " << techValues.driverEnableDelay);

    BOOST_CHECK_MESSAGE( techValues.inOutSSADelay
                         == 8*drs::nanoseconds,
                        "Secondary sense amplifier delay"
                        " different from the expected."
                        << "\nExpected around: " << 8*drs::nanoseconds
                        << "\nGot: " << techValues.inOutSSADelay);

    BOOST_CHECK_MESSAGE( techValues.cmdDecoderDelay
                         == 9212*drs::nanoseconds,
                        "Command decoder delay"
                        " different from the expected."
                        << "\nExpected around: " << 9212*drs::nanoseconds
                        << "\nGot: " << techValues.cmdDecoderDelay);

    BOOST_CHECK_MESSAGE( techValues.IODelay
                         == 9769*drs::nanoseconds,
                        "IO interface Delay"
                        " different from the expected."
                        << "\nExpected around: " << 9769*drs::nanoseconds
                        << "\nGot: " << techValues.IODelay);

    BOOST_CHECK_MESSAGE( techValues.SSAPrechargeDelay
                         == 1540*drs::nanoseconds,
                        "Delay of SSA precharge"
                        " different from the expected."
                        << "\nExpected around: " << 1540*drs::nanoseconds
                        << "\nGot: " << techValues.SSAPrechargeDelay);

    BOOST_CHECK_MESSAGE( techValues.tWRMargin
                         == 2126*drs::nanoseconds,
                        "Security margin for write recovery"
                        " different from the expected."
                        << "\nExpected around: " << 2126*drs::nanoseconds
                        << "\nGot: " << techValues.tWRMargin);

    BOOST_CHECK_MESSAGE( techValues.equalizerDelay
                         == 1103*drs::nanoseconds,
                        "Equalizer circuit enabling delay"
                        " different from the expected."
                        << "\nExpected around: " << 1103*drs::nanoseconds
                        << "\nGot: " << techValues.equalizerDelay);

    BOOST_CHECK_MESSAGE( techValues.vppPumpsEfficiency == 0.3,
                        "Efficiency of VPP pumps different from the expected."
                        << "\nExpected around: " << 0.3
                        << "\nGot: " << techValues.vppPumpsEfficiency);




    BOOST_CHECK_MESSAGE( techValues.dramType
                         == "DDR",
                         "DRAM type"
                         " different from the expected."
                        << "\nExpected: " << "DDR"
                        << "\nGot: " << techValues.dramType);

    BOOST_CHECK_MESSAGE( techValues.is3D
                         == false,
                         "3D flag"
                         " different from the expected."
                        << "\nExpected: " << false
                        << "\nGot: " << techValues.is3D);

    BOOST_CHECK_MESSAGE( techValues.isDLL
                         == false,
                         "DLL flag"
                         " different from the expected."
                        << "\nExpected: " << false
                        << "\nGot: " << techValues.isDLL);

    BOOST_CHECK_MESSAGE( techValues.hasExternalVpp
                         == false,
                         "External Vpp flag"
                         " different from the expected."
                        << "\nExpected: " << false
                        << "\nGot: " << techValues.isDLL);

    BOOST_CHECK_MESSAGE( techValues.channelSize
                         == 2028*drs::gibibit,
                         "DRAM Size"
                         " different from the expected."
                        << "\nExpected: " << 2028*drs::gibibit
                        << "\nGot: " << techValues.channelSize);

    BOOST_CHECK_MESSAGE( techValues.nBanks
                         == 3264,
                         "Number of banks"
                         " different from the expected."
                        << "\nExpected: " << 3264
                        << "\nGot: " << techValues.nBanks);

    BOOST_CHECK_MESSAGE( techValues.nHorizontalBanks
                         == 8054,
                         "Number of banks in the row direction"
                         " different from the expected."
                        << "\nExpected: " << 8054
                        << "\nGot: " << techValues.nHorizontalBanks);

    BOOST_CHECK_MESSAGE( techValues.nVerticalBanks
                         == 2098,
                         "Number of banks in the column direction"
                         " different from the expected."
                        << "\nExpected: " << 2098
                        << "\nGot: " << techValues.nVerticalBanks);

    BOOST_CHECK_MESSAGE( techValues.cellsPerLWL
                         == 5507,
                         "Cells per local wordline"
                         " different from the expected."
                        << "\nExpected: " << 5507
                        << "\nGot: " << techValues.cellsPerLWL);

    BOOST_CHECK_MESSAGE( techValues.cellsPerLWLRedundancy
                         == 7765,
                         "Redundant cells per local wordline"
                         " different from the expected."
                        << "\nExpected: " << 7765
                        << "\nGot: " << techValues.cellsPerLWLRedundancy);

    BOOST_CHECK_MESSAGE( techValues.cellsPerLBL
                         == 2941,
                         "Cells per local bitline"
                         " different from the expected."
                        << "\nExpected: " << 2941
                        << "\nGot: " << techValues.cellsPerLBL);

    BOOST_CHECK_MESSAGE( techValues.cellsPerLBLRedundancy
                         == 7914,
                         "Redundant cells per local bitline"
                         " different from the expected."
                        << "\nExpected: " << 7914
                        << "\nGot: " << techValues.cellsPerLBLRedundancy);

    BOOST_CHECK_MESSAGE( techValues.interface
                         == 3554*drs::bit,
                         "Interface"
                         " different from the expected."
                        << "\nExpected: " << 3554*drs::bit
                        << "\nGot: " << techValues.interface);

    BOOST_CHECK_MESSAGE( techValues.prefetch
                         == 8578,
                         "Prefetch"
                         " different from the expected."
                        << "\nExpected: " << 8578
                        << "\nGot: " << techValues.prefetch);

    BOOST_CHECK_MESSAGE( techValues.dramFreq
                         == 9664*drs::megahertz_clock,
                         "DRAM frequency"
                         " different from the expected."
                        << "\nExpected: " << 9664*drs::megahertz_clock
                        << "\nGot: " << techValues.dramFreq);

    BOOST_CHECK_MESSAGE( techValues.dramCoreFreq
                         == 7546*drs::megahertz_clock,
                         "DRAM core frequency"
                         " different from the expected."
                        << "\nExpected: " << 7546*drs::megahertz_clock
                        << "\nGot: " << techValues.dramCoreFreq);

    BOOST_CHECK_MESSAGE( techValues.nTilesPerBank
                         == 8259,
                         "Tiles per bank"
                         " different from the expected."
                        << "\nExpected: " << 8259
                        << "\nGot: " << techValues.nTilesPerBank);

    BOOST_CHECK_MESSAGE( techValues.pageStorage
                         == 463*drs::kibibyte,
                         "Page size"
                         " different from the expected."
                        << "\nExpected: " << 463*drs::kibibyte
                        << "\nGot: " << techValues.pageStorage);

    BOOST_CHECK_MESSAGE( techValues.pageSpanningFactor
                         == 6401,
                         "Pages per tile"
                         " different from the expected."
                        << "\nExpected: " << 6401
                        << "\nGot: " << techValues.pageSpanningFactor);

    BOOST_CHECK_MESSAGE( techValues.subArrayToPageFactor
                         == 4456,
                         "Ratio of subarrays activated pro command"
                         " different from the expected."
                        << "\nExpected: " << 4456
                        << "\nGot: " << techValues.subArrayToPageFactor);

    BOOST_CHECK_MESSAGE( techValues.BLArchitecture
                         == "2957",
                        "Bitline architecture"
                        " different from the expected."
                        << "\nExpected: " << "2957"
                        << "\nGot: " << techValues.BLArchitecture);

    BOOST_CHECK_MESSAGE( techValues.retentionTime
                         == 2242*drs::millisecond,
                         "Retention time"
                         " different from the expected."
                        << "\nExpected: " << 2242*drs::millisecond
                        << "\nGot: " << techValues.retentionTime);

    BOOST_CHECK_MESSAGE( techValues.temperature
                         == 963*bu::celsius::degrees,
                         "Required trefI"
                         " different from the expected."
                        << "\nExpected: " << 963*bu::celsius::degrees
                        << "\nGot: " << techValues.temperature);

    BOOST_CHECK_MESSAGE( techValues.refreshMode
                         == 9263,
                         "Refresh mode factor"
                         " different from the expected."
                        << "\nExpected: " << 9263
                        << "\nGot: " << techValues.refreshMode);


}


BOOST_AUTO_TEST_CASE( checkInputTechnologyValues_no_tech_file )
{
    int sim_argc = 5;
    char* sim_argv[] = {"./executable",
                        "-t",
                        "technology_input/not_a_file.json",
                        "-p",
                        "architecture_input/test_architecture.json"};

    ArgumentsParser inputFileName(sim_argc, sim_argv);
    string exceptionMsg("Empty");
    try {
        inputFileName.runArgParser();
    }catch (string exceptionMsgThrown){
        exceptionMsg = exceptionMsgThrown;
    }
    string expectedMsg("Empty");
    BOOST_CHECK_MESSAGE( exceptionMsg == expectedMsg,
                        "Error message different from what was expected."
                        << "\nExpected: " << expectedMsg
                        << "\nGot: " << exceptionMsg);

    TechnologyValues techValues;
    try {
        techValues = TechnologyValues(inputFileName.technologyFileName[0],
                         inputFileName.architectureFileName[0]);
    }catch (string exceptionMsgThrown){
        exceptionMsg = exceptionMsgThrown;
    }
    expectedMsg = string("[ERROR] ");
    expectedMsg.append("Could not open technology file: ");
    expectedMsg.append(inputFileName.technologyFileName[0]);
    expectedMsg.append("!\n");
    BOOST_CHECK_MESSAGE( exceptionMsg == expectedMsg,
                        "Error message different from what was expected."
                        << "\nExpected: " << expectedMsg
                        << "\nGot: " << exceptionMsg);
}

BOOST_AUTO_TEST_CASE( checkInputTechnologyValues_no_arch_file )
{
    int sim_argc = 5;
    char* sim_argv[] = {"./executable",
                        "-t",
                        "technology_input/test_technology.json",
                        "-p",
                        "architecture_input/not_a_file.json"};

    ArgumentsParser inputFileName(sim_argc, sim_argv);
    string exceptionMsg("Empty");
    try {
        inputFileName.runArgParser();
    }catch (string exceptionMsgThrown){
        exceptionMsg = exceptionMsgThrown;
    }
    string expectedMsg("Empty");
    BOOST_CHECK_MESSAGE( exceptionMsg == expectedMsg,
                        "Error message different from what was expected."
                        << "\nExpected: " << expectedMsg
                        << "\nGot: " << exceptionMsg);

    TechnologyValues techValues;
    try {
        techValues = TechnologyValues(inputFileName.technologyFileName[0],
                                      inputFileName.architectureFileName[0]);
    }catch (string exceptionMsgThrown){
        exceptionMsg = exceptionMsgThrown;
    }
    expectedMsg = string("[ERROR] ");
    expectedMsg.append("Could not open architecture file: ");
    expectedMsg.append(inputFileName.architectureFileName[0]);
    expectedMsg.append("!\n");
    BOOST_CHECK_MESSAGE( exceptionMsg == expectedMsg,
                        "Error message different from what was expected."
                        << "\nExpected: " << expectedMsg
                        << "\nGot: " << exceptionMsg);

}

BOOST_AUTO_TEST_CASE( checkInputTechnologyValues_bad_tech_file )
{
    int sim_argc = 5;
    char* sim_argv[] = {"./executable",
                        "-t",
                        "main.cpp",
                        "-p",
                        "architecture_input/test_architecture.json"};

    ArgumentsParser inputFileName(sim_argc, sim_argv);
    string exceptionMsg("Empty");
    try {
        inputFileName.runArgParser();
    }catch (string exceptionMsgThrown){
        exceptionMsg = exceptionMsgThrown;
    }
    string expectedMsg("Empty");
    BOOST_CHECK_MESSAGE( exceptionMsg == expectedMsg,
                        "Error message different from what was expected."
                        << "\nExpected: " << expectedMsg
                        << "\nGot: " << exceptionMsg);

    TechnologyValues techValues;
    try {
        techValues = TechnologyValues(inputFileName.technologyFileName[0],
                                      inputFileName.architectureFileName[0]);
    }catch (string exceptionMsgThrown){
        exceptionMsg = exceptionMsgThrown;
    }
    expectedMsg = string("[ERROR] ");
    expectedMsg.append("Could not parse ");
    expectedMsg.append(inputFileName.technologyFileName[0]);
    expectedMsg.append(" as a JSON document.\n");
    BOOST_CHECK_MESSAGE( exceptionMsg == expectedMsg,
                        "Error message different from what was expected."
                        << "\nExpected: " << expectedMsg
                        << "\nGot: " << exceptionMsg);

}

BOOST_AUTO_TEST_CASE( checkInputTechnologyValues_bad_arch_file )
{
    int sim_argc = 5;
    char* sim_argv[] = {"./executable",
                        "-t",
                        "technology_input/test_technology.json",
                        "-p",
                        "main.cpp"};

    ArgumentsParser inputFileName(sim_argc, sim_argv);
    string exceptionMsg("Empty");
    try {
        inputFileName.runArgParser();
    }catch (string exceptionMsgThrown){
        exceptionMsg = exceptionMsgThrown;
    }
    string expectedMsg("Empty");
    BOOST_CHECK_MESSAGE( exceptionMsg == expectedMsg,
                        "Error message different from what was expected."
                        << "\nExpected: " << expectedMsg
                        << "\nGot: " << exceptionMsg);

    TechnologyValues techValues;
    try {
        techValues = TechnologyValues(inputFileName.technologyFileName[0],
                                      inputFileName.architectureFileName[0]);
    }catch (string exceptionMsgThrown){
        exceptionMsg = exceptionMsgThrown;
    }
    expectedMsg = string("[ERROR] ");
    expectedMsg.append("Could not parse ");
    expectedMsg.append(inputFileName.architectureFileName[0]);
    expectedMsg.append(" as a JSON document.\n");
    BOOST_CHECK_MESSAGE( exceptionMsg == expectedMsg,
                        "Error message different from what was expected."
                        << "\nExpected: " << expectedMsg
                        << "\nGot: " << exceptionMsg);
}

BOOST_AUTO_TEST_SUITE_END()

#endif


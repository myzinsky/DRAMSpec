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
 * Authors: Omar Naji,
 *          Matthias Jung,
 *          Christian Weis,
 *          Kamal Haddad,
 *          Andr'e Lucas Chinazzo
 */

#ifndef BANK_H
#define BANK_H

//This class repesents the fourth level of abstraction of the DRAM structure,
//being the bank a grouping of tile.

#include "Tile.h"

namespace bu=boost::units;
namespace si=boost::units::si;
namespace inf=boost::units::information;
namespace drs=boost::units::dramspec;

class Bank : public Tile
{
  public:
    Bank() : //Empty constructor for test proposes
        Tile()
    {
        bankInitialize();
    }

    Bank(const std::string& techname,const std::string& paraname):
        Tile(techname,paraname)
    {
        bankInitialize();
        bankCompute();
    }

    // Size in number of bits of a single bank
    bu::quantity<drs::information_per_bank_unit> bankStorage;

    // Width in micrometer of a single bank
    bu::quantity<drs::micrometer_per_bank_unit> bankWidth;
    // Height in micrometer of a single bank
    bu::quantity<drs::micrometer_per_bank_unit> bankHeight;

    void bankInitialize();

    void bankCompute();
    void bankStorageCalc();
    void bankLenghtCalc();

};

#endif // BANK_H

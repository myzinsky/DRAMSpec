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

#ifndef TILE_H
#define TILE_H

//This class repesents the third level of abstraction of the DRAM structure,
//being the tile a grouping of subarrays which are a grouping of cells.

#include "SubArray.h"

class Tile : public SubArray
{
  public:
    Tile(const std::string& techname,const std::string& paraname):
        SubArray(techname,paraname),
        tileStorage(0*drs::bit_per_tile),
        tileWidth(0*drs::micrometer_per_tile),
        tileHeight(0*drs::micrometer_per_tile),

        nSubArraysPerArrayBlock(0*drs::subarray_per_tile),
        nArrayBlocksPerTile(0*drs::subarray_per_tile)
    {
        //order of functions is important
        bool TINIT = false;
        TINIT = tileInit();
        if(TINIT == false)
        {
                std::cout<<"ERROR: Function for Tile Initialization not called"<<
                "\t"<<"Order of Functions is important"<<"\n";
                throw(" Function for Tile Initialization not called");
        }
    }
  public:
    // Size in number of bits of a single tile
    bu::quantity<drs::information_per_tile_unit> tileStorage;

    // Width in micrometer of a single tile
    bu::quantity<drs::micrometer_per_tile_unit> tileWidth;
    // Height in micrometer of a single tile
    bu::quantity<drs::micrometer_per_tile_unit> tileHeight;

    // Number of subarrays per tile in the wordline direction
    bu::quantity<drs::subarray_per_tile_unit> nSubArraysPerArrayBlock;
    // Number of subarrays per tile in the bitline direction
    bu::quantity<drs::subarray_per_tile_unit> nArrayBlocksPerTile;

    bool tileStorageCalc();

    void checkTileDataConsistency();
    bool tileLenghtCalc();

    bool tileAreaCalc();

    bool tileInit();

};

#endif // TILE_H
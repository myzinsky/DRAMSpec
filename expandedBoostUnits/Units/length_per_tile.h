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
 * Authors: Omar Naji, Matthias Jung, Christian Weis, Kamal Haddad, Andr'e Lucas Chinazzo
 */

#ifndef DRAMSPEC_LENGTH_PER_TILE_UNIT_H
#define DRAMSPEC_LENGTH_PER_TILE_UNIT_H

#include <boost/units/make_scaled_unit.hpp>

#include "../dramSpecUnitsSystem.h"
#include "../DerivedDimensions/length_per_tile.h"

namespace boost {

namespace units {

namespace dramspec {

typedef unit<length_per_tile_dimension,dramspec::system_bit> length_per_tile_unit;

typedef make_scaled_unit<length_per_tile_unit,scale<10, static_rational<-3>>>::type millimeter_per_tile_unit;
BOOST_UNITS_STATIC_CONSTANT(millimeter_per_tile,millimeter_per_tile_unit);
BOOST_UNITS_STATIC_CONSTANT(millimeters_per_tile,millimeter_per_tile_unit);
typedef make_scaled_unit<length_per_tile_unit,scale<10, static_rational<-6>>>::type micrometer_per_tile_unit;
BOOST_UNITS_STATIC_CONSTANT(micrometer_per_tile,micrometer_per_tile_unit);
BOOST_UNITS_STATIC_CONSTANT(micrometers_per_tile,micrometer_per_tile_unit);

} // namespace dramspec

inline std::string name_string(const reduce_unit<dramspec::length_per_tile_unit>::type&)   { return "meter/tile"; }
inline std::string symbol_string(const reduce_unit<dramspec::length_per_tile_unit>::type&) { return "meter/tile"; }

} // namespace units

} // namespace boost

#endif // DRAMSPEC_LENGTH_PER_TILE_UNIT_H

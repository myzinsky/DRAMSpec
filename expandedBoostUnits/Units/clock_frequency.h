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

#ifndef DRAMSPEC_CLOCK_FREQUENCY_UNIT_H
#define DRAMSPEC_CLOCK_FREQUENCY_UNIT_H

#include "../dramSpecUnitsSystem.h"
#include "../DerivedDimensions/clock_frequency.h"

#include <boost/units/systems/si.hpp>
#include <boost/units/systems/si/io.hpp>
#include <boost/units/systems/si/prefixes.hpp>

namespace boost {

namespace units {

namespace dramspec {

typedef unit<clock_frequency_dimension,dramspec::system>    clock_frequency_unit;

BOOST_UNITS_STATIC_CONSTANT(clock_per_second,clock_frequency_unit);
BOOST_UNITS_STATIC_CONSTANT(clocks_per_second,clock_frequency_unit);
BOOST_UNITS_STATIC_CONSTANT(clock_hertz,clock_frequency_unit);

typedef make_scaled_unit<clock_frequency_unit,scale<10, static_rational<6>>>::type megahertz_clock_unit;
BOOST_UNITS_STATIC_CONSTANT(megahertz_clock,megahertz_clock_unit);
typedef make_scaled_unit<clock_frequency_unit,scale<10, static_rational<9>>>::type gigahertz_clock_unit;
BOOST_UNITS_STATIC_CONSTANT(gigahertz_clock,gigahertz_clock_unit);

} // namespace dramspec

inline std::string name_string(const reduce_unit<dramspec::clock_frequency_unit>::type&)   { return "clock/second"; }
inline std::string symbol_string(const reduce_unit<dramspec::clock_frequency_unit>::type&) { return "clock/s"; }

} // namespace units

} // namespace boost

#endif // DRAMSPEC_CLOCK_FREQUENCY_UNIT_H
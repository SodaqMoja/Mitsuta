/*
 * Copyright (c) 2013 Kees Bakker.  All rights reserved.
 *
 * This file is part of Mitsuta.
 *
 * Mitsuta is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published bythe Free Software Foundation, either version 3 of
 * the License, or(at your option) any later version.
 *
 * Mitsuta is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with Mitsuta.  If not, see
 * <http://www.gnu.org/licenses/>.
 */


#include "Mitsuta.h"

/*
 * \brief Reset and initialize with the first value
 */
void Mitsuta::first(int16_t val)
{
  _d = val;
  _sum = _d;
  _n = 1;
}

/*
 * \brief Add the next value using the Mitsuta algorithm
 */
void Mitsuta::next(int16_t val)
{
  if (_n == 0) {
    first(val);
    return;
  }
  int16_t delta = val - _d;
  if (delta < -180) {
    _d += delta + 360;
  } else if (delta < 180) {
    _d += delta;
  } else {
    _d += delta - 360;
  }
#if MITSUTA_DEBUG
  _delta = delta;
#endif
  _sum += _d;
  ++_n;
}

int16_t Mitsuta::mean() const
{
  if (_n == 0) {
    // Nothing was stored. What can we do?
    return 999;
  }
  int16_t value = _sum / _n;
  return (value + 360) % 360;
}

/*
 *  \brief Sum up the squares of the "d" values for calculation of standard deviation
 */
void Mitsuta::addSumsq()
{
  _sumsq += (int32_t) _d * (int32_t) _d;
}

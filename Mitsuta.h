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

#ifndef MITSUTA_H_
#define MITSUTA_H_

#include <stdint.h>

class Mitsuta
{
public:
  // By not declaring we get the default initializer,
  // probably just memset.
  //Mitsuta() { n = 0; }
  void reset()                          { _n = 0; _sumsq = 0; }
  void first(int16_t val);
  void next(int16_t val);
  void addSumsq();
  int16_t mean() const;
  uint16_t n() const                    { return _n; }
  int32_t sumsq() const                 { return _sumsq; }
private:
  int16_t       _d;
  int32_t       _sum;
  uint16_t      _n;
  int32_t       _sumsq;
#if MITSUTA_DEBUG
  int16_t       _delta;
#endif
};

#endif /* MITSUTA_H_ */

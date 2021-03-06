// Copyright 2021 PDFium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef TESTING_SCOPED_SET_TZ_H_
#define TESTING_SCOPED_SET_TZ_H_

#include <string>

#include "third_party/base/optional.h"

class ScopedSetTZ {
 public:
  explicit ScopedSetTZ(const std::string& tz);
  ScopedSetTZ(const ScopedSetTZ&) = delete;
  ScopedSetTZ& operator=(const ScopedSetTZ&) = delete;
  ~ScopedSetTZ();

 private:
  Optional<std::string> old_tz_;
};

#endif  // TESTING_SCOPED_SET_TZ_H_

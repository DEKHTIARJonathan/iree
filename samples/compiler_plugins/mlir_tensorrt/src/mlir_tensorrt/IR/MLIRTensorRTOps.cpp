// Copyright 2023 The IREE Authors
//
// Licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#include "mlir_tensorrt/IR/MLIRTensorRTOps.h"

#include "mlir/IR/OpImplementation.h"

// clang-format off
#define GET_OP_CLASSES
#include "mlir_tensorrt/IR/MLIRTensorRTOps.cpp.inc" // IWYU pragma: keep
// clang-format on

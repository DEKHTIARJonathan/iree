// Copyright 2023 The IREE Authors
//
// Licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef IREE_SAMPLES_COMPILER_PLUGINS_MLIR_TENSORRT_IR_MLIRTENSORRTOPS_H_
#define IREE_SAMPLES_COMPILER_PLUGINS_MLIR_TENSORRT_IR_MLIRTENSORRTOPS_H_

#include "mlir/IR/Builders.h"
#include "mlir/IR/Operation.h"

// Include generated.
#define GET_OP_CLASSES
#include "mlir_tensorrt/IR/MLIRTensorRTOps.h.inc"  // IWYU pragma: keep

#endif  // IREE_SAMPLES_COMPILER_PLUGINS_MLIR_TENSORRT_IR_MLIRTENSORRTOPS_H_

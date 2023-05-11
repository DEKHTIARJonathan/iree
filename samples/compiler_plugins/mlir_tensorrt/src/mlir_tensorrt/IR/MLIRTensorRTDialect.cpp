// Copyright 2023 The IREE Authors
//
// Licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#include "mlir_tensorrt/IR/MLIRTensorRTDialect.h"
#include "mlir_tensorrt/IR/MLIRTensorRTOps.h"

namespace mlir::iree_compiler::IREE::MLIRTensorRT {

void MLIRTensorRTDialect::initialize() {
  addOperations<
#define GET_OP_LIST
#include "mlir_tensorrt/IR/MLIRTensorRTOps.cpp.inc"
      >();
}

}  // namespace mlir::iree_compiler::IREE::MLIRTensorRT

#include "mlir_tensorrt/IR/MLIRTensorRTDialect.cpp.inc"

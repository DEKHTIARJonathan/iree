// Copyright 2023 The IREE Authors
//
// Licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

include "mlir/Pass/PassBase.td"

#ifndef IREE_MLIR_TENSSORT_PASSES
#define IREE_MLIR_TENSSORT_PASSES

def LegalizeMLIRTensorRT : Pass<"iree-mlir-tensorrt-legalize", "mlir::ModuleOp"> {
  let summary = "Legalizes the MLIR TensorRT ops";
  let constructor = [{
    ::mlir::iree_compiler::IREE::MLIRTensorRT::createLegalizeMLIRTensorRTPass()
  }];
}

#endif // IREE_MLIR_TENSSORT_PASSES

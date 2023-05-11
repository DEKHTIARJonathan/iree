// Copyright 2023 The IREE Authors
//
// Licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef MLIR_TENSORRT_SAMPLE
#define MLIR_TENSORRT_SAMPLE

include "mlir/IR/OpBase.td"

def MLIRTensorRT_Dialect : Dialect {
  let name = "mlir_tensorrt";
  let cppNamespace = "::mlir::iree_compiler::IREE::MLIRTensorRT";
}

class MLIRTensorRT_Op<string mnemonic, list<Trait> traits = []> :
    Op<MLIRTensorRT_Dialect, mnemonic, traits> {
}

def MLIRTensorRT_PrintOp : MLIRTensorRT_Op<"print", []> {
  let summary = [{Print}];
  let arguments = (ins);
  let results = (outs);

  let assemblyFormat = [{
    attr-dict
  }];
}

#endif  // MLIR_TENSORRT_SAMPLE

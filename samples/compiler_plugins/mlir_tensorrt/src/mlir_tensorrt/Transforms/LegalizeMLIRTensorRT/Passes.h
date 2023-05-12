// Copyright 2023 The IREE Authors
//
// Licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef IREE_SAMPLES_COMPILER_PLUGINS_MLIR_TENSORRT_TRANSFORMS_LEGALIZEMLIRTENSORRT_PASSES_H_
#define IREE_SAMPLES_COMPILER_PLUGINS_MLIR_TENSORRT_TRANSFORMS_LEGALIZEMLIRTENSORRT_PASSES_H_

#include "mlir/IR/BuiltinOps.h"
#include "mlir/Pass/Pass.h"
#include "mlir/Pass/PassManager.h"

namespace mlir::iree_compiler::IREE::MLIRTensorRT {
    std::unique_ptr<OperationPass<ModuleOp>> createLegalizeMLIRTensorRTPass();
}  // namespace mlir::iree_compiler::IREE::MLIRTensorRT

// namespace detail {
//     #define GEN_PASS_DECL
//     #define GEN_PASS_REGISTRATION
//     #include "mlir_tensorrt/Transforms/LegalizeMLIRTensorRT/Passes.h.inc"  
// }

namespace detail {
namespace {

#define GEN_PASS_DECL
#define GEN_PASS_REGISTRATION
#define GEN_PASS_DEF_LEGALIZEMLIRTENSORRT
#include "mlir_tensorrt/Transforms/LegalizeMLIRTensorRT/Passes.h.inc"

}  // namespace
}  // namespace detail

#endif  // IREE_SAMPLES_COMPILER_PLUGINS_MLIR_TENSORRT_TRANSFORMS_LEGALIZEMLIRTENSORRT_PASSES_H_

// Copyright 2023 The IREE Authors
//
// Licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef IREE_SAMPLES_COMPILER_PLUGINS_MLIR_TENSORRT_TRANSFORMS_PASSES_H_
#define IREE_SAMPLES_COMPILER_PLUGINS_MLIR_TENSORRT_TRANSFORMS_PASSES_H_

#include "mlir_tensorrt/Transforms/LegalizeMLIRTensorRT/Passes.h"

namespace detail {
namespace {

#define GEN_PASS_REGISTRATION
#include "mlir_tensorrt/Transforms/LegalizeMLIRTensorRT/Passes.h.inc"

}  // namespace
}  // namespace detail

#endif  // IREE_SAMPLES_COMPILER_PLUGINS_MLIR_TENSORRT_TRANSFORMS_PASSES_H_

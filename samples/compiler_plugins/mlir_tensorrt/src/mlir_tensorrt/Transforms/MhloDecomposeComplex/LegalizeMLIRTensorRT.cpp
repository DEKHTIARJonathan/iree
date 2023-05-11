// Copyright 2023 The IREE Authors
//
// Licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#include "mlir/Dialect/Func/IR/FuncOps.h"
#include "mlir/IR/Builders.h"
#include "mlir/IR/BuiltinAttributes.h"
#include "mlir/IR/BuiltinTypes.h"
#include "mlir_tensorrt/IR/MLIRTensorRTOps.h"
#include "mlir_tensorrt/Transforms/Passes.h"

#define GEN_PASS_DEF_LEGALIZEMLIRTENSORRT
#include "mlir_tensorrt/Transforms/Passes.h.inc"

namespace mlir::iree_compiler::IREE::MLIRTensorRT {
namespace {

class LegalizeMLIRTensorRTPass
    : public ::impl::LegalizeMLIRTensorRTBase<LegalizeMLIRTensorRTPass> {
 public:
  void runOnOperation() override {
    auto *context = &getContext();
    // TODO: This is all just a placeholder. To make it real, we should be
    // checking if the import already exists and likely doing some more fancy
    // lowering.
    // Add imports.
    auto m = getOperation();
    auto importBuilder = OpBuilder::atBlockBegin(m.getBody());
    importBuilder
        .create<func::FuncOp>(m.getLoc(), "mlir_tensorrt.print",
                              FunctionType::get(context, {}, {}))
        .setPrivate();

    // Legalize operations.
    m.walk([&](Operation *op) {
      if (auto printOp = dyn_cast<IREE::MLIRTensorRT::PrintOp>(op)) {
        OpBuilder b(op);
        b.create<func::CallOp>(printOp.getLoc(), "mlir_tensorrt.print",
                               TypeRange{});
        printOp.erase();
      }
    });
  }
};

}  // namespace

std::unique_ptr<OperationPass<ModuleOp>> createLegalizeMLIRTensorRTPass() {
  return std::make_unique<LegalizeMLIRTensorRTPass>();
}

}  // namespace mlir::iree_compiler::IREE::MLIRTensorRT

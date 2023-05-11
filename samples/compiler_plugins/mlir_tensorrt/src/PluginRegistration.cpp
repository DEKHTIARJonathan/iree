// Copyright 2023 The IREE Authors
//
// Licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#include "iree/compiler/PluginAPI/Client.h"
#include "mlir/IR/Diagnostics.h"
#include "mlir/IR/Location.h"
#include "mlir/IR/MLIRContext.h"
#include "mlir/Pass/Pass.h"
#include "mlir_tensorrt/IR/MLIRTensorRTDialect.h"

#include "mlir_tensorrt/Transforms/Passes.h"

using namespace mlir;
using namespace mlir::iree_compiler;
namespace {

struct MyOptions {
  void bindOptions(OptionsBinder &binder) {}
};

struct MySession : public PluginSession<MySession, MyOptions> {
  static void registerPasses() { ::detail::registerPasses(); }

  void onRegisterDialects(DialectRegistry &registry) override {
    registry.insert<IREE::MLIRTensorRT::MLIRTensorRTDialect>();
  }

  LogicalResult onActivate() override { return success(); }

  void extendPreprocessingPassPipeline(OpPassManager &pm) override {
    pm.addPass(IREE::MLIRTensorRT::createLegalizeMLIRTensorRTPass());
  }
};

}  // namespace

IREE_DEFINE_COMPILER_OPTION_FLAGS(MyOptions);

extern "C" bool iree_register_compiler_plugin_mlir_tensorrt(
    mlir::iree_compiler::PluginRegistrar *registrar) {
  registrar->registerPlugin<MySession>("mlir_tensorrt");
  return true;
}

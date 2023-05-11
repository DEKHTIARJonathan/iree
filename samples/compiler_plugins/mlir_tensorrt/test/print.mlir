// RUN: iree-opt --iree-plugin=mlir_tensorrt_sample --iree-print-plugin-info --pass-pipeline='builtin.module(iree-mlir-tensorrt-legalize)' %s | FileCheck %s

// CHECK: func.func private @mlir_tensorrt.print()
func.func @main() {
  // CHECK: call @mlir_tensorrt.print
  mlir_tensorrt.print
  func.return
}

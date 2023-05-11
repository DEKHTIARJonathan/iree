add_subdirectory(mlir_tensorrt)

iree_cc_library(
  NAME
    MLIRTensorRTregistration
  HDRS
    "mlir_tensorrt/Transforms/Passes.h"
  SRCS
    "PluginRegistration.cpp"
  DEPS
    ::mlir_tensorrt::IR::MLIRTensorRTIR
    ::mlir_tensorrt::Transforms::LegalizeMLIRTensorRT::MLIRTensorRTLegalize
    # ::mlir_tensorrt::Transforms::MhloDecomposeComplex::MhloDecomposeComplex
    MLIRIR
    MLIRPass
    iree::compiler::PluginAPI
  PUBLIC
)

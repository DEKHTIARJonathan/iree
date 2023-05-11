# This target should contain only passes/transforms that do
# not depend on dialects defined in this project -- they can only
# depend on upstream dialects.

iree_cc_library(
  NAME
    MhloDecomposeComplex
  HDRS
    "../Passes.h"
    "../Passes.h.inc"
  SRCS
    "LegalizeMLIRTensorRT.cpp"
  DEPS
    MLIRFuncDialect
    MLIRIR
    MLIRPass
  PUBLIC
    MLIRTensorRTIR
    MLIRTensorRTPassesIncGen
)

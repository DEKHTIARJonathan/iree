# This target should contain only passes/transforms that do
# not depend on dialects defined in this project -- they can only
# depend on upstream dialects.

iree_cc_library(
  NAME
    MLIRTensorRTLegalize
  HDRS
    "Passes.h"
    "Passes.h.inc"
  SRCS
    "LegalizeMLIRTensorRT.cpp"
  DEPS
    MLIRFuncDialect
    MLIRIR
    MLIRPass
  PUBLIC
    MLIRTensorRTPassesIncGen
    MLIRTensorRTIR
)

iree_tablegen_library(
  NAME
    MLIRTensorRTPassesIncGen
  TD_FILE
    "Passes.td"
  OUTS
    --gen-pass-decls Passes.h.inc
)

iree_tablegen_doc(
  NAME
    MLIRTensorRTPassesIncGenDocGen
  TD_FILE
    "Passes.td"
  OUTS
    --gen-dialect-doc MLIRTensorRTPass.md
)

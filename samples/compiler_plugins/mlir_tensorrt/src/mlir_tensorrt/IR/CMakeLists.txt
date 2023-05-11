

iree_cc_library(
  NAME
    MLIRTensorRTIR
  HDRS
    "MLIRTensorRTDialect.h"
    "MLIRTensorRTOps.h"
  SRCS
    "MLIRTensorRTDialect.cpp"
    "MLIRTensorRTOps.cpp"
    "MLIRTensorRTOps.cpp.inc"
  DEPS
    ::MLIRTensorRTOpsGen
    LLVMSupport
    MLIRFuncDialect
    MLIRIR
    MLIRSupport
  PUBLIC
)

iree_tablegen_library(
  NAME
    MLIRTensorRTOpsGen
  TD_FILE
    "MLIRTensorRTOps.td"
  OUTS
    --gen-dialect-decls MLIRTensorRTDialect.h.inc
    --gen-dialect-defs MLIRTensorRTDialect.cpp.inc
    --gen-op-decls MLIRTensorRTOps.h.inc
    --gen-op-defs MLIRTensorRTOps.cpp.inc
)

iree_tablegen_doc(
  NAME
    MLIRTensorRTDialectDocGen
  TD_FILE
    "MLIRTensorRTOps.td"
  OUTS
    --gen-dialect-doc -dialect=mlir_tensorrt MLIRTensorRTDialect.md
)

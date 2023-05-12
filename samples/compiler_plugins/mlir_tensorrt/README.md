# MLIR-TRT Compiler Plugin Sample

WARNING: This plugin is under construction.

This sample demonstrates a compiler plugin which:

* Adds a new dialect to IREE
* Implements pre-processor lowerings to transform ops to internal
  implementations (TODO)
* Has a python-based runner that implements the IO ops in pure python (TODO)
* Illustrates some advanced features of the way such things can be
  constructed (custom types, async, etc) (TODO)
* Show how to test such a plugin (TODO)

To use this, the plugin must be built into the compiler via:

```
-DIREE_COMPILER_PLUGIN_PATHS=samples/compiler_plugins/mlir-tensorrt
```

It can then be activated in either `iree-opt` or `iree-compile` via the
option `--iree-plugin=mlir_tensorrt`.

To compile a sample:

```
iree-compile \
  --iree-hal-target-backends=cuda \
  --iree-plugin=mlir_tensorrt \
  samples/compiler_plugins/mlir_tensorrt/test/print.mlir \
  -o /tmp/print.vmfb

export PYTHONPATH=${PYTHONPATH}
python3 samples/compiler_plugins/mlir_tensorrt/test/run_mock.py /tmp/print.vmfb
```

Should print:

```
--- Loading /tmp/print.vmfb
--- Running main()
+++ HELLO FROM MLIR_TENSORRT
```

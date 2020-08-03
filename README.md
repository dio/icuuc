## icuuc

This provides [Bazel](https://bazel.build) targets for embedding [icu4c](https://github.com/unicode-org/icu/tree/master/icu4c) statically.

Provided targets:
- `:common` provides common libraries.
- `:data` provides minimal ICU data (by default filtered by (tools/data/filters.json)[tools/data/filters.json], see: (tools/data/README.md)[tools/data/README.md] for generating more ICU data).
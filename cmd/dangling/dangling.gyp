# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.
{
  'includes': [
    '../../coreconf/config.gypi',
  ],
  # Diagnostic shim for sanitizer builds only (see cmd/dangling/dangling.c).
  # It is LD_PRELOADed into every test binary and must therefore be a bare
  # shared object: it is built WITHOUT sanitizer instrumentation (so it carries
  # no __asan_* self-references) and WITHOUT the NSPR libraries config.gypi
  # otherwise adds to every shared_library, so loading it into a non-ASan
  # helper process (a shell, sed, the symbolizer) is a harmless no-op. All ASan
  # entry points are resolved at load with dlsym.
  # Built for the ASan test suites only, not for fuzz builds (also ASan), where
  # the detector is unused and would only bloat the fuzz artifacts.
  'conditions': [
    [ 'sanitizer_flags!=0 and fuzz==0', {
      'targets': [
        {
          'target_name': 'dangling',
          'product_name': 'dangling',
          'type': 'shared_library',
          'sources': [
            'dangling.c',
          ],
          # Strip the sanitizer instrumentation config.gypi adds to every
          # target (it is a global condition, so exclusion is the reliable way
          # to drop it for one target rather than fighting flag order).
          'cflags!': [
            '<@(sanitizer_flags)',
          ],
          'ldflags!': [
            '<@(sanitizer_flags)',
          ],
          'libraries': [
            '-ldl',
          ],
          'libraries!': [
            '-lplds4',
            '-lplc4',
            '-lnspr4',
          ],
        },
        # A deliberately dangling pointer the harness uses to prove the
        # detector is live before trusting a clean run. An ordinary ASan
        # executable; it needs nothing from NSS.
        {
          'target_name': 'dangling_canary',
          'type': 'executable',
          'sources': [
            'dangling_canary.c',
          ],
          'libraries!': [
            '-lplds4',
            '-lplc4',
            '-lnspr4',
          ],
        },
      ],
    }],
  ],
  'variables': {
    'module': 'nss',
  }
}

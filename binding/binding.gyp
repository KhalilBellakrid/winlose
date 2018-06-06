{
  'variables': {
    'run_path%': '../../winlose-build/src',
    'library_path%': '../../../winlose-build/src'
  },
  'targets': [{
    'target_name': 'Winlose_nodejs',
    'sources': [
      '../nodejs/Winlose_nodejs.cpp',
      '../nodejs/NJSWinlose.cpp',
      '../nodejs/NJSWinlose.h',
    ],
    'include_dirs': [
      "<!(node -e \"require('nan')\")",
      '../src',
    ],
    "copies": [
      {
        'files': ['<(module_root_dir)/<(run_path)/$(CONFIG)/winlose<(SHARED_LIB_SUFFIX)'],
        'destination': '<(module_root_dir)/build/Release/',
      },
      {
        'files': ['<(module_root_dir)/<(run_path)/$(CONFIG)/winlose.lib'],
        'destination': '<(module_root_dir)/build/',
      },
    ],
    'conditions': [
      ['OS=="mac"', {
        'libraries': ['-Wl,-rpath,<!(pwd)/<@(run_path)', '-L<@(library_path)', '-lwinlose'],
      }],
      ['OS=="win"', {
        'include_dirs': ['$(UCRT_BASED_PATH)'],
        'libraries': ['winlose'],
      }],
    ]
  }]
}

{
  'variables': {
    'run_path%': '../../winlose-build/src',
    'library_path%': '../../../winlose-build/src'
  },
  'targets': [{
    'target_name': 'winlose',
    'sources': [
      '../nodejs-binding/winlose.cpp',
      '../nodejs-binding/NJSWinloseCpp.cpp',
      '../nodejs-binding/NJSWinloseNodeJS.cpp',
    ],
    'include_dirs': [
      "<!(node -e \"require('nan')\")",
      '../src/api',
    ],
    'conditions': [
      ['OS=="mac"', {
        'libraries': ['-Wl,-rpath,<!(pwd)/<@(run_path)', '-L<@(library_path)', '-lwinlose'],
      }],
      ['OS=="win"', {
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
        'include_dirs': ['$(UCRT_BASED_PATH)'],
        'libraries': ['winlose'],
      }],
    ]
  }]
}

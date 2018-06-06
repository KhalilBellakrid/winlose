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
			"../src",
		],
		"copies": [
	        {
	          'destination': '<(module_root_dir)/build/Release/',
	          'files': ['<(module_root_dir)/<(run_path)/Debug/winlose<(SHARED_LIB_SUFFIX)']
	        },
	        {
	          'destination': '<(module_root_dir)/build/Release/',
	          'files': ['<(module_root_dir)/<(run_path)/Debug/winlose.lib']
	        },
	        {
	          'destination': '<(module_root_dir)/build/',
	          'files': ['<(module_root_dir)/<(run_path)/Debug/winlose<(SHARED_LIB_SUFFIX)']
	        },
	        {
	          'destination': '<(module_root_dir)/build/',
	          'files': ['<(module_root_dir)/<(run_path)/Debug/winlose.lib']
	        },
	        {
	          'destination': '<(module_root_dir)/build/',
	          'files': ['<(module_root_dir)/ucrtbased.dll']
	        },
      	],
		'conditions': [
			['OS=="mac"', {
				'libraries': ['-Wl,-rpath,<!(pwd)/<@(run_path)', '-L<@(library_path)', '-lwinlose'],
			}],
			['OS=="win"', {
				'libraries': ['winlose'],
			}],
		]

	}]
}
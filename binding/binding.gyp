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
		'conditions': [
			['OS=="mac"', {
				'libraries': ['-Wl,-rpath,<!(pwd)/<@(run_path)', '-L<@(library_path)', '-lwinlose'],
			}],
			['OS=="win"', {
				'libraries': ['../../../winlose-build/src/Debug/winlose.lib'],
			}],
		]

	}]
}
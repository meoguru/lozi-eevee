{
  'targets': [
    {
      'target_name': 'eevee',
      'type': 'static_library',
      'dependencies': [
        'deps/asio.gyp:asio',
        'deps/json11.gyp:json11',
      ],
      'sources': [
        'src/eevee.cpp',
      ],
      'include_dirs': [
        'include',
      ],
      'all_dependent_settings': {
        'include_dirs': [
          'include',
        ],
      },
    },
    {
      'target_name': 'test',
      'type': 'executable',
      'dependencies': [
        'deps/gtest.gyp:gtest',
        'eevee',
      ],
      'sources': [
        'test/eevee.cpp',
        'test/json11.cpp',
      ],
    },
  ],
}

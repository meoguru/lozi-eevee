{
  'targets': [
    {
      'target_name': 'eevee',
      'type': 'executable',
      'xcode_settings': {
        'OTHER_CFLAGS': [
          '-std=c++11',
          '-stdlib=libc++',
        ],
      },
      'dependencies': [
        'deps/json11.gyp:json11',
      ],
      'sources': [
        'src/main.cpp',
      ],
    },
  ],
}

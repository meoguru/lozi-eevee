{
  'targets': [
    {
      'target_name': 'eevee',
      'type': 'executable',
      'dependencies': [
        'deps/asio.gyp:asio',
        'deps/json11.gyp:json11',
      ],
      'sources': [
        'src/main.cpp',
      ],
    },
    {
      'target_name': 'test',
      'type': 'executable',
      'dependencies': [
        'deps/gtest.gyp:gtest',
        'deps/json11.gyp:json11',
      ],
      'sources': [
        'test/json11.cpp',
      ],
    },
  ],
}

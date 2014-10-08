{
  'targets': [
    {
      'target_name': 'asio',
      'type': 'static_library',
      'xcode_settings': {
        'OTHER_CFLAGS': [
          '-std=c++11',
          '-stdlib=libc++',
          '-Wno-deprecated',
        ],
      },
      'defines': [
        'ASIO_STANDALONE',
        'ASIO_SEPARATE_COMPILATION',
      ],
      'sources': [
        'asio/asio/src/asio.cpp',
        'asio/asio/src/asio_ssl.cpp',
      ],
      'include_dirs': [
        'asio/asio/include',
      ],
      'all_dependent_settings': {
        'defines': [
          'ASIO_STANDALONE',
        ],
        'include_dirs': [
          'asio/asio/include',
        ],
      },
    },
  ],
}

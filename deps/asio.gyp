{
  'targets': [
    {
      'target_name': 'asio',
      'type': 'static_library',
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
      'direct_dependent_settings': {
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

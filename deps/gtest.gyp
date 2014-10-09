{
  'targets': [
    {
      'target_name': 'gtest',
      'type': 'static_library',
      'sources': [
        'gtest/src/gtest-all.cc',
        'gtest/src/gtest_main.cc',
      ],
      'include_dirs': [
        'gtest',
        'gtest/include',
      ],
      'all_dependent_settings': {
        'include_dirs': [
          'gtest/include',
        ],
      },
    },
  ],
}

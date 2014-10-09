{
  'targets': [
    {
      'target_name': 'json11',
      'type': 'static_library',
      'sources': [
        'json11/json11.cpp'
      ],
      'include_dirs': [
        'json11',
      ],
      'all_dependent_settings': {
        'include_dirs': [
          '.',
        ],
      },
    },
  ],
}

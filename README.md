[![Windows](https://github.com/FrancoisSestier/matrix_layer_stack/actions/workflows/windows.yml/badge.svg)](https://github.com/FrancoisSestier/matrix_layer_stack/actions/workflows/windows.yml) [![Ubuntu](https://github.com/FrancoisSestier/matrix_layer_stack/actions/workflows/ubuntu.yml/badge.svg)](https://github.com/FrancoisSestier/matrix_layer_stack/actions/workflows/ubuntu.yml) [![codecov](https://codecov.io/gh/FrancoisSestier/matrix_layer_stack/branch/master/graph/badge.svg?token=ZPDP1TAO3Z)](https://codecov.io/gh/FrancoisSestier/matrix_layer_stack) [![License: Unlicense](https://img.shields.io/badge/license-Unlicense-blue.svg)](http://unlicense.org/)

Open Source Archetype and Chunk Based Lightweight Entity Component System with straighforward api design

### Matrix Layer Stack
easy to use stack of matrices 

## Usage Design 

```c++
    using elevation = s_int16_t<struct elevation_tag>;
    using tile_id = s_int16_t<struct tile_id_tag>;

    using chunk = matrix_tuple<256, 256, elevation, tile_id>;

    chunk ck;

    {
        auto [elevation_, tile_id_] = ck.get<elevation, tile_id>(10, 30);

        ASSERT_EQ(elevation_, 0);
        ASSERT_EQ(tile_id_, 0);

        elevation_ = 50;
        tile_id_ = 10;
    }

    auto [elevation_, tile_id_] = ck.get<elevation, tile_id>(10, 30);
    ASSERT_EQ(elevation_, 50);
    ASSERT_EQ(tile_id_, 10);
```
 

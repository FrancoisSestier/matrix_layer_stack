#include <gtest/gtest.h>

#include <mls/matrix_tuple.hpp>
#include <mls/strong_types.hpp>

using namespace mls;
TEST(MATRIX_TUPLE, BASE_TYPES) {

    matrix_tuple<256, 256, int,char> ck;
    {
        auto [i] = ck.get<int>(2, 3);

        ASSERT_EQ(i, 0);

        i++;
    }
    auto [i,c] = ck.get<int,char>(2, 3);
    ASSERT_EQ(i, 1);

}

TEST(MATRIX_TUPLE, STRONG_TYPES) {
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

};
